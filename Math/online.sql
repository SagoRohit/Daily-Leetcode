-- writing a function  with input and output
CREATE OR REPLACE function IS_SENIOR_EMPLOYEE2(eid in varchar2)
return varchar2 IS
    JDATE DATE;
    YEARS NUMBER;
    msg varchar2(100);
BEGIN
    SELECT HIRE_DATE
    INTO JDATE
    FROM MY_EMPLOYEES
    WHERE EMPLOYEE_ID = eid;

    YEARS := MONTHS_BETWEEN(SYSDATE, JDATE) / 12;

    IF YEARS >= 10 THEN
        msg:='The employee worked 10 years or more';
    ELSE
        msg:='The employee worked less than 10 years';
    END IF;
    return msg;
EXCEPTION
WHEN NO_DATA_FOUND THEN
return 'No employee found.' ;
WHEN TOO_MANY_ROWS THEN
return 'More than one employee found.' ;
WHEN OTHERS THEN
return 'Some unknown error occurred.' ;
END;
/
declare
    message varchar2(100);
begin
    message := IS_SENIOR_EMPLOYEE2(100);
    dbms_output.put_line(message);
    message:= IS_SENIOR_EMPLOYEE2(1005);
    dbms_output.put_line(message);
end ;
/

select last_name, IS_SENIOR_EMPLOYEE2(employee_id)
from MY_EMPLOYEES


                          -- ================================= TRIGGERS ================================

--This trigger will run before insert on STUDENTS table
CREATE OR REPLACE TRIGGER HELLO_WORLD2
BEFORE INSERT
ON STUDENTS
DECLARE
BEGIN
DBMS_OUTPUT.PUT_LINE('Hello World2');
END ;
/
--This trigger will run after an insert or a delete statement on STUDENTS table
CREATE OR REPLACE TRIGGER HELLO_WORLD3
AFTER INSERT OR DELETE
ON STUDENTS
DECLARE
BEGIN
DBMS_OUTPUT.PUT_LINE('Hello World3');
END ;
/
--The following trigger will run after an update statement on STUDENTS table.
--Added with that, this trigger will only run when update is performed on the
--CGPA column.
CREATE OR REPLACE TRIGGER HELLO_WORLD4
AFTER UPDATE
OF CGPA
ON STUDENTS
DECLARE
BEGIN
DBMS_OUTPUT.PUT_LINE('Hello World4');
END ;
/
--The following trigger will run after an update operation on the STUDENTS table.
--Added with that, the trigger will run once for each row. The previous rows will
--run once for the whole statement, where this trigger will run N times if N rows
--are affected by the SQL statement.
CREATE OR REPLACE TRIGGER HELLO_WORLD5
AFTER UPDATE
OF CGPA
ON STUDENTS
FOR EACH ROW
DECLARE
BEGIN
DBMS_OUTPUT.PUT_LINE('Hello World5');
END ;
/

-- ======================================= EXAMPLE ================================
INSERT INTO STUDENTS VALUES ('Shakib Ahmed', 3.63);
--This will run HELLO_WORLD, HELLO_WORLD2, HELLO_WORLD3
DELETE FROM STUDENTS WHERE CGPA < 3.65 ;
--This will run HELLO_WOLRD3
UPDATE STUDENTS SET CGPA = CGPA + 0.01 WHERE STUDENT_NAME LIKE '%Shakib%';
--This will run HELLO_WORLD4, but will not run HELLO_WORLD5!!! Why? Because
--HELLO_WORLD5 is declared with FOR EACH ROW clause. This means trigger should
--be
--run for each row affected. Since, the above statement does not update any row
--(as the previous DELETE operation already deleted that row from the table)
--it will not run HELLO_WORLD5!
UPDATE STUDENTS SET STUDENT_NAME = 'Fahim Ahmed'
WHERE STUDENT_NAME = 'Fahim Hasan' ;
--This will not run any trigger. Although HELLO_TRIGGER4 is declared to be run
--after an update operation, the trigger will not run because the update is done
--on the column STUDENT_NAME rather than CGPA
UPDATE STUDENTS SET CGPA = CGPA + 0.01 ;
--This will run both HELLO_WORLD4 and HELLO_WORLD5 trigger. However, HELLO_WORLD5
--will run twice! Why? Because two rows will be affected by the SQL statement!



