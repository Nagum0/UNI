CREATE OR REPLACE PROCEDURE P_FIB(n IN INTEGER, m OUT INTEGER) IS
BEGIN
    IF n <= 1 THEN
        m := n;
    ELSE
        DECLARE
            m1 INTEGER;
            m2 INTEGER;
        BEGIN
            P_FIB(n - 1, m1);
            P_FIB(n - 2, m2);
            m := m1 + m2;
        END;
    END IF;
END;

CREATE OR REPLACE FUNCTION LNKO(a INTEGER, b INTEGER) RETURN NUMBER IS
BEGIN
    DECLARE 
        n INTEGER;
        m INTEGER;
    BEGIN
        n := a;
        m := b;

        WHILE m != 0 LOOP
            DECLARE
                temp INTEGER;
            BEGIN
                temp := m;
                m := MOD(n, m);
                n := temp;
            END;
        END LOOP;

        RETURN n;
    END;
END;

CREATE OR REPLACE FUNCTION FACTOR(n INTEGER) RETURN INTEGER IS
BEGIN
    IF n = 0 THEN
        RETURN 1;
    ELSE
        RETURN n * FACTOR(n - 1);
    END IF;
END;

CREATE OR REPLACE FUNCTION hanyszor3(p1 VARCHAR2, p2 VARCHAR2) RETURN INTEGER IS
BEGIN
    DECLARE
        n INTEGER; -- Length of p1
        m INTEGER; -- Index of last occurance
        c INTEGER; -- Count of substrings
    BEGIN
        n := LENGTH(p1);
        m := 1;
        c := 0;

        LOOP
            IF m = 0 THEN
                RETURN c;
            END IF;

            m := INSTR(p1, p2, m);

            IF m > 0 THEN
                c := c + 1;
                m := m + LENGTH(p2);
            END IF;
        END LOOP;
        
        RETURN c;
    END;
END;

DECLARE
    n INTEGER;
    m INTEGER;
BEGIN
    n := 10;
    P_FIB(n, m);
    DBMS_OUTPUT.PUT_LINE(m);
    DBMS_OUTPUT.PUT_LINE(LNKO(3570, 7293));
    DBMS_OUTPUT.PUT_LINE(FACTOR(5));
    DBMS_OUTPUT.PUT_LINE(HANYSZOR3('ab cd ef abab gt ab', 'ab'));
END;