-- ============================================================
-- January 2026 CSE 216
-- Online on PL/SQL - Subsection A1+A2
-- Oracle PL/SQL Solutions
-- Schema: standard Oracle HR EMPLOYEES / DEPARTMENTS /
--         LOCATIONS / COUNTRIES tables
-- ============================================================

SET SERVEROUTPUT ON;


-- ============================================================
-- QUESTION 1
-- ============================================================

-- ------------------------------------------------------------
-- Support table
-- ------------------------------------------------------------
CREATE TABLE MANAGER_SUMMARY (
    MANAGER_ID           NUMBER,
    DEPARTMENT_ID        NUMBER,
    MANAGER_NAME         VARCHAR2(100),
    DIRECT_REPORT_COUNT  NUMBER,
    GENERATED_BY         VARCHAR2(30),
    GENERATED_ON         DATE
);


-- ------------------------------------------------------------
-- (a) Function: GET_DIRECT_REPORT_COUNT
-- ------------------------------------------------------------
CREATE OR REPLACE FUNCTION GET_DIRECT_REPORT_COUNT (
    P_EMP_ID IN NUMBER
) RETURN NUMBER
IS
    v_count NUMBER;
BEGIN
    SELECT COUNT(*)
    INTO   v_count
    FROM   EMPLOYEES
    WHERE  MANAGER_ID = P_EMP_ID;

    RETURN v_count;
END GET_DIRECT_REPORT_COUNT;
/


-- ------------------------------------------------------------
-- (b) Procedure: BUILD_MANAGER_SUMMARY
-- ------------------------------------------------------------
CREATE OR REPLACE PROCEDURE BUILD_MANAGER_SUMMARY (
    P_DEPT_ID        IN  NUMBER,
    P_MANAGER_COUNT  OUT NUMBER,
    P_TOTAL_REPORTS  OUT NUMBER
)
IS
    v_report_count NUMBER;
    v_emp_exists   NUMBER;
BEGIN
    P_MANAGER_COUNT := 0;
    P_TOTAL_REPORTS := 0;

    SELECT COUNT(*)
    INTO   v_emp_exists
    FROM   EMPLOYEES
    WHERE  DEPARTMENT_ID = P_DEPT_ID;

    IF v_emp_exists = 0 THEN
        DBMS_OUTPUT.PUT_LINE('No employees in department ' || P_DEPT_ID);
        RETURN;
    END IF;

    DELETE FROM MANAGER_SUMMARY
    WHERE  DEPARTMENT_ID = P_DEPT_ID;

    FOR emp_rec IN (
        SELECT EMPLOYEE_ID, FIRST_NAME, LAST_NAME
        FROM   EMPLOYEES
        WHERE  DEPARTMENT_ID = P_DEPT_ID
    ) LOOP
        v_report_count := GET_DIRECT_REPORT_COUNT(emp_rec.EMPLOYEE_ID);

        IF v_report_count > 0 THEN
            INSERT INTO MANAGER_SUMMARY (
                MANAGER_ID, DEPARTMENT_ID, MANAGER_NAME,
                DIRECT_REPORT_COUNT, GENERATED_BY, GENERATED_ON
            ) VALUES (
                emp_rec.EMPLOYEE_ID,
                P_DEPT_ID,
                emp_rec.FIRST_NAME || ' ' || emp_rec.LAST_NAME,
                v_report_count,
                USER,
                SYSDATE
            );

            P_MANAGER_COUNT := P_MANAGER_COUNT + 1;
            P_TOTAL_REPORTS := P_TOTAL_REPORTS + v_report_count;
        END IF;
    END LOOP;
END BUILD_MANAGER_SUMMARY;
/


-- ------------------------------------------------------------
-- (c) Anonymous block: run for Department 50
-- ------------------------------------------------------------
DECLARE
    v_manager_count NUMBER;
    v_total_reports NUMBER;
BEGIN
    BUILD_MANAGER_SUMMARY(50, v_manager_count, v_total_reports);

    DBMS_OUTPUT.PUT_LINE('P_MANAGER_COUNT = ' || v_manager_count);
    DBMS_OUTPUT.PUT_LINE('P_TOTAL_REPORTS = ' || v_total_reports);
END;
/


-- ============================================================
-- QUESTION 2
-- ============================================================

-- ------------------------------------------------------------
-- Support table
-- ------------------------------------------------------------
CREATE TABLE DEPT_RELOCATION_LOG (
    DEPARTMENT_ID        NUMBER,
    OLD_LOCATION_ID      NUMBER,
    NEW_LOCATION_ID      NUMBER,
    OLD_CITY             VARCHAR2(30),
    NEW_CITY             VARCHAR2(30),
    RELOCATION_TYPE      VARCHAR2(15),
    RAISE_PCT            NUMBER,
    EMPLOYEES_AFFECTED   NUMBER,
    CHANGED_BY           VARCHAR2(30),
    CHANGED_ON           DATE
);


