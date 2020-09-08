
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned int magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[6];
};
static const struct sqlcxp sqlfpn =
{
    5,
    "qa.pc"
};


static unsigned int sqlctx = 2227;


static struct sqlexd {
   unsigned int   sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
      const short *cud;
   unsigned char  *sqlest;
      const char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
            void  **sqphsv;
   unsigned int   *sqphsl;
            int   *sqphss;
            void  **sqpind;
            int   *sqpins;
   unsigned int   *sqparm;
   unsigned int   **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
   unsigned int   sqlcmax;
   unsigned int   sqlcmin;
   unsigned int   sqlcincr;
   unsigned int   sqlctimeout;
   unsigned int   sqlcnowait;
              int   sqfoff;
   unsigned int   sqcmod;
   unsigned int   sqfmod;
            void  *sqhstv[7];
   unsigned int   sqhstl[7];
            int   sqhsts[7];
            void  *sqindv[7];
            int   sqinds[7];
   unsigned int   sqharm[7];
   unsigned int   *sqharc[7];
   unsigned short  sqadto[7];
   unsigned short  sqtdso[7];
} sqlstm = {12,7};

/* SQLLIB Prototypes */
extern void sqlcxt (void **, unsigned int *,
                    struct sqlexd *, const struct sqlcxp *);
extern void sqlcx2t(void **, unsigned int *,
                    struct sqlexd *, const struct sqlcxp *);
extern void sqlbuft(void **, char *);
extern void sqlgs2t(void **, char *);
extern void sqlorat(void **, unsigned int *, void *);

/* Forms Interface */
static const int IAPSUCC = 0;
static const int IAPFAIL = 1403;
static const int IAPFTL  = 535;
extern void sqliem(unsigned char *, signed int *);

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{12,4130,838,0,0,
5,0,0,0,0,0,27,132,0,0,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,10,0,0,
36,0,0,2,0,0,17,136,0,0,1,1,0,1,0,1,97,0,0,
55,0,0,2,0,0,45,138,0,0,0,0,0,1,0,
70,0,0,2,0,0,13,139,0,0,1,0,0,1,0,2,3,0,0,
89,0,0,2,0,0,15,140,0,0,0,0,0,1,0,
104,0,0,3,0,0,17,151,0,0,1,1,0,1,0,1,97,0,0,
123,0,0,3,0,0,45,155,0,0,0,0,0,1,0,
138,0,0,3,0,0,13,157,0,0,7,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,2,3,0,0,
181,0,0,3,0,0,15,159,0,0,0,0,0,1,0,
196,0,0,4,92,0,5,278,0,0,1,1,0,1,0,1,3,0,0,
215,0,0,5,60,0,5,285,0,0,1,1,0,1,0,1,3,0,0,
234,0,0,6,0,0,29,343,0,0,0,0,0,1,0,
249,0,0,7,0,0,31,399,0,0,0,0,0,1,0,
};


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include "..\header\common.h"
#include "..\header\date.h"
#include "..\header\file.h"
#include "..\header\validation.h"

/* 定数の定義 */
const char USER_NAME[] = "QA";
const char PASSWORD[] = "qsATXjfZ";
const char CONNECT_STRING[] = "192.168.1.2/orcl";
const char OUTPUT_PATH[] = ".\\data\\";
const char SEPARATE_MSG[] = "----------------------------------------------------------------------------------------------\n";
const char DESTINATION_DIR[] = "/qa_system/data/";

/* 変数の定義 */
char output_file_path[256] = "";
FILE* fp;

/* メッセージの定義 */
const char INPUT_NAME_MSG[] = "名前を入力してください。\n";
const char RESULT_MSG[] = "【結果】\n";

/* 警告定数の定義 */
char WARNING_MSG_LIST[256][128];

/* エラー定数の定義 */
char ERROR_MSG_LIST[256][128];

/* 関数の宣言 */
void setMsg();
void procWarning(int);
void procError(int);


