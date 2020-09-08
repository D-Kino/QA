#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "..\header\date.h"

struct tm * getNowDateTime() {
    time_t timer;        /* 時刻を取り出すための型（実際はunsigned long型） */
    struct tm *local;    /* tm構造体（時刻を扱う） 定義はtime.hに記述されている */

    timer = time(NULL);        /* 現在時刻を取得 */
    local = localtime(&timer);    /* 地方時に変換 */

    /* 年月日と時分秒をtm構造体の各パラメタから変数に代入 */
    local->tm_year = local->tm_year + 1900;        /* 1900年からの年数が取得されるため */
    local->tm_mon = local->tm_mon + 1;        /* 0を1月としているため */

    return local;
}
