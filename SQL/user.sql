/* QA�V�X�e���̃A�v���P�[�V�������[�U�̍쐬 */
CREATE USER QA
  identified by qsATXjfZ
  default tablespace QA
  temporary tablespace TEMP
;

/* �\���쐬�ł��錠�� */
GRANT CREATE ANY TABLE TO QA;

/* �\��ύX�ł��錠�� */
GRANT ALTER ANY TABLE TO QA;

/* SELECT�ł��錠�� */
GRANT SELECT ANY TABLE TO QA;

/* INSERT�ł��錠�� */
GRANT INSERT ANY TABLE TO QA;

/* UPDATE�ł��錠�� */
GRANT UPDATE ANY TABLE TO QA;

/* DELETE�ł��錠�� */
GRANT DELETE ANY TABLE TO QA;

/* TRIGGER���쐬�ł��錠�� */
GRANT CREATE ANY TRIGGER TO QA;

/* �\�̈�̍쐬���� */
GRANT UNLIMITED TABLESPACE TO QA;

/* �ڑ������̕t�^ */
GRANT CONNECT TO QA;

/* �V�[�P���X�쐬�����̂̕t�^ */
GRANT CREATE ANY SEQUENCE TO QA;

/* V$SQLSTATS�ւ̎Q�ƌ�����t�^ */
grant select on V$SQLSTATS to [���[�U��];