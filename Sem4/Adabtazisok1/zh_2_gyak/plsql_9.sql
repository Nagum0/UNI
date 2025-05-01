SET SERVEROUTPUT ON;

/*  
    Összetettebb feladat, amely kis gondolkodással egyszerűsíthető
    Írjunk meg egy procedúrát, amely a következők szerint módosítja egyes dolgozók fizetését.
    Vegyük minden osztályon a legrégebben belépett dolgozót, és növeljük meg a fizetését
    annyiszor 100-zal, ahány dolgozó még rajta kívül az osztályon dolgozik.
    (Ha több legrégebben belépett dolgozó is van, akkor mindegyikük fizetését növeljük meg.)
    A módosítások után a program írja ki az új átlagfizetést két tizedesre kerekítve. 
    A procedúra a kiírás után adjon ki egy ROLLBACK utasítást, hogy megmaradjanak az eredeti fizetések,
    így a procedúrát többször is futtatni tudják.
*/

CREATE OR REPLACE PROCEDURE fiz_mod IS
    CURSOR old_emp IS
    SELECT dnev, oazon
    FROM DOLGOZO
    WHERE belepes = (
        SELECT MIN(belepes)
        FROM DOLGOZO d2
        WHERE d2.oazon = oazon
    );

    v_atlag NUMBER := 0;
BEGIN
    FOR row IN old_emp LOOP
        UPDATE DOLGOZO
        SET fizetes = fizetes + (100 * (
            SELECT COUNT(*) - 1
            FROM DOLGOZO d2
            WHERE d2.oazon = row.oazon
        ))
        WHERE dnev = row.dnev
        AND oazon = row.oazon;
    END LOOP;

    SELECT TRUNC(AVG(fizetes), 2) 
    INTO v_atlag
    FROM DOLGOZO;

    DBMS_OUTPUT.PUT_LINE(v_atlag);

    ROLLBACK;
END;

SELECT TRUNC(AVG(fizetes), 2) 
FROM DOLGOZO;

execute fiz_mod();

/* 
    Módosítás kurzorral
    Írjunk meg egy procedúrát, amelyik módosítja a paraméterében megadott osztályon a fizetéseket, és 
    kiírja a dolgozó nevét és új fizetését.  A módosítás mindenki fizetéséhez adjon hozzá n*10 ezret, 
    ahol n a dolgozó nevében levő magánhangzók száma (A, E, I, O, U).
    A procedúra a kiírás után adjon ki egy ROLLBACK utasítást, hogy megmaradjanak az eredeti fizetések,
    így a procedúrát többször is futtatni tudják.
*/

CREATE OR REPLACE PROCEDURE fiz_mod2(p_oazon INTEGER) IS
    CURSOR selected_emps IS
    SELECT *
    FROM DOLGOZO
    WHERE oazon = p_oazon;

    n INTEGER := 0;
    v_atlag NUMBER;

    FUNCTION magan_hangzok(p_str VARCHAR2) RETURN INTEGER IS
        i INTEGER;
        c CHAR(1);
        v_count INTEGER := 0;
    BEGIN
        FOR i IN 1..LENGTH(p_str) LOOP
            c := SUBSTR(UPPER(p_str), i, 1);

            IF c = 'A' OR c = 'E' OR c = 'I' OR c = 'O' OR c = 'U' THEN
                v_count := v_count + 1;
            END IF;
        END LOOP;

        RETURN v_count;
    END;
BEGIN
    FOR row IN selected_emps LOOP
        n := magan_hangzok(row.dnev);
        DBMS_OUTPUT.PUT_LINE(row.dnev || ': ' || n);

        UPDATE DOLGOZO
        SET fizetes = fizetes + (n * 10000)
        WHERE dnev = row.dnev;
    END LOOP;

    SELECT TRUNC(AVG(fizetes), 2) 
    INTO v_atlag
    FROM DOLGOZO;

    DBMS_OUTPUT.PUT_LINE(v_atlag);

    ROLLBACK;
END;

execute fiz_mod2(20);

/* 
    Exception
    Írjunk meg egy függvényt, amelyik egy karakteres típusú paraméterben egy dátumot 
    kap a következő formátumban: 'éééé.hh.nn' vagy 'nn.hh.éééé'. 
    A függvény adja vissza a nap nevét, pl. 'kedd'.
    Ha a megadott karakterlánc nem egy érvényes dátum, akkor adja vissza, hogy 'rossz'.
*/

CREATE OR REPLACE FUNCTION nap_nev(p_kar VARCHAR2) RETURN VARCHAR2 IS
    v_date DATE;
    v_name VARCHAR2(10);