/* ホスト変数の宣言 */
/* EXEC SQL BEGIN DECLARE SECTION; */ 

    /* varchar username[20]; */ 
struct { unsigned short len; unsigned char arr[20]; } username;

    /* varchar password[20]; */ 
struct { unsigned short len; unsigned char arr[20]; } password;

    /* varchar connect_string[56]; */ 
struct { unsigned short len; unsigned char arr[56]; } connect_string;

    int category_count[256];
    int h_id[256];
    char h_category[256][64];
    char h_question[256][256];
    char h_choice[256][256];
    char h_answer[256][2];
    int h_q_total[256];
    int h_correct_total[256];
    char subquery[256];
    char query[256];
    char category_query[256];
/* EXEC SQL END DECLARE SECTION; */ 


/* EXEC SQL INCLUDE sqlca;
 */ 
/*
 * $Header: sqlca.h 24-apr-2003.12:50:58 mkandarp Exp $ sqlca.h 
 */

/* Copyright (c) 1985, 2003, Oracle Corporation.  All rights reserved.  */
 
/*
NAME
  SQLCA : SQL Communications Area.
FUNCTION
  Contains no code. Oracle fills in the SQLCA with status info
  during the execution of a SQL stmt.
NOTES
  **************************************************************
  ***                                                        ***
  *** This file is SOSD.  Porters must change the data types ***
  *** appropriately on their platform.  See notes/pcport.doc ***
  *** for more information.                                  ***
  ***                                                        ***
  **************************************************************

  If the symbol SQLCA_STORAGE_CLASS is defined, then the SQLCA
  will be defined to have this storage class. For example:
 
    #define SQLCA_STORAGE_CLASS extern
 
  will define the SQLCA as an extern.
 
  If the symbol SQLCA_INIT is defined, then the SQLCA will be
  statically initialized. Although this is not necessary in order
  to use the SQLCA, it is a good pgming practice not to have
  unitialized variables. However, some C compilers/OS's don't
  allow automatic variables to be init'd in this manner. Therefore,
  if you are INCLUDE'ing the SQLCA in a place where it would be
  an automatic AND your C compiler/OS doesn't allow this style
  of initialization, then SQLCA_INIT should be left undefined --
  all others can define SQLCA_INIT if they wish.

  If the symbol SQLCA_NONE is defined, then the SQLCA variable will
  not be defined at all.  The symbol SQLCA_NONE should not be defined
  in source modules that have embedded SQL.  However, source modules
  that have no embedded SQL, but need to manipulate a sqlca struct
  passed in as a parameter, can set the SQLCA_NONE symbol to avoid
  creation of an extraneous sqlca variable.
 
MODIFIED
    lvbcheng   07/31/98 -  long to int
    jbasu      12/12/94 -  Bug 217878: note this is an SOSD file
    losborne   08/11/92 -  No sqlca var if SQLCA_NONE macro set 
  Clare      12/06/84 - Ch SQLCA to not be an extern.
  Clare      10/21/85 - Add initialization.
  Bradbury   01/05/86 - Only initialize when SQLCA_INIT set
  Clare      06/12/86 - Add SQLCA_STORAGE_CLASS option.
*/
 
#ifndef SQLCA
#define SQLCA 1
 
struct   sqlca
         {
         /* ub1 */ char    sqlcaid[8];
         /* b4  */ int     sqlabc;
         /* b4  */ int     sqlcode;
         struct
           {
           /* ub2 */ unsigned short sqlerrml;
           /* ub1 */ char           sqlerrmc[70];
           } sqlerrm;
         /* ub1 */ char    sqlerrp[8];
         /* b4  */ int     sqlerrd[6];
         /* ub1 */ char    sqlwarn[8];
         /* ub1 */ char    sqlext[8];
         };

#ifndef SQLCA_NONE 
#ifdef   SQLCA_STORAGE_CLASS
SQLCA_STORAGE_CLASS struct sqlca sqlca
#else
         struct sqlca sqlca
#endif
 
#ifdef  SQLCA_INIT
         = {
         {'S', 'Q', 'L', 'C', 'A', ' ', ' ', ' '},
         sizeof(struct sqlca),
         0,
         { 0, {0}},
         {'N', 'O', 'T', ' ', 'S', 'E', 'T', ' '},
         {0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0}
         }
#endif
         ;
#endif
 
#endif
 
/* end SQLCA */


int main(argc, argv)
int argc;
char *argv[];
{
    int i = 0;
    int question_num = 0;	// 問題数
    int correct_answers_cnt = 0;	// 正解数
    char name[64];	// 名前
    char category[64];	// 問題のカテゴリ
    char kaito[3];	// ユーザの回答
    char kaito_msg[5];	// ユーザの回答（出力用）
    char correctness_ary[256][256]; // 正誤結果を格納
    char choice[4][64]; // 問題の選択肢
    char output_file_name[64]; // 出力ファイル名
	char convert_file_path[256];	// 文字コード変換後のファイルパス
    char start_msg[256];	// 問題の開始メッセージ
    char question_msg[256];	// 問題文
    char choice_msg[256];	// 選択メッセージ
    char result_detail_msg[256]; // 結果詳細メッセージ
    char result_kaito_msg[16];	// 回答結果メッセージ
    char destination_file_path[128]; // 送信先ファイルパス
    char question_no_str[16]; // 送信先ファイルパス
    double correct_rate = 0;

    /* メッセージ格納用配列にメッセージを格納 */
    setMsg();

    /* 引数チェック */
    if (argc != 3) {
    	procError(100);
    	return 100;
    }

    /* 入力チェック */
    /* 文字数チェック */
    if (validLength(argv[1], 0, 50)) {
    	procError(101);
    	return 101;
    }
    /* 数値チェック */
    if (validInt(argv[2])) {
    	procError(103);
    	return 103;
    }
    /* int型の範囲を超えたかをチェック */
    if (atoi(argv[2]) < 0) {
		procError(105);
    	return 105;
    }
    /* 数値大小チェック */
    switch (validSize(atoi(argv[2]), 1, 100)) {
    	case 1:
    		procError(104);
        	return 104;
        case 2:
			procError(105);
        	return 105;
    }

    /* 引数を変数に格納 */
    strcpy(category, argv[1]);
    question_num = atoi(argv[2]);

    /* 例外宣言 */
    /* EXEC SQL WHENEVER SQLERROR GOTO errorpt; */ 


    /* Oracle接続 */
    strcpy(username.arr, USER_NAME);
    username.len=strlen(username.arr);
    strcpy(password.arr, PASSWORD);
    password.len=strlen(password.arr);
    strcpy(connect_string.arr, CONNECT_STRING);
    connect_string.len=strlen(connect_string.arr);
    /* EXEC SQL CONNECT :username IDENTIFIED BY :password USING :connect_string; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )10;
    sqlstm.offset = (unsigned int  )5;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)&username;
    sqlstm.sqhstl[0] = (unsigned int  )22;
    sqlstm.sqhsts[0] = (         int  )22;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)&password;
    sqlstm.sqhstl[1] = (unsigned int  )22;
    sqlstm.sqhsts[1] = (         int  )22;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)&connect_string;
    sqlstm.sqhstl[2] = (unsigned int  )58;
    sqlstm.sqhsts[2] = (         int  )58;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlstm.sqlcmax = (unsigned int )100;
    sqlstm.sqlcmin = (unsigned int )2;
    sqlstm.sqlcincr = (unsigned int )1;
    sqlstm.sqlctimeout = (unsigned int )0;
    sqlstm.sqlcnowait = (unsigned int )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) goto errorpt;
}



    /* カテゴリ存在チェック */
    sprintf(category_query, "SELECT COUNT(*) FROM question_answer WHERE category = '%s' AND ROWNUM <= %d", category);
    /* EXEC SQL PREPARE COUNT_CATEGORY_SQL1 FROM :category_query; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )36;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)category_query;
    sqlstm.sqhstl[0] = (unsigned int  )256;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) goto errorpt;
}


    /* EXEC SQL DECLARE COUNT_CATEGORY_CUR1 CURSOR FOR COUNT_CATEGORY_SQL1; */ 

    /* EXEC SQL OPEN COUNT_CATEGORY_CUR1; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )55;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) goto errorpt;
}


    /* EXEC SQL FETCH COUNT_CATEGORY_CUR1 INTO category_count; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )256;
    sqlstm.offset = (unsigned int  )70;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (           int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (         void  *)category_count;
    sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )sizeof(int);
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqharc[0] = (unsigned int   *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) goto errorpt;
}


    /* EXEC SQL CLOSE COUNT_CATEGORY_CUR1; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )89;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) goto errorpt;
}


    if (category_count[0] < 1) {
    	procError(102);
    	return 102;
    }

    /* クエリ */
    strcpy(subquery, "SELECT DBMS_RANDOM.RANDOM() AS rand, question_answer.* FROM question_answer ORDER BY rand");
    sprintf(query, "SELECT id, category, question, choice, answer, q_total, correct_total FROM (%s) WHERE category = '%s' AND ROWNUM <= %d", subquery, category, question_num);

    /* 文字列queryを解析してSQL1という名前を指定する */
    /* EXEC SQL PREPARE SQL1 FROM :query; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )104;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)query;
    sqlstm.sqhstl[0] = (unsigned int  )256;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) goto errorpt;
}


    /* CUR1というカーソルをSQL1に関連付けをしている */
    /* EXEC SQL DECLARE CUR1 CURSOR FOR SQL1; */ 

    /* Oracleカーソルを割り当て、入力ホスト変数にバインドし、問合せを実行します */
    /* EXEC SQL OPEN CUR1; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )123;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) goto errorpt;
}


    /* 選択リスト内の列値をINTO句の対応するホスト変数に割り当てた後、カーソルを次の行に進める  */
    /* EXEC SQL FETCH CUR1 INTO h_id, h_category, h_question, h_choice,h_answer, h_q_total,h_correct_total; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 7;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )256;
    sqlstm.offset = (unsigned int  )138;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (           int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (         void  *)h_id;
    sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )sizeof(int);
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqharc[0] = (unsigned int   *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)h_category;
    sqlstm.sqhstl[1] = (unsigned int  )64;
    sqlstm.sqhsts[1] = (         int  )64;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqharc[1] = (unsigned int   *)0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)h_question;
    sqlstm.sqhstl[2] = (unsigned int  )256;
    sqlstm.sqhsts[2] = (         int  )256;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqharc[2] = (unsigned int   *)0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)h_choice;
    sqlstm.sqhstl[3] = (unsigned int  )256;
    sqlstm.sqhsts[3] = (         int  )256;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqharc[3] = (unsigned int   *)0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)h_answer;
    sqlstm.sqhstl[4] = (unsigned int  )2;
    sqlstm.sqhsts[4] = (         int  )2;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqharc[4] = (unsigned int   *)0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)h_q_total;
    sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[5] = (         int  )sizeof(int);
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqharc[5] = (unsigned int   *)0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)h_correct_total;
    sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[6] = (         int  )sizeof(int);
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqharc[6] = (unsigned int   *)0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) goto errorpt;
}


    /* カーソルを使用禁止以降FETCHできない。 */
    /* EXEC SQL CLOSE CUR1; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 7;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )181;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) goto errorpt;
}



    /* 問題数チェック */
    i = question_num - 1;
    if (h_id[i] == 0) {
		procWarning(1);
    	while(i > 0){
    		if (h_id[i] != 0) {
    			question_num = i + 1;
    			break;
    		}
    		i--;
    	}
    }

    /* テスト実行者の名前の入力を受け付ける。 */
    printf(INPUT_NAME_MSG);
    while (1) {
    	if (getsn(name, 64) == NULL) {
    		exit(0);
    	}
        strcpy(name, trim(name));

        /* 名前の文字数チェック */
        if (validLength(name, 0, 30)) {
        	procWarning(5);
        } else {
        	break;
        }
    }

    /* 現在の日時を取得 */
    char datetime[16];
    struct tm *local = getNowDateTime();
    sprintf(datetime, "%4d%02d%02d%02d%02d%02d", local->tm_year, local->tm_mon, local->tm_mday, local->tm_hour, local->tm_min, local->tm_sec);

    /* 出力ファイル */
    sprintf(output_file_name, "%s-%s-%s.txt", datetime, category, name);
    sprintf(output_file_path, "%s%s", OUTPUT_PATH, output_file_name);

    /* 出力先ディレクトリの作成 */
    _mkdir(OUTPUT_PATH);

    /* ファイルをオープンする */
	if ((fp = fopen(output_file_path, "w")) == NULL) {
		// ファイルオープンエラー
		procError(106);;
    	return 106;
	}

    /* 画面表示を消す（OS依存） */
    system("cls");

	/* 出題処理 */
    sprintf(start_msg, "*** %sに関する問題を%d問出題します。 ***\n", category, question_num);
    printf("%s", start_msg);
    if (fputs(start_msg , fp) == EOF) {
    	// ファイル書き込みエラー
		fclose(fp);
		deleteFile(output_file_path);
		procError(106);
		return 106;
    }
    for (i=0; i<question_num; i++) {
    	if (h_id[i] == 0) {
    		if (i == 0) {
    			procError(108);
    			return 108;
    		}
    		break;
    	}

        /* 出題 */
        sprintf(question_msg, "Q%d.%s\n", i+1, trim(h_question[i]));
        printf("%s", question_msg);
        if (fputs(question_msg , fp) == EOF) {
        	// ファイル書き込みエラー
    		fclose(fp);
    		deleteFile(output_file_path);
    		procError(106);
    		return 106;
        }
        sscanf(h_choice[i], "%[^,],%[^,],%[^,],%s", choice[0], choice[1], choice[2], choice[3]);
        sprintf(choice_msg, "%s %s %s %s\n", choice[0], choice[1], choice[2], choice[3]);
        printf(choice_msg);
        if (fputs(choice_msg , fp) == EOF) {
        	// ファイル書き込みエラー
    		fclose(fp);
    		deleteFile(output_file_path);
    		procError(106);
    		return 106;
        }

        /* 回答処理 */
        while (1) {
        	if (getsn(kaito, 3) == NULL) {
        		exit(0);
        	}
            if (strcmp(kaito, "A") == 0 || strcmp(kaito, "B") == 0  || strcmp(kaito, "C") == 0  || strcmp(kaito, "D") == 0) {
            	break;
            } else {
        		procWarning(2);
            }
        }
        sprintf(kaito_msg, "%s\n", kaito);
    	if (fputs(kaito_msg , fp) == EOF) {
    		// ファイル書き込みエラー
    		fclose(fp);
    		deleteFile(output_file_path);
    		procError(106);
    		return 106;
    	}

        /* 正誤判定 */
        if (strcmp(h_answer[i], kaito) == 0){
            strcpy(correctness_ary[i], "○");
            correct_answers_cnt++;

            /* データベース更新処理 */
            /* EXEC SQL UPDATE question_answer
                SET q_total = q_total + 1, correct_total = correct_total + 1
                WHERE id = :h_id[i]; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 7;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update question_answer  set q_total=(q_total+1),\
correct_total=(correct_total+1) where id=:b0";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )196;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)&h_id[i];
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqphsv = sqlstm.sqhstv;
            sqlstm.sqphsl = sqlstm.sqhstl;
            sqlstm.sqphss = sqlstm.sqhsts;
            sqlstm.sqpind = sqlstm.sqindv;
            sqlstm.sqpins = sqlstm.sqinds;
            sqlstm.sqparm = sqlstm.sqharm;
            sqlstm.sqparc = sqlstm.sqharc;
            sqlstm.sqpadto = sqlstm.sqadto;
            sqlstm.sqptdso = sqlstm.sqtdso;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) goto errorpt;
}


        } else {
            strcpy(correctness_ary[i], "×");

            /* データベース更新処理 */
            /* EXEC SQL UPDATE question_answer
                SET q_total = q_total + 1
                WHERE id = :h_id[i]; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 7;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update question_answer  set q_total=(q_total+1) \
where id=:b0";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )215;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)&h_id[i];
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqphsv = sqlstm.sqhstv;
            sqlstm.sqphsl = sqlstm.sqhstl;
            sqlstm.sqphss = sqlstm.sqhsts;
            sqlstm.sqpind = sqlstm.sqindv;
            sqlstm.sqpins = sqlstm.sqinds;
            sqlstm.sqparm = sqlstm.sqharm;
            sqlstm.sqparc = sqlstm.sqharc;
            sqlstm.sqpadto = sqlstm.sqadto;
            sqlstm.sqptdso = sqlstm.sqtdso;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) goto errorpt;
}


        }

        printf("%s", SEPARATE_MSG);
        if (fputs(SEPARATE_MSG , fp) == EOF) {
        	// ファイル書き込みエラー
    		fclose(fp);
    		deleteFile(output_file_path);
    		procError(106);
    		return 106;
        }
    }

    /* 結果出力 */
	printf("%s", RESULT_MSG);
    if (fputs(RESULT_MSG , fp) == EOF) {
    	// ファイル書き込みエラー
		fclose(fp);
		deleteFile(output_file_path);
		procError(106);
		return 106;
    }
    correct_rate = (double)correct_answers_cnt / (double)question_num * 100;
    if (correct_rate != 0) {
    	/* 小数点以下を切り捨てるため */
    	correct_rate -= 0.5;
    }
    sprintf(result_detail_msg, "%d問中%d問正解しました。（正解率： %.0f%%）\n", question_num, correct_answers_cnt, correct_rate);
    printf("%s", result_detail_msg);
    if (fputs(result_detail_msg , fp) == EOF) {
    	// ファイル書き込みエラー
		fclose(fp);
		deleteFile(output_file_path);
		procError(106);
		return 106;
    }
    for (int j=0; j<i; j++) {
    	sprintf(question_no_str, "%s%d.", "Q", j+1);
    	sprintf(result_kaito_msg, "%-5s%s", question_no_str, correctness_ary[j]);
    	if (strcmp(correctness_ary[j], "×") == 0) {
    		/* 正解を文字列に付与 */
        	sprintf(result_kaito_msg, "%s 正解は%s\n", result_kaito_msg, h_answer[j]);
    	} else {
        	sprintf(result_kaito_msg, "%s\n", result_kaito_msg);
    	}
    	printf("%s", result_kaito_msg);
        if (fputs(result_kaito_msg , fp) == EOF) {
        	// ファイル書き込みエラー
    		fclose(fp);
    		deleteFile(output_file_path);
    		procError(106);
    		return 106;
        }
    }

    /* コミット */
    /* EXEC SQL COMMIT; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 7;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )234;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) goto errorpt;
}



    /* ファイル名出力 */
    printf("「%s」というファイル名で出力されました。\n", output_file_name);

    /* バッファを出力する。 */
    fflush(fp);

    /* ファイルをクローズ */
    fclose(fp);

    /* ファイル転送処理 */
    /* ファイル転送不可能な場合は警告表示をし、処理をスキップ */
    if (existWinSCP() != 0) {
		/* 転送用ツールがない */
    	procWarning(3);
    	/* 処理スキップ扱いなので、正常終了 */
    	return 0;
    }
    if (existIconv() != 0) {
		/* 文字コード変換用ツールがない */
    	procWarning(4);
    	/* 処理スキップ扱いなので、正常終了 */
    	return 0;
    }

	/* 転送用ファイルの作成*/
	if (iconvFile(output_file_path, convert_file_path, "sjis", "UTF-8") != 0) {
		/* 文字エンコード失敗 */
		procWarning(4);
    	/* 処理スキップ扱いなので、正常終了 */
    	return 0;
	}

	/* ファイル転送 */
	strcpy(destination_file_path, DESTINATION_DIR);
	strcat(destination_file_path, output_file_name);
	if (putFile(output_file_path, destination_file_path) != 0) {
		/* 転送失敗 */
		procWarning(3);
    	/* 処理スキップ扱いなので、正常終了 */
		return 0;
	}

	/* ファイル転送まで成功したら、ファイルを削除する */
	deleteFile(output_file_path);
	deleteFile(convert_file_path);

    return 0;

errorpt:
    //printf("\n\n%-70s \n",sqlca.sqlerrm.sqlerrmc);

    /* 無限ループ回避 */
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* ロールバック */
	/* EXEC SQL ROLLBACK; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )249;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



	/* ファイルを開いている場合閉じる */
	if (fp != NULL) {
		fclose(fp);
	}

	/* ファイルが存在する場合は削除する */
	if (existFile(output_file_path) == 1) {
		deleteFile(output_file_path);
	}
	procError(255);
	return 255;
}

void setMsg() {
	strcpy(WARNING_MSG_LIST[1], "指定された数に対して問題数が不足しています。登録されている問題の数だけ出題されます。\n");
	strcpy(WARNING_MSG_LIST[2], "問題への回答は「A」「B」「C」「D」いずれかで入力してください。\n");
	strcpy(WARNING_MSG_LIST[3], "ファイル転送ができないためローカルでのみ保存されます。\n");
	strcpy(WARNING_MSG_LIST[4], "Linux用変換ファイルの作成に失敗しました。ローカルでのみ保存されます。\n");
	strcpy(WARNING_MSG_LIST[5], "名前は30文字以内で入力してください。\n");
	strcpy(ERROR_MSG_LIST[100], "引数が指定されていません。次のような形式で実行してください。 qa.exe [カテゴリ] [問題数]\n");
	strcpy(ERROR_MSG_LIST[101], "カテゴリの文字数が多すぎます。\n");
	strcpy(ERROR_MSG_LIST[102], "指定されたカテゴリは存在しません。\n");
	strcpy(ERROR_MSG_LIST[103], "問題数は半角数字で入力してください。\n");
	strcpy(ERROR_MSG_LIST[104], "問題数は1以上の値で入力してください。\n");
	strcpy(ERROR_MSG_LIST[105], "問題数は100以下の値で入力してください。\n");
	strcpy(ERROR_MSG_LIST[106], "ファイル書き込みに失敗しました。\n");
	strcpy(ERROR_MSG_LIST[107], "ファイルの転送に失敗しました。\n");
	strcpy(ERROR_MSG_LIST[255], "プログラムが異常終了しました。\n");
}

/**
 * 警告処理を行う。
 * @param warning_code: 警告コード
 */
void procWarning(int warning_code) {
	char *p, *msg[256];
	strcpy(msg, WARNING_MSG_LIST[warning_code]);
	/* PowerShell用のエスケープ文字を付与 */
	while ((p = strchr(msg, ' '))!=NULL) *p = '`';
	/* 警告メッセージを出力 */
	printf("[WARNING][%d]%s", warning_code, WARNING_MSG_LIST[warning_code]);
	/* イベント登録 */
	registerEvent("Warning", warning_code, msg);
}

/**
 * エラー処理を行う。
 * @param error_code: エラーコード
 */
void procError(int error_code) {
	char *p, *msg[256];
	strcpy(msg, ERROR_MSG_LIST[error_code]);
	/* PowerShell用のエスケープ文字を付与 */
	while ((p = strchr(msg, ' '))!=NULL) *p = '`';
	/* エラーメッセージを出力 */
	printf("[ERROR][%d]%s", error_code, ERROR_MSG_LIST[error_code]);
	/* イベント登録 */
	registerEvent("Error", error_code, msg);
}