-- ================================ Problem 1 =============================
CREATE TABLE LOG_TABLE_CGPA_UPDATE
(
USERNAME VARCHAR2(25),
DATETIME DATE
) ;

create or replace trigger LOG_CGPA_UPDATE
after update
of CGPA
on STUDENTS
declare
    USERNAME varchar2(100);
begin
    USERNAME := USER;
    insert into LOG_TABLE_CGPA_UPDATE VALUES(USERNAME, SYSDATE);
end ;
/

-- ======== Example =========
update STUDENTS set cgpa = cgpa + 0.01;
update STUDENTS set cgpa = cgpa - 0.01;
select * LOG_TABLE_CGPA_UPDATE;


-- ================= Problem 2 =============
CREATE TABLE STUDENTS_DELETED(
STUDENT_NAME VARCHAR2(25),
CGPA NUMBER,
USERNAME VARCHAR2(25),
DATETIME DATE
) ;

CREATE OR REPLACE TRIGGER BACKUP_DELETED_STUDENTS
BEFORE DELETE
ON STUDENTS
FOR EACH ROW
DECLARE
V_NAME VARCHAR2(25);
V_USERNAME VARCHAR2(25);
V_CGPA NUMBER;
V_DATETIME DATE;
BEGIN
V_NAME := :OLD.STUDENT_NAME ;
V_CGPA := :OLD.CGPA ;
V_USERNAME := USER ;
V_DATETIME := SYSDATE ;
INSERT INTO STUDENTS_DELETED VALUES (V_NAME,V_CGPA,V_USERNAME,V_DATETIME);
END ;
/


-- ===================== Problem 3 =================
CREATE OR REPLACE TRIGGER CORRECT_STUDENT_NAME
BEFORE INSERT
ON STUDENTS
FOR EACH ROW
DECLARE
BEGIN
:NEW.STUDENT_NAME := INITCAP(:NEW.STUDENT_NAME) ;
END ;
/
--Issue the following SQL statements and then view the rows of STUDENTS table
INSERT INTO STUDENTS VALUES ('SHAkil ahMED', 3.80);
INSERT INTO STUDENTS VALUES ('masum billah', 3.60);



 -- ==================== online ================
 --------------------------------------------------------------------------
-- CSE 216 - Online 3 on PL/SQL
--------------------------------------------------------------------------

SET SERVEROUTPUT ON;

--------------------------------------------------------------------------
-- Table needed for Q1
--------------------------------------------------------------------------
CREATE TABLE MANAGER_SUMMARY (
    MANAGER_ID          NUMBER,
    DEPARTMENT_ID        NUMBER,
    MANAGER_NAME         VARCHAR2(100),
    DIRECT_REPORT_COUNT  NUMBER,
    GENERATED_BY         VARCHAR2(30),
    GENERATED_ON         DATE
);

--------------------------------------------------------------------------
-- Q1(a) Function: GET_DIRECT_REPORT_COUNT
--------------------------------------------------------------------------
CREATE OR REPLACE FUNCTION GET_DIRECT_REPORT_COUNT (
    P_EMP_ID IN NUMBER
) RETURN NUMBER
IS
    V_COUNT NUMBER;
BEGIN
    SELECT COUNT(*)
    INTO V_COUNT
    FROM EMPLOYEES
    WHERE MANAGER_ID = P_EMP_ID;

    RETURN V_COUNT;   -- COUNT(*) is never NULL, so 0 is returned automatically
END GET_DIRECT_REPORT_COUNT;
/

--------------------------------------------------------------------------
-- Q1(b) Procedure: BUILD_MANAGER_SUMMARY
--------------------------------------------------------------------------
CREATE OR REPLACE PROCEDURE BUILD_MANAGER_SUMMARY (
    P_DEPT_ID        IN  NUMBER,
    P_MANAGER_COUNT  OUT NUMBER,
    P_TOTAL_REPORTS  OUT NUMBER
)
IS
    V_EMP_COUNT NUMBER;
    V_REPORTS   NUMBER;
