#include <stdio.h>
#include <ctype.h>
#include "..\header\common.h"

/**
 * �������`�F�b�N���s���B
 * @param string: �`�F�b�N�Ώە�����Amin_length: �ŏ��������Amax_length: �ő啶����
 * @return ����0�A�����������Ȃ�1�A������������2
 */
int validLength (char *string, int min_length, int max_length) {
	int str_cnt = 0;
	str_cnt = sjlen(string);

	if (str_cnt < min_length) {
		/* �������s�� */
		return 1;
	}

	if (str_cnt > max_length) {
		/* �������ߑ� */
		return 2;
	}

	return 0;
}

/**
 * �����񂪐��l���`�F�b�N���s���B
 * @param string: �`�F�b�N�Ώە�����
 * @return ���l0�A���l�ȊO1
 */
int validInt (char *string) {
    int i;

    for (i=0; i<strlen(string); i++) {
        if (!isdigit(string[i])) {
        	/* �����ȊO */
            return 1;
        }
    }

    return 0;
}


/**
 * ������̑召�`�F�b�N���s���B
 * @param num: �`�F�b�N�Ώې��l
 * @return ����0�A���l��������1�A���l���傫��2
 */
int validSize (int num, int min_num, int max_num) {
	if (num < min_num) {
		/* ���l�������� */
		return 1;
	}

	if (num > max_num) {
		/* ���l���傫�� */
		return 2;
	}

    return 0;
}
