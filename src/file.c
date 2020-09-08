#include <stdio.h>
#include <sys/stat.h>
#include "..\header\common.h"

const char HOST[] = "172.16.1.12:22";
const char USER[] = "qa_user";
const char PASS_WORD[] = "test";
const char PRIVATE_KEY[] ="C:\\Users\\trend\\kinoshita\\.vagrant\\machines\\default\\virtualbox\\private_key.ppk";

/**
 * �t�@�C���̍폜������B
 * @param path: �t�@�C���p�X
 * @return �폜����0�A�폜�����s������0�ȊO
 */
int deleteFile(const char *path) {
	return remove(path);
}

/**
 * �t�@�C���̑��݂��m�F����B
 * @param path: �t�@�C���p�X�B
 * @return ���݂����� 0�ȊO�A���݂��Ȃ���� 0
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
 * WinSCP�̃R�}���h���g�p�ł��邩���m�F����B
 * ��WinSCP���C���X�g�[�������A���ϐ��̃p�X��ʂ��Ă����K�v������B
 * @return �g�p�\0�A�g�p�ł��Ȃ�1
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
 * �t�@�C���]�����s���B
 * ���vWinSCP
 * @param source: ���M���p�X�Adestination�F ���M��p�X
 * @return �]������0�A�]�����s1
 */
int putFile(const char *source, const char *destination) {
	int result_no = 0;
	char winscp_cmd[256];

	/* WinSCP�̃R�}���h�����s */
	sprintf(winscp_cmd, "winscp /command \"open scp://%s:%s@%s -privatekey=%s -rawsettings utf=1 EOLType=0 \" \"put \"\"%s\"\" \"\"%s\"\"\" \"exit\" > nul 2>&1", USER, PASS_WORD, HOST, PRIVATE_KEY, source, destination);
	result_no = system(winscp_cmd);
	if (result_no != 0) {
		/* �]�����s*/
		return 1;
	}

	return 0;
}

/**
 * iconv�̃R�}���h���g�p�ł��邩���m�F����B
 * @return �g�p�\0�A�g�p�ł��Ȃ�1
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
 * �t�@�C���̕����R�[�h��ϊ�����B
 * �o�͐�͕ϊ��Ώۃt�@�C�������́u�ύX��̕����R�[�h�v�f�B���N�g���̒��ɓ���t�@�C���ڂŏo�͂����B
 * @param file_path: �ϊ��Ώۃt�@�C���̃p�X�Aform_code: �ϊ��O�̕����R�[�h�Ato_code: �ϊ���̕����R�[�h
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

    /* 1��� */
	strcpy(tmp_file_path, file_path);
    ptr = strtok(tmp_file_path, "\\");
   	strcpy(convert_file_ary[split_cnt], ptr);
    split_cnt++;

    /* 2��ڈȍ~ */
    while(ptr != NULL) {
        /* strtok�֐��ɂ��ύX���ꂽNULL�̃|�C���^���擪 */
        ptr = strtok(NULL, "\\");
        /* ptr��NULL�̏ꍇ�G���[����������̂őΏ� */
        if(ptr != NULL) {
           	strcpy(convert_file_ary[split_cnt], ptr);
            split_cnt++;
        }
        /* �K�w���[�����邽�߃G���[�Ƃ��� */
        if (deep_N < split_cnt) {
        	return 1;
        }
    }

    /* �ϊ���̃t�@�C���p�X�̐��� */
    for (int i=0; i < split_cnt; i++) {
    	if (i == 0) {
    		strcpy(convert_file_path, convert_file_ary[i]);
    		strcat(convert_file_path, "\\");
    	} else {
    		if (i == (split_cnt - 1)) {
    			/* �ϊ��㕶���R�[�h���t�@�C���p�X�Ɋ܂߂� */
    			sprintf(convert_file_path, "%s\\%s", convert_file_path, to_code);
    			/* �t�H���_�����݂��Ȃ��ꍇ�͍쐬������ */
    			if(stat(convert_file_path, &st) != 0){
    				sprintf(cmd, "mkdir %s", convert_file_path);
    				system(cmd);
    			}
    		}
    		sprintf(convert_file_path, "%s\\%s", convert_file_path, convert_file_ary[i]);
    	}
    }

    /* �����R�[�h�ϊ� */
	sprintf(cmd, "iconv -f \"%s\" -t \"%s\" \"%s\" > \"%s\" 2> nul", from_code, to_code, file_path, convert_file_path);
	result_no = system(cmd);
	if (result_no != 0) {
		/* �ϊ����s */
		return 1;
	}

	/* �����R�[�h��ύX�����t�@�C���𑗐M����̂ŏ㏑ */
	strcpy(file_path, convert_file_path);

	return 0;
}