BEGIN
    P_MANAGER_COUNT := 0;
    P_TOTAL_REPORTS := 0;

    -- clear out any old rows for this department first
    DELETE FROM MANAGER_SUMMARY WHERE DEPARTMENT_ID = P_DEPT_ID;

    SELECT COUNT(*) INTO V_EMP_COUNT
    FROM EMPLOYEES
    WHERE DEPARTMENT_ID = P_DEPT_ID;

    IF V_EMP_COUNT = 0 THEN
        DBMS_OUTPUT.PUT_LINE('No employees in department ' || P_DEPT_ID);
        RETURN;
    END IF;

    FOR EMP_REC IN (
        SELECT EMPLOYEE_ID, FIRST_NAME, LAST_NAME
        FROM EMPLOYEES
        WHERE DEPARTMENT_ID = P_DEPT_ID
    ) LOOP
        V_REPORTS := GET_DIRECT_REPORT_COUNT(EMP_REC.EMPLOYEE_ID);

        IF V_REPORTS > 0 THEN
            INSERT INTO MANAGER_SUMMARY (
                MANAGER_ID, DEPARTMENT_ID, MANAGER_NAME,
                DIRECT_REPORT_COUNT, GENERATED_BY, GENERATED_ON
            ) VALUES (
                EMP_REC.EMPLOYEE_ID, P_DEPT_ID,
                EMP_REC.FIRST_NAME || ' ' || EMP_REC.LAST_NAME,
                V_REPORTS, USER, SYSDATE
            );

            P_MANAGER_COUNT := P_MANAGER_COUNT + 1;
            P_TOTAL_REPORTS := P_TOTAL_REPORTS + V_REPORTS;
        END IF;
    END LOOP;
END BUILD_MANAGER_SUMMARY;
/

--------------------------------------------------------------------------
-- Q1(c) Anonymous block: run for department 50
--------------------------------------------------------------------------
DECLARE
    V_MGR_COUNT   NUMBER;
    V_TOT_REPORTS NUMBER;
BEGIN
    BUILD_MANAGER_SUMMARY(50, V_MGR_COUNT, V_TOT_REPORTS);

    DBMS_OUTPUT.PUT_LINE('Managers found: ' || V_MGR_COUNT);
    DBMS_OUTPUT.PUT_LINE('Total direct reports: ' || V_TOT_REPORTS);
END;
/


--------------------------------------------------------------------------
-- Table needed for Q2
--------------------------------------------------------------------------
CREATE TABLE DEPT_RELOCATION_LOG (
    DEPARTMENT_ID        NUMBER,
    OLD_LOCATION_ID       NUMBER,
    NEW_LOCATION_ID       NUMBER,
    OLD_CITY              VARCHAR2(30),
    NEW_CITY              VARCHAR2(30),
    RELOCATION_TYPE       VARCHAR2(15),
    RAISE_PCT             NUMBER,
    EMPLOYEES_AFFECTED    NUMBER,
    CHANGED_BY            VARCHAR2(30),
    CHANGED_ON            DATE
);

--------------------------------------------------------------------------
-- Q2 Trigger: TRG_DEPT_RELOCATION
--------------------------------------------------------------------------
CREATE OR REPLACE TRIGGER TRG_DEPT_RELOCATION
AFTER UPDATE OF LOCATION_ID ON DEPARTMENTS
FOR EACH ROW
WHEN (OLD.LOCATION_ID != NEW.LOCATION_ID)
DECLARE
    V_OLD_CITY     LOCATIONS.CITY%TYPE;
    V_NEW_CITY     LOCATIONS.CITY%TYPE;
    V_OLD_COUNTRY  LOCATIONS.COUNTRY_ID%TYPE;
    V_NEW_COUNTRY  LOCATIONS.COUNTRY_ID%TYPE;
    V_OLD_REGION   COUNTRIES.REGION_ID%TYPE;
    V_NEW_REGION   COUNTRIES.REGION_ID%TYPE;
    V_TYPE         VARCHAR2(15);
    V_PCT          NUMBER;
    V_EMP_COUNT    NUMBER;
