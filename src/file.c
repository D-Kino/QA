#include <stdio.h>
#include <sys/stat.h>
#include "..\header\common.h"

const char HOST[] = "172.16.1.12:22";
const char USER[] = "qa_user";
const char PASS_WORD[] = "test";
const char PRIVATE_KEY[] ="C:\\Users\\trend\\kinoshita\\.vagrant\\machines\\default\\virtualbox\\private_key.ppk";

/**
 * ファイルの削除をする。
 * @param path: ファイルパス
 * @return 削除成功0、削除が失敗したら0以外
 */
int deleteFile(const char *path) {
	return remove(path);
}

/**
 * ファイルの存在を確認する。
 * @param path: ファイルパス。
 * @return 存在したら 0以外、存在しなければ 0
 */
int existFile(const char *path) {
	FILE* fp = fopen(path, "r");
	if (fp == NULL) {
		return 0;
	}

	fclose(fp);
	return 1;
}

/**
 * WinSCPのコマンドが使用できるかを確認する。
 * ※WinSCPをインストールをし、環境変数のパスを通しておく必要がある。
 * @return 使用可能0、使用できない1
 */
int existWinSCP() {
	int result_no = 0;
	result_no = system("winscp /help > nul 2>&1");
	if (result_no != 0) {
		return 1;
	} else {
		return 0;
	}
}

/**
 * ファイル転送を行う。
 * ※要WinSCP
 * @param source: 送信元パス、destination： 送信先パス
 * @return 転送成功0、転送失敗1
 */
int putFile(const char *source, const char *destination) {
	int result_no = 0;
	char winscp_cmd[256];

	/* WinSCPのコマンドを実行 */
	sprintf(winscp_cmd, "winscp /command \"open scp://%s:%s@%s -privatekey=%s -rawsettings utf=1 EOLType=0 \" \"put \"\"%s\"\" \"\"%s\"\"\" \"exit\" > nul 2>&1", USER, PASS_WORD, HOST, PRIVATE_KEY, source, destination);
	result_no = system(winscp_cmd);
	if (result_no != 0) {
		/* 転送失敗*/
		return 1;
	}

	return 0;
}

/**
 * iconvのコマンドが使用できるかを確認する。
 * @return 使用可能0、使用できない1
 */
int existIconv() {
	int result_no = 0;
	result_no = system("iconv --help > nul 2>&1");
	if (result_no != 0) {
		return 1;
	} else {
		return 0;
	}
}

/**
 * ファイルの文字コードを変換する。
 * 出力先は変換対象ファイル直下の「変更後の文字コード」ディレクトリの中に同一ファイル目で出力される。
 * @param file_path: 変換対象ファイルのパス、form_code: 変換前の文字コード、to_code: 変換後の文字コード
 */
int iconvFile(const char *file_path, const char *convert_file_path, const char *from_code, const char *to_code) {
	int result_no = 0;
	int split_cnt = 0;
	int deep_N = 12;
	char tmp_file_path[256];
	char convert_file_ary[deep_N][256];
	char *ptr;
	char cmd[256];
	struct stat st;

    /* 1回目 */
	strcpy(tmp_file_path, file_path);
    ptr = strtok(tmp_file_path, "\\");
   	strcpy(convert_file_ary[split_cnt], ptr);
    split_cnt++;

    /* 2回目以降 */
    while(ptr != NULL) {
        /* strtok関数により変更されたNULLのポインタが先頭 */
        ptr = strtok(NULL, "\\");
        /* ptrがNULLの場合エラーが発生するので対処 */
        if(ptr != NULL) {
           	strcpy(convert_file_ary[split_cnt], ptr);
            split_cnt++;
        }
        /* 階層が深すぎるためエラーとする */
        if (deep_N < split_cnt) {
        	return 1;
        }
    }

    /* 変換後のファイルパスの生成 */
    for (int i=0; i < split_cnt; i++) {
    	if (i == 0) {
    		strcpy(convert_file_path, convert_file_ary[i]);
    		strcat(convert_file_path, "\\");
    	} else {
    		if (i == (split_cnt - 1)) {
    			/* 変換後文字コードをファイルパスに含める */
    			sprintf(convert_file_path, "%s\\%s", convert_file_path, to_code);
    			/* フォルダが存在しない場合は作成をする */
    			if(stat(convert_file_path, &st) != 0){
    				sprintf(cmd, "mkdir %s", convert_file_path);
    				system(cmd);
    			}
    		}
    		sprintf(convert_file_path, "%s\\%s", convert_file_path, convert_file_ary[i]);
    	}
    }

    /* 文字コード変換 */
	sprintf(cmd, "iconv -f \"%s\" -t \"%s\" \"%s\" > \"%s\" 2> nul", from_code, to_code, file_path, convert_file_path);
	result_no = system(cmd);
	if (result_no != 0) {
		/* 変換失敗 */
		return 1;
	}

	/* 文字コードを変更したファイルを送信するので上書 */
	strcpy(file_path, convert_file_path);

	return 0;
}

