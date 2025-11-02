/* 
    SELECT ... INTO v1
    Írjunk meg egy függvényt, amelyik visszaadja egy adott fizetési kategóriába tartozó
    dolgozók átlagfizetését.
*/

CREATE OR REPLACE FUNCTION kat_atlag(n INTEGER) RETURN NUMBER IS
BEGIN
    DECLARE
        atlag NUMBER;
    BEGIN
        SELECT AVG(fizetes) 
        INTO atlag
        FROM DOLGOZO CROSS JOIN FIZ_KATEGORIA
        WHERE fizetes BETWEEN also AND felso
        AND kategoria = n;

        RETURN atlag;
    END;
END;

SELECT kat_atlag(2) FROM DUAL;

/* 
    SELECT ... INTO v1, v2
    Írjunk meg egy procedúrát, amelyik kiírja azon dolgozók számát és átlagfizetését,
    akiknek a belépési dátuma a paraméterül megadott nevű napon (pl. 'Hétfő') volt.
*/

CREATE OR REPLACE PROCEDURE nap_atl(d VARCHAR2) IS
BEGIN
    DECLARE
        c INTEGER := 0;
        atlag NUMBER := 0;
    BEGIN
        SELECT COUNT(*), TRUNC(AVG(fizetes), 2)
        INTO c, atlag
        FROM DOLGOZO
        WHERE TO_CHAR(belepes, 'DAY', 'nls_date_language=hungarian') = RPAD(UPPER(d), 9);

        DBMS_OUTPUT.PUT_LINE(c);
        DBMS_OUTPUT.PUT_LINE(atlag);
    END;
END;

set serveroutput on;
execute nap_atl('Csütörtök'); -- példa output: Dolgozók száma: 4, Átlag fiz: 2481,25

/* 
    Insert, Delete, Update 
    Írjunk meg egy procedúrát, amelyik megnöveli azoknak a dolgozóknak a fizetését, akiknek a 
    fizetési kategóriája ugyanaz, mint a procedúra paramétere. A növelés mértéke a dolgozó
    osztályában előforduló legkisebb fizetés legyen.
    A procedúra a módosítás után írja ki a fizetések átlagát két tizedesjegyre kerekítve.
    A procedúra a kiírás után adjon ki egy ROLLBACK utasítást, hogy megmaradjanak az eredeti fizetések,
    így a procedúrát többször is futtatni tudják.
*/

CREATE OR REPLACE PROCEDURE kat_novel(p_kategoria NUMBER) IS
    v_atlag NUMBER := 0;
BEGIN
    UPDATE DOLGOZO d1
    SET fizetes = fizetes + NVL((
        SELECT MIN(fizetes)
        FROM DOLGOZO d2
        WHERE d1.oazon = d2.oazon
    ), 0)
    WHERE EXISTS (
        SELECT 1
        FROM FIZ_KATEGORIA
        WHERE d1.fizetes BETWEEN also AND felso
        AND p_kategoria = kategoria
    );

    SELECT TRUNC(AVG(fizetes), 2)
    INTO v_atlag
    FROM DOLGOZO;

    DBMS_OUTPUT.PUT_LINE(v_atlag);

    ROLLBACK;
END;

SELECT TRUNC(AVG(fizetes), 2)
FROM DOLGOZO, FIZ_KATEGORIA
WHERE fizetes BETWEEN also AND felso
AND kategoria = 2;

execute kat_novel(2);

/* 
    Cursor (több soros SELECT)
    Írjunk meg egy procedúrát, amelyik veszi a paraméterül megadott osztály dolgozóit ábécé 
    szerinti sorrendben, és kiírja a foglalkozásaikat egy karakterláncban összefűzve.
*/

CREATE OR REPLACE PROCEDURE print_foglalkozas(o_nev VARCHAR2) IS
    CURSOR dolgozo_cursor IS
    SELECT foglalkozas
    FROM DOLGOZO NATURAL JOIN OSZTALY
    WHERE onev = o_nev
    ORDER BY foglalkozas;
    v_str VARCHAR2(1000) := '';
    v_first BOOLEAN := TRUE;
BEGIN
    FOR rec IN dolgozo_cursor LOOP
        IF v_first THEN
            v_str := rec.foglalkozas;
            v_first := FALSE;
        ELSE
            v_str := v_str || '-' || rec.foglalkozas;
        END IF;
    END LOOP;

    DBMS_OUTPUT.PUT_LINE(v_str);
END;

execute print_foglalkozas('ACCOUNTING');  -- példa output: MANAGER-PRESIDENT-CLERK

/* 
    Cursor (több soros SELECT)
    Írjunk meg egy függvényt, amelyik veszi a paraméterül megadott osztály dolgozóit ábécé 
    szerinti sorrendben, és visszaadja a foglalkozásaikat egy karakterláncban összefűzve.
*/