BEGIN
    -- old location's city / country / region
    SELECT L.CITY, L.COUNTRY_ID, C.REGION_ID
    INTO V_OLD_CITY, V_OLD_COUNTRY, V_OLD_REGION
    FROM LOCATIONS L
    JOIN COUNTRIES C ON C.COUNTRY_ID = L.COUNTRY_ID
    WHERE L.LOCATION_ID = :OLD.LOCATION_ID;

    -- new location's city / country / region
    SELECT L.CITY, L.COUNTRY_ID, C.REGION_ID
    INTO V_NEW_CITY, V_NEW_COUNTRY, V_NEW_REGION
    FROM LOCATIONS L
    JOIN COUNTRIES C ON C.COUNTRY_ID = L.COUNTRY_ID
    WHERE L.LOCATION_ID = :NEW.LOCATION_ID;

    -- decide relocation type and raise (checked top to bottom)
    IF V_OLD_COUNTRY = V_NEW_COUNTRY THEN
        V_TYPE := 'DOMESTIC';
        V_PCT  := 3;
    ELSIF V_OLD_REGION = V_NEW_REGION THEN
        V_TYPE := 'REGIONAL';
        V_PCT  := 8;
    ELSE
        V_TYPE := 'OVERSEAS';
        V_PCT  := 12;
    END IF;

    -- employees currently in the department
    SELECT COUNT(*) INTO V_EMP_COUNT
    FROM EMPLOYEES
    WHERE DEPARTMENT_ID = :NEW.DEPARTMENT_ID;

    -- apply the raise
    UPDATE EMPLOYEES
    SET SALARY = ROUND(SALARY * (100 + V_PCT) / 100, 2)
    WHERE DEPARTMENT_ID = :NEW.DEPARTMENT_ID;

    -- log the relocation
    INSERT INTO DEPT_RELOCATION_LOG (
        DEPARTMENT_ID, OLD_LOCATION_ID, NEW_LOCATION_ID,
        OLD_CITY, NEW_CITY, RELOCATION_TYPE, RAISE_PCT,
        EMPLOYEES_AFFECTED, CHANGED_BY, CHANGED_ON
    ) VALUES (
        :NEW.DEPARTMENT_ID, :OLD.LOCATION_ID, :NEW.LOCATION_ID,
        V_OLD_CITY, V_NEW_CITY, V_TYPE, V_PCT,
        V_EMP_COUNT, USER, SYSDATE
    );
END;
/

--------------------------------------------------------------------------
-- Q2 Demonstration
--------------------------------------------------------------------------

-- Test 1: DOMESTIC move (Southlake US -> South San Francisco US)
UPDATE DEPARTMENTS SET LOCATION_ID = 1500 WHERE DEPARTMENT_ID = 60;

-- Test 2: REGIONAL move (Munich DE -> London GB, both Europe)
UPDATE DEPARTMENTS SET LOCATION_ID = 2400 WHERE DEPARTMENT_ID = 70;

-- Test 3: OVERSEAS move (Toronto CA -> Tokyo JP)
UPDATE DEPARTMENTS SET LOCATION_ID = 1200 WHERE DEPARTMENT_ID = 20;

-- Test 4: same location assigned again -> no raise, no log row
UPDATE DEPARTMENTS SET LOCATION_ID = 2400 WHERE DEPARTMENT_ID = 40;

-- Test 5: two empty departments relocated in one statement (Seattle US -> Toronto CA)
UPDATE DEPARTMENTS SET LOCATION_ID = 1800 WHERE DEPARTMENT_ID IN (130, 140);

-- verify the log
SELECT DEPARTMENT_ID, OLD_LOCATION_ID, NEW_LOCATION_ID,
       OLD_CITY, NEW_CITY, RELOCATION_TYPE, RAISE_PCT, EMPLOYEES_AFFECTED
FROM DEPT_RELOCATION_LOG
ORDER BY DEPARTMENT_ID;

-- verify the salary updates
SELECT EMPLOYEE_ID, DEPARTMENT_ID, SALARY
FROM EMPLOYEES
WHERE DEPARTMENT_ID IN (20, 40, 60, 70)
ORDER BY DEPARTMENT_ID, EMPLOYEE_ID;

ROLLBACK;