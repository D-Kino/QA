#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "..\header\date.h"

struct tm * getNowDateTime() {
    time_t timer;        /* ���������o�����߂̌^�i���ۂ�unsigned long�^�j */
    struct tm *local;    /* tm�\���́i�����������j ��`��time.h�ɋL�q����Ă��� */

    timer = time(NULL);        /* ���ݎ������擾 */
    local = localtime(&timer);    /* �n�����ɕϊ� */

    /* �N�����Ǝ����b��tm�\���̂̊e�p�����^����ϐ��ɑ�� */
    local->tm_year = local->tm_year + 1900;        /* 1900�N����̔N�����擾����邽�� */
    local->tm_mon = local->tm_mon + 1;        /* 0��1���Ƃ��Ă��邽�� */

    return local;
}