-- ------------------------------------------------------------
-- Row-level trigger on DEPARTMENTS
-- ------------------------------------------------------------
CREATE OR REPLACE TRIGGER TRG_DEPT_RELOCATION
AFTER UPDATE OF LOCATION_ID ON DEPARTMENTS
FOR EACH ROW
DECLARE
    v_old_city    LOCATIONS.CITY%TYPE;
    v_new_city    LOCATIONS.CITY%TYPE;
    v_old_country LOCATIONS.COUNTRY_ID%TYPE;
    v_new_country LOCATIONS.COUNTRY_ID%TYPE;
    v_old_region  COUNTRIES.REGION_ID%TYPE;
    v_new_region  COUNTRIES.REGION_ID%TYPE;
    v_reloc_type  DEPT_RELOCATION_LOG.RELOCATION_TYPE%TYPE;
    v_raise_pct   NUMBER;
    v_emp_count   NUMBER;
BEGIN
    IF :OLD.LOCATION_ID != :NEW.LOCATION_ID THEN

        SELECT L.CITY, L.COUNTRY_ID, C.REGION_ID
        INTO   v_old_city, v_old_country, v_old_region
        FROM   LOCATIONS L
        JOIN   COUNTRIES C ON C.COUNTRY_ID = L.COUNTRY_ID
        WHERE  L.LOCATION_ID = :OLD.LOCATION_ID;

        SELECT L.CITY, L.COUNTRY_ID, C.REGION_ID
        INTO   v_new_city, v_new_country, v_new_region
        FROM   LOCATIONS L
        JOIN   COUNTRIES C ON C.COUNTRY_ID = L.COUNTRY_ID
        WHERE  L.LOCATION_ID = :NEW.LOCATION_ID;

        IF v_new_country = v_old_country THEN
            v_reloc_type := 'DOMESTIC';
            v_raise_pct  := 3;
        ELSIF v_new_region = v_old_region THEN
            v_reloc_type := 'REGIONAL';
            v_raise_pct  := 8;
        ELSE
            v_reloc_type := 'OVERSEAS';
            v_raise_pct  := 12;
        END IF;

        SELECT COUNT(*)
        INTO   v_emp_count
        FROM   EMPLOYEES
        WHERE  DEPARTMENT_ID = :NEW.DEPARTMENT_ID;

        UPDATE EMPLOYEES
        SET    SALARY = ROUND(SALARY * (100 + v_raise_pct) / 100, 2)
        WHERE  DEPARTMENT_ID = :NEW.DEPARTMENT_ID;

        INSERT INTO DEPT_RELOCATION_LOG (
            DEPARTMENT_ID, OLD_LOCATION_ID, NEW_LOCATION_ID,
            OLD_CITY, NEW_CITY, RELOCATION_TYPE, RAISE_PCT,
            EMPLOYEES_AFFECTED, CHANGED_BY, CHANGED_ON
        ) VALUES (
            :NEW.DEPARTMENT_ID, :OLD.LOCATION_ID, :NEW.LOCATION_ID,
            v_old_city, v_new_city, v_reloc_type, v_raise_pct,
            v_emp_count, USER, SYSDATE
        );
    END IF;
END TRG_DEPT_RELOCATION;
/


-- ------------------------------------------------------------
-- Test driver
-- ------------------------------------------------------------

-- Test 1: DOMESTIC move (Southlake US -> South San Francisco US)
UPDATE DEPARTMENTS
SET    LOCATION_ID = 1500
WHERE  DEPARTMENT_ID = 60;

-- Test 2: REGIONAL move (Munich DE -> London GB, both Europe)
UPDATE DEPARTMENTS
SET    LOCATION_ID = 2400
WHERE  DEPARTMENT_ID = 70;

-- Test 3: OVERSEAS move (Toronto CA, Americas -> Tokyo JP, Asia)
UPDATE DEPARTMENTS
SET    LOCATION_ID = 1200
WHERE  DEPARTMENT_ID = 20;

-- Test 4: Assign the same location (no-op, no raise, no log row)
UPDATE DEPARTMENTS
SET    LOCATION_ID = 2400
WHERE  DEPARTMENT_ID = 40;

-- Test 5: Two empty departments in ONE statement (Seattle US -> Toronto CA)
UPDATE DEPARTMENTS
SET    LOCATION_ID = 1800
WHERE  DEPARTMENT_ID IN (130, 140);


-- ------------------------------------------------------------
-- Verify the log
-- ------------------------------------------------------------
SELECT DEPARTMENT_ID, OLD_LOCATION_ID,
       NEW_LOCATION_ID, OLD_CITY, NEW_CITY,
       RELOCATION_TYPE, RAISE_PCT,
       EMPLOYEES_AFFECTED
FROM   DEPT_RELOCATION_LOG
ORDER BY DEPARTMENT_ID;


-- ------------------------------------------------------------
-- Verify the employees
-- ------------------------------------------------------------
SELECT EMPLOYEE_ID, DEPARTMENT_ID, SALARY
FROM   EMPLOYEES
WHERE  DEPARTMENT_ID IN (20, 40, 60, 70)
ORDER BY DEPARTMENT_ID, EMPLOYEE_ID;


-- ------------------------------------------------------------
-- Roll back all test data changes
-- ------------------------------------------------------------
ROLLBACK;