CREATE OR REPLACE FUNCTION get_foglalkozas(o_nev VARCHAR2) RETURN VARCHAR2 IS
    CURSOR dolgozo_cursor IS
    SELECT foglalkozas
    FROM DOLGOZO NATURAL JOIN OSZTALY
    WHERE onev = o_nev
    ORDER BY dnev;
    v_str VARCHAR2(100) := '';
    v_first BOOLEAN := TRUE;
BEGIN
    FOR rec IN dolgozo_cursor LOOP
        IF v_first THEN
            v_str := rec.foglalkozas;
            v_first := FALSE;
        ELSE
            v_str := v_str || '-' || rec.foglalkozas;
        END IF;
    END LOOP;

    RETURN v_str;
END;

SELECT get_foglalkozas('ACCOUNTING') FROM dual;

/* 
    Asszociatív tömb  --> TABLE OF ... INDEX BY ...
    Írjunk meg egy procedúrát, amelyik veszi az első n prímszámot (1. prímszám: 2, 2. prímszám: 3, stb.)
    és beleteszi azokat egy asszociatív tömbbe. A procedúra a végén írja ki a tömb utolsó elemét és a
    prímszámok összegét.
*/

CREATE OR REPLACE PROCEDURE primes(n INTEGER) IS
    TYPE primes_type IS TABLE OF INTEGER INDEX BY BINARY_INTEGER;
    primes primes_type;
    i INTEGER := 2;
    c BINARY_INTEGER := 1;
    ossz INTEGER := 0;
BEGIN
    WHILE i <= n LOOP
        IF PRIME(i) = 1 THEN
            primes(c) := i;
            c := c + 1;
        END IF;
        i := i + 1;
    END LOOP;

    DBMS_OUTPUT.PUT_LINE(primes(primes.COUNT));
    
    i := 0;
    FOR i IN 1..primes.COUNT LOOP
        ossz := ossz + primes(i);
    END LOOP;

    DBMS_OUTPUT.PUT_LINE(ossz);
END;

execute primes(100);

/* 
    Cursor és asszociatív tömb 
    Írjunk meg egy procedúrát, amelyik veszi a dolgozókat ábácé szerinti sorrendben, 
    és minden páratlan sorszámú dolgozó nevét és fizetését beleteszi egy asszociatív tömbbe. 
    A procedúra a végén írja ki a tömb utolsó előtti elemében szereplő nevet és fizetést.
*/

CREATE OR REPLACE PROCEDURE curs_tomb IS
    CURSOR dolgs IS
    SELECT dnev, fizetes
    FROM DOLGOZO
    ORDER BY dnev;

    TYPE dolg_type IS RECORD
    (
        nev DOLGOZO.DNEV%TYPE,
        fiz DOLGOZO.FIZETES%TYPE
    );

    TYPE dolgozok_type IS TABLE OF dolg_type INDEX BY BINARY_INTEGER;

    dolgozok dolgozok_type;
    n BINARY_INTEGER := 0;
    i INTEGER := 0;
BEGIN
    FOR row IN dolgs LOOP
        IF MOD(i, 2) = 0 THEN
            dolgozok(n) := row;
            n := n + 1;
        END IF;
        i := i + 1;
    END LOOP;

    DBMS_OUTPUT.PUT_LINE(dolgozok(dolgozok.COUNT - 1).nev || '-' || dolgozok(dolgozok.COUNT - 1).fiz);
END;

execute curs_tomb();

/*
    Hozzunk létre mind a két adatbázisban (ullman, aramis) egy GYAK9 nevű 
    két oszlopos táblát, aminek mindkét oszlopa VARCHAR2(100) típusú, majd 
    töltsük fel a következő adatokkal (3 sorral).
    Az első oszlopba kerüljön be a következő osztályok neve: 'ACCOUNTING', RESEARCH', 'SALES',
    a második oszlopba pedig az adott osztályon előforduló foglalkozások neveiből összefűzött
    karakterlánc, például: 'MANAGER-PRESIDENT-CLERK'.
    Tipp: használják az alábbi get_foglalkozas() nevű függvényt. 
*/

CREATE TABLE GYAK9
(
    osztaly VARCHAR2(100),
    lanc VARCHAR2(100)
);

INSERT INTO GYAK9 (osztaly, lanc)
VALUES('ACCOUNTING', GET_FOGLALKOZAS('ACCOUNTING'));
INSERT INTO GYAK9 (osztaly, lanc)
VALUES('RESEARCH', GET_FOGLALKOZAS('RESEARCH'));
INSERT INTO GYAK9 (osztaly, lanc)
VALUES('SALES', GET_FOGLALKOZAS('SALES'));

COMMIT;

SELECT object_name "TABLE", created FROM user_objects 
WHERE object_type='TABLE' AND object_name LIKE 'GYAK9'
ORDER BY object_name;