WITH
ckodok AS (
    SELECT pkod AS pk, COUNT(DISTINCT ckod) AS szam
    FROM SZALLIT
    GROUP BY pkod
)
SELECT DISTINCT pkod, pnev
FROM (SZALLIT NATURAL JOIN PROJEKT), ckodok
WHERE pkod = pk
AND szam = (
    SELECT MAX(szam)
    FROM ckodok
);

SET SERVEROUTPUT ON;

DECLARE
n NUMBER;
f NUMBER;

BEGIN
    n := 5;
    f := 1;
    
    FOR i IN 1..n LOOP
        f := f * i;
    END LOOP;
    
    dbms_output.put_line(f);
END;

-- Lent definialtuk a fact fuggvenyt es elmentettuk a db-be.
BEGIN
    dbms_output.put_line(fact(5));
    dbms_output.put_line(fact(10));
END;

CREATE OR REPLACE 
FUNCTION fact(n INTEGER) RETURN INTEGER IS
    BEGIN
        IF n < 0 THEN
            RETURN -1;
        ELSIF n > 1 THEN
            RETURN n * fact(n - 1);
        ELSE RETURN 1;
        END IF;
    END;


CREATE OR REPLACE
FUNCTION prime(n INTEGER) RETURN INTEGER IS
m INTEGER;
BEGIN
    m := FLOOR(SQRT(n));

    FOR i IN 2..m LOOP
        IF MOD(n, i) = 0 THEN
            RETURN 0;
        END IF;
    END LOOP;

    RETURN 1;
END prime;

CREATE TABLE GYAK8 AS
SELECT dkod, dnev
FROM DOLGOZO
WHERE prime(dkod) = 1;

SELECT object_name "TABLE", created FROM user_objects 
WHERE object_type='TABLE' AND object_name LIKE 'GYAK8'
ORDER BY object_name;
