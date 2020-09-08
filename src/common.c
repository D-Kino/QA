#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <string.h>

/**
 * ������̍����̋󔒂���������B
 * @param string: ������
 * @return �g�������ꂽ������
 */
char *ltrim (const char *string) {
    char* tmp = (char*) string;
    for (; *tmp == 0x20 && *tmp != 0x00; tmp++);
    return tmp;
}

/**
 * ������̉E���̋󔒂���������B
 * @param string: ������
 * @return �g�������ꂽ������
 */
char *rtrim (const char *string) {
    char* tmp = (char*) string;
    // ������̑傫�� - �k���o�C�g�̈ʒu
    int s = (strlen(tmp) - 1);
    for (; s > 0 && tmp[s] == 0x20; s--);
    tmp[s + 1] = 0x00;
    return tmp;
}

/**
 * ������̗��[�̋󔒂���������B
 * @param string: ������
 * @return �g�������ꂽ������
 */
char *trim (const char *string) {
    // ltrim �� rtrim�֐����g�p�B
    return ltrim(rtrim(string));
}

/**
 * SHIFT_JIS�̕��������J�E���g����
 * @param string
 * @return ������
 */
int sjlen(const char *string)
{
    int count = 0;  // �������̃J�E���g�p
    int skip = 0;  // skip=1�̏ꍇ�͕����J�E���g���X�L�b�v����
    while (*string != '\0') {
        if (skip) {  // 2�o�C�g������2�o�C�g�ڂ̏ꍇ�̓J�E���g���Ȃ�
            skip = 0;
        } else {
            if ((*string & 0xE0) == 0x80 || (*string & 0xE0) == 0xE0) { skip = 1; } // 2�o�C�g�����ɊY������ꍇ
            count++;
        }
        string++;
    }
    return count;
}

/**
 * PowerShell�R�}���h�����s����B
 * @param cmd �R�}���h
 * @return ����0�A�ُ�1
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
 * QA�V�X�e���̃C�x���g��o�^����B
 * @return ����0�A�ُ�1
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
 * ���[�U���͂̕�������擾����
 * @params s:�i�[�敶���z��, n:�T�C�Y
 * @return �����z��
 */
char *getsn(char *s, int n) {
   /* �W�����͂���1�����ǂݍ��� */
   if (fgets(s, n, stdin) == NULL) return NULL;
   /* ���s�������������� */
   char *ln = strchr(s, '\n');
   if (ln) {
	   /* ���s�������I�[�����ɒu�� */
	   *ln = '\0';
   } else {
	   /* ���̓X�g���[����ɕ������c���Ă�ꍇ */
	   /* ���s�������ǂݎ����܂ŋ�ǂ݂��� */
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
 * �󕶎����̔�����s��
 * @return �󕶎�1�A�󕶎��ł͂Ȃ�0
 */
int isEmpty(char *p) {
    return *p == '\0';
}