BEGIN
    BEGIN
        v_date := TO_DATE(p_kar, 'YYYY.MM.DD');

        EXCEPTION
            WHEN OTHERS THEN
                BEGIN
                    v_date := TO_DATE(p_kar, 'DD.MM.YYYY');

                    EXCEPTION
                        WHEN OTHERS THEN
                            RETURN 'rossz';
                END;
    END;

    RETURN TO_CHAR(v_date, 'DAY', 'NLS_DATE_LANGUAGE=HUNGARIAN');
END;

SELECT nap_nev('2017.05.01'), nap_nev('02.05.2017'), nap_nev('2017.13.13'), nap_nev('x') FROM dual;

/* 
    Exception, SQLCODE
    Írjunk meg egy procedúrát, amelyik a paraméterében kapott számra külön sorokba kiírja 
    annak reciprokát, négyzetgyökét, és faktoriálisát. Ha bármelyik nem értelmezhető vagy
    túlcsordulást okoz, akkor erre a részre írja ki a kapott hibakódot. (SQLCODE).
*/

CREATE OR REPLACE PROCEDURE szamok(n NUMBER) IS
    v_error_code NUMBER;
BEGIN
    -- Reciproka
    BEGIN
        DECLARE
            v_reciproka NUMBER;
        
        BEGIN
            v_reciproka := 1 / n;

            EXCEPTION
                WHEN OTHERS THEN
                    v_error_code := SQLCODE;
                    DBMS_OUTPUT.PUT_LINE(v_error_code);
        END;
    END;

    -- Negyzetgyok
    BEGIN
        DECLARE
            v_sqrt NUMBER;
        
        BEGIN
            v_sqrt := SQRT(n);

            EXCEPTION
                WHEN OTHERS THEN
                    v_error_code := SQLCODE;
                    DBMS_OUTPUT.PUT_LINE(v_error_code);
        END;
    END;

    -- Faktorialis
    BEGIN
        DECLARE
            v_fact NUMBER;
        
        BEGIN
            v_fact := SQRT(n);

            EXCEPTION
                WHEN OTHERS THEN
                    v_error_code := SQLCODE;
                    DBMS_OUTPUT.PUT_LINE(v_error_code);
        END;
    END;
END;

execute szamok(0);
execute szamok(-2);
execute szamok(40);

/*
    Írjunk meg egy függvényt, amelyik visszaadja a paraméterként szereplő '+'-szal 
    elválasztott számok és kifejezések összegét. Ha valamelyik kifejezés nem szám,
    akkor azt az összeadásnál hagyja figyelmen kívül, vagyis 0-nak tekintse.
*/

CREATE OR REPLACE FUNCTION osszeg2(p_char VARCHAR2) RETURN NUMBER IS
    TYPE ns_type IS TABLE OF NUMBER INDEX BY BINARY_INTEGER;
    ns ns_type;
    idx BINARY_INTEGER := 1;
    c CHAR(1);
    strt BINARY_INTEGER := 1;
    len BINARY_INTEGER := 1;
    s INTEGER := 0;
    segment VARCHAR2(100);
BEGIN
    FOR i IN 1..LENGTH(p_char) LOOP
        c := SUBSTR(p_char, i, 1);

        IF c = '+' THEN
            segment := TRIM(SUBSTR(p_char, strt, len - 1));
            BEGIN
                ns(idx) := TO_NUMBER(segment);
            EXCEPTION
                WHEN OTHERS THEN
                    ns(idx) := 0;
            END;
            idx := idx + 1;
            strt := i + 1;
            len := 1;
        ELSE
            len := len + 1;
        END IF;
    END LOOP;

    IF strt <= LENGTH(p_char) THEN
        segment := TRIM(SUBSTR(p_char, strt));
        BEGIN
            ns(idx) := TO_NUMBER(segment);
        EXCEPTION
            WHEN OTHERS THEN
                ns(idx) := 0;
        END;
    END IF;

    FOR i IN 1..ns.COUNT LOOP
        s := s + ns(i);
    END LOOP;

    RETURN s;
END;

SELECT osszeg2('1 + 1 + 1') FROM dual;

/*
    Hozzunk létre mind a két adatbázisban (ullman, aramis) egy GYAK10 nevű 
    három oszlopos táblát, amely azoknak a dolgozóknak a nevét, belépési dátumát, és a belépési dátumuk 
    napjának nevét (pl. hétfő) tartalmazza, akiknek a fizetése nagyobb az összes dolgozó átlagfizetésénél.
    Tipp: használják az alábbi nap_nev() nevű függvényt.
*/

CREATE TABLE GYAK10 AS
SELECT dnev, belepes, NAP_NEV(belepes) AS belepes_nap
FROM DOLGOZO
WHERE fizetes >= (
    SELECT ROUND(AVG(fizetes), 2)
    FROM DOLGOZO
);

-- 1: 108, 29/29, 3.6
-- 2: 96, 28/33 3.2
-- Korrigalt: 