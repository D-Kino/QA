/* question_answer�e�[�u���̍폜 */
-- DROP TABLE question_answer;

/* question_answer�e�[�u���̍쐬 */
CREATE TABLE question_answer
 (
 id NUMBER,
 category VARCHAR2(50),
 question VARCHAR2(200),
 choice VARCHAR2(200),
 answer CHAR(1),
 q_total NUMBER,
 correct_total NUMBER,
 CONSTRAINT pk1 PRIMARY KEY(id)
 )
 TABLESPACE QA;

/* auto increment */
CREATE SEQUENCE qa_seq START WITH 1;

CREATE OR REPLACE TRIGGER qa_bir 
BEFORE INSERT ON question_answer 
FOR EACH ROW

BEGIN
  SELECT qa_seq.NEXTVAL
  INTO   :new.id
  FROM   dual;
END;
/