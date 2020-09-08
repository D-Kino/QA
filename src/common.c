#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <string.h>

/**
 * 文字列の左側の空白を除去する。
 * @param string: 文字列
 * @return トリムされた文字列
 */
char *ltrim (const char *string) {
    char* tmp = (char*) string;
    for (; *tmp == 0x20 && *tmp != 0x00; tmp++);
    return tmp;
}

/**
 * 文字列の右側の空白を除去する。
 * @param string: 文字列
 * @return トリムされた文字列
 */
char *rtrim (const char *string) {
    char* tmp = (char*) string;
    // 文字列の大きさ - ヌルバイトの位置
    int s = (strlen(tmp) - 1);
    for (; s > 0 && tmp[s] == 0x20; s--);
    tmp[s + 1] = 0x00;
    return tmp;
}

/**
 * 文字列の両端の空白を除去する。
 * @param string: 文字列
 * @return トリムされた文字列
 */
char *trim (const char *string) {
    // ltrim と rtrim関数を使用。
    return ltrim(rtrim(string));
}

/**
 * SHIFT_JISの文字数をカウントする
 * @param string
 * @return 文字数
 */
int sjlen(const char *string)
{
    int count = 0;  // 文字数のカウント用
    int skip = 0;  // skip=1の場合は文字カウントをスキップする
    while (*string != '\0') {
        if (skip) {  // 2バイト文字の2バイト目の場合はカウントしない
            skip = 0;
        } else {
            if ((*string & 0xE0) == 0x80 || (*string & 0xE0) == 0xE0) { skip = 1; } // 2バイト文字に該当する場合
            count++;
        }
        string++;
    }
    return count;
}

/**
 * PowerShellコマンドを実行する。
 * @param cmd コマンド
 * @return 正常0、異常1
 */
int executePowerShell (char *cmd) {
	int result_no;
	char powershell_cmd[256];
	sprintf(powershell_cmd, "powershell -Command \"%s\"", cmd);
	if (system(powershell_cmd) != 0) {
		result_no = 1;
	} else {
		result_no = 0;
	}
	return result_no;
}

/**
 * QAシステムのイベントを登録する。
 * @return 正常0、異常1
 */
int registerEvent (char *event_type, int event_id, char *message) {
	int result_no;
	char register_evenet_cmd[256];
	sprintf(register_evenet_cmd, "Write-EventLog -LogName Application -Source QA_SYSTEM -EntryType %s -EventId %d -Message %s", event_type, event_id, message);
	if (executePowerShell(register_evenet_cmd) != 0) {
		result_no = 1;
	} else {
		result_no = 0;
	}
	return result_no;
}

/**
 * ユーザ入力の文字列を取得する
 * @params s:格納先文字配列, n:サイズ
 * @return 文字配列
 */
char *getsn(char *s, int n) {
   /* 標準入力から1文字読み込む */
   if (fgets(s, n, stdin) == NULL) return NULL;
   /* 改行文字を検索する */
   char *ln = strchr(s, '\n');
   if (ln) {
	   /* 改行文字を終端文字に置換 */
	   *ln = '\0';
   } else {
	   /* 入力ストリーム上に文字が残ってる場合 */
	   /* 改行文字が読み取られるまで空読みする */
	   while (1) {
		   int c = getchar();
		   if (c == '\n' || c == EOF) {
			   break;
		   }
	   }
   }
   return s;
}

/**
 * 空文字化の判定を行う
 * @return 空文字1、空文字ではない0
 */
int isEmpty(char *p) {
    return *p == '\0';
}

