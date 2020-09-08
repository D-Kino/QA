#include <stdio.h>
#include <ctype.h>
#include "..\header\common.h"

/**
 * 文字数チェックを行う。
 * @param string: チェック対象文字列、min_length: 最小文字数、max_length: 最大文字数
 * @return 正常0、文字数が少ない1、文字数が多い2
 */
int validLength (char *string, int min_length, int max_length) {
	int str_cnt = 0;
	str_cnt = sjlen(string);

	if (str_cnt < min_length) {
		/* 文字数不足 */
		return 1;
	}

	if (str_cnt > max_length) {
		/* 文字数過多 */
		return 2;
	}

	return 0;
}

/**
 * 文字列が数値かチェックを行う。
 * @param string: チェック対象文字列
 * @return 数値0、数値以外1
 */
int validInt (char *string) {
    int i;

    for (i=0; i<strlen(string); i++) {
        if (!isdigit(string[i])) {
        	/* 数字以外 */
            return 1;
        }
    }

    return 0;
}


/**
 * 文字列の大小チェックを行う。
 * @param num: チェック対象数値
 * @return 正常0、数値が小さい1、数値が大きい2
 */
int validSize (int num, int min_num, int max_num) {
	if (num < min_num) {
		/* 数値が小さい */
		return 1;
	}

	if (num > max_num) {
		/* 数値が大きい */
		return 2;
	}

    return 0;
}
