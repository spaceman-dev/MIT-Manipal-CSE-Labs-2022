--StudentTable for execution of PL/SQL block Lab 8


CREATE TABLE StudentTable(
RollNo NUMERIC(10,0),
GPA NUMERIC(10,2));


INSERT INTO StudentTable(RollNo, GPA) VALUES(1, 5.8);
INSERT INTO StudentTable(RollNo, GPA) VALUES(2, 6.5);
INSERT INTO StudentTable(RollNo, GPA) VALUES(3, 3.4);
INSERT INTO StudentTable(RollNo, GPA) VALUES(4, 7.8);
INSERT INTO StudentTable(RollNo, GPA) VALUES(5, 9.5);

--Q1
SET SERVEROUTPUT ON
DECLARE
RNo StudentTable.RollNo%TYPE;
Gpa1 StudentTable.GPA%TYPE;
BEGIN
Rno := &RollNo;
SELECT GPA INTO Gpa1 FROM StudentTable WHERE RollNo=RNo;
DBMS_OUTPUT.PUT_LINE('GPA='||Gpa1);
END;
/

--Q2
SET SERVEROUTPUT ON
DECLARE
RNo StudentTable.RollNo%TYPE;
Gpa1 StudentTable.GPA%TYPE;
BEGIN
Rno := &RollNo;
SELECT GPA INTO Gpa1 FROM StudentTable WHERE RollNo=RNo;
IF Gpa1>9 THEN
DBMS_OUTPUT.PUT_LINE('A+');
ELSIF Gpa1>8 THEN
DBMS_OUTPUT.PUT_LINE('A');
ELSIF Gpa1>7 THEN
DBMS_OUTPUT.PUT_LINE('B');
ELSIF Gpa1>6 THEN
DBMS_OUTPUT.PUT_LINE('C');
ELSIF Gpa1>5 THEN
DBMS_OUTPUT.PUT_LINE('D');
ELSIF GPa1>4 THEN
DBMS_OUTPUT.PUT_LINE('E');
ELSE
DBMS_OUTPUT.PUT_LINE('F');
END IF; 
END;
/
--Q4
SET SERVEROUTPUT ON
DECLARE
RNo StudentTable.RollNo%TYPE;
Gpa1 StudentTable.GPA%TYPE;
LetGrad1 StudentTable.LetterGrade%TYPE;
BEGIN
FOR i IN 1..5 LOOP
SELECT LetterGrade INTO LetGrad1 FROM StudentTable WHERE RollNo=i;
DBMS_OUTPUT.PUT_LINE('Letter Grade : '|| LetGrad1)
END LOOP;
END;
/
--Q5
ALTER TABLE StudentTable ADD (LetterGrade VARCHAR(3));
SET SERVEROUTPUT ON
DECLARE
RNo StudentTable.RollNo%TYPE;
Gpa1 StudentTable.GPA%TYPE;
x NUMBER := 1;
BEGIN
WHILE x<6
LOOP
SELECT GPA INTO Gpa1 FROM StudentTable WHERE RollNo=x;
IF Gpa1>9 THEN
UPDATE StudentTable SET LetterGrade='A+' WHERE RollNo=x;
ELSIF Gpa1>8 THEN
UPDATE StudentTable SET LetterGrade='A' WHERE RollNo=x;
ELSIF Gpa1>7 THEN
UPDATE StudentTable SET LetterGrade='B' WHERE RollNo=x;
ELSIF Gpa1>6 THEN
UPDATE StudentTable SET LetterGrade='C' WHERE RollNo=x;
ELSIF Gpa1>5 THEN
UPDATE StudentTable SET LetterGrade='D' WHERE RollNo=x;
ELSIF Gpa1>4 THEN
UPDATE StudentTable SET LetterGrade='E' WHERE RollNo=x;
ELSE
UPDATE StudentTable SET LetterGrade='F' WHERE RollNo=x;
END IF;
x:=x+1;
END LOOP;
END;
/

--Q6
SET SERVEROUTPUT ON
DECLARE
RNo StudentTable.RollNo%TYPE;
Gpa1 StudentTable.GPA%TYPE;
high NUMBER :=0;
j NUMBER :=0;
BEGIN
FOR i IN 1..5 LOOP
SELECT GPA INTO Gpa1 FROM StudentTable WHERE RollNo=i;
IF Gpa1>high THEN
high:=Gpa1;
j:=i;
END IF;
END LOOP;
DBMS_OUTPUT.PUT_LINE('RollNo of Student with Highest GPA is '||j);
END;
/

--Q9
SET SERVEROUTPUT ON
DECLARE
OutOfGrades EXCEPTION;
RNo StudentTable.RollNo%TYPE;
Gpa1 StudentTable.GPA%TYPE;
x NUMBER := 1;
BEGIN
WHILE x<6
LOOP
SELECT GPA INTO Gpa1 FROM StudentTable WHERE RollNo=x;
IF Gpa1>10 OR Gpa1<0 THEN
RAISE OutOfGrades;
END IF;
IF Gpa1>9 THEN
UPDATE StudentTable SET LetterGrade='A+' WHERE RollNo=x;
ELSIF Gpa1>8 THEN
UPDATE StudentTable SET LetterGrade='A' WHERE RollNo=x;
ELSIF Gpa1>7 THEN
UPDATE StudentTable SET LetterGrade='B' WHERE RollNo=x;
ELSIF Gpa1>6 THEN
UPDATE StudentTable SET LetterGrade='C' WHERE RollNo=x;
ELSIF Gpa1>5 THEN
UPDATE StudentTable SET LetterGrade='D' WHERE RollNo=x;
ELSIF Gpa1>4 THEN
UPDATE StudentTable SET LetterGrade='E' WHERE RollNo=x;
ELSE
UPDATE StudentTable SET LetterGrade='F' WHERE RollNo=x;
END IF;
x:=x+1;
END LOOP;
EXCEPTION 
WHEN OutOfGrades THEN DBMS_OUTPUT.PUT_LINE('Grades Not In Range');
WHEN OTHERS THEN DBMS_OUTPUT.PUT_LINE('Error');
END;
/
