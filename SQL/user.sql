/* QAシステムのアプリケーションユーザの作成 */
CREATE USER QA
  identified by qsATXjfZ
  default tablespace QA
  temporary tablespace TEMP
;

/* 表を作成できる権限 */
GRANT CREATE ANY TABLE TO QA;

/* 表を変更できる権限 */
GRANT ALTER ANY TABLE TO QA;

/* SELECTできる権限 */
GRANT SELECT ANY TABLE TO QA;

/* INSERTできる権限 */
GRANT INSERT ANY TABLE TO QA;

/* UPDATEできる権限 */
GRANT UPDATE ANY TABLE TO QA;

/* DELETEできる権限 */
GRANT DELETE ANY TABLE TO QA;

/* TRIGGERを作成できる権限 */
GRANT CREATE ANY TRIGGER TO QA;

/* 表領域の作成権限 */
GRANT UNLIMITED TABLESPACE TO QA;

/* 接続権限の付与 */
GRANT CONNECT TO QA;

/* シーケンス作成権限のの付与 */
GRANT CREATE ANY SEQUENCE TO QA;

/* V$SQLSTATSへの参照権限を付与 */
grant select on V$SQLSTATS to [ユーザ名];