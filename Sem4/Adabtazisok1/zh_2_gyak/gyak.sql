-- Adjuk meg azon szállítók nevét, akik minden kék ('kek') cikket szállítanak minden projekthez. [sznev]
WITH kek_cikkek AS (
    SELECT DISTINCT ckod
    FROM CIKK
    WHERE szin = 'kek'
),
projektek AS (
    SELECT DISTINCT pkod
    FROM PROJEKT
),
szukseges_kombinaciok AS (
    SELECT p.pkod, c.ckod
    FROM projektek p
    CROSS JOIN kek_cikkek c
),
szallito_kombinaciok AS (
    SELECT sz.szkod, sz.pkod, sz.ckod
    FROM SZALLIT sz
    JOIN CIKK c ON sz.ckod = c.ckod
    WHERE c.szin = 'kek'
),
megfelelo_szallitok AS (
    SELECT sk.szkod
    FROM szallito_kombinaciok sk
    JOIN szukseges_kombinaciok szuk
    ON sk.pkod = szuk.pkod AND sk.ckod = szuk.ckod
    GROUP BY sk.szkod
    HAVING COUNT(*) = (SELECT COUNT(*) FROM szukseges_kombinaciok)
)
SELECT sz.sznev
FROM SZALLITO sz
JOIN megfelelo_szallitok m ON sz.szkod = m.szkod;

/* 
    SELECT ... INTO v1
    Írjunk meg egy függvényt, amelyik visszaadja egy adott fizetési kategóriába tartozó
    dolgozók átlagfizetését.
*/

CREATE OR REPLACE FUNCTION kat_atlag(n integer) RETURN number IS
    v_atlag NUMBER;
BEGIN
    SELECT ROUND(AVG(d.fizetes), 2)
    INTO v_atlag
    FROM DOLGOZO d
    CROSS JOIN FIZ_KATEGORIA f
    WHERE d.fizetes BETWEEN f.also AND f.felso
    AND f.kategoria = n;

    RETURN v_atlag;
END;

SELECT kat_atlag(2) FROM dual;

/* 
    SELECT ... INTO v1, v2
    Írjunk meg egy procedúrát, amelyik kiírja azon dolgozók számát és átlagfizetését,
    akiknek a belépési dátuma a paraméterül megadott nevű napon (pl. 'Hétfő') volt.
*/
CREATE OR REPLACE PROCEDURE nap_atl(d VARCHAR2) IS
    v_count INTEGER := 0;
    v_avg NUMBER := 0;
BEGIN
    SELECT COUNT(DISTINCT d.dnev), ROUND(AVG(d.fizetes), 2)
    INTO v_count, v_avg
    FROM DOLGOZO d
    WHERE TO_CHAR(belepes, 'DAY', 'NLS_DATE_LANGUAGE=HUNGARIAN') = UPPER(d);

    DBMS_OUTPUT.PUT_LINE(v_count || ', ' || v_avg);
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
    CURSOR valasztott_dolgozok IS
    SELECT *
    FROM DOLGOZO d
    CROSS JOIN FIZ_KATEGORIA f
    WHERE d.fizetes BETWEEN f.also AND f.felso
    AND f.kategoria = p_kategoria;

    v_avg NUMBER := 0;
BEGIN
    FOR row IN valasztott_dolgozok LOOP
        UPDATE DOLGOZO d
        SET d.fizetes = d.fizetes + (
            SELECT MIN(d2.fizetes)
            FROM DOLGOZO d2
            WHERE d.oazon = d2.oazon
        );
    END LOOP;

    SELECT ROUND(AVG(d.fizetes), 2)
    INTO v_avg
    FROM DOLGOZO d;

    DBMS_OUTPUT.PUT_LINE(v_avg);

    ROLLBACK;
END;

execute kat_novel(2);

/* 
    Cursor (több soros SELECT)
    Írjunk meg egy procedúrát, amelyik veszi a paraméterül megadott osztály dolgozóit ábécé 
    szerinti sorrendben, és kiírja a foglalkozásaikat egy karakterláncban összefűzve.
*/
CREATE OR REPLACE PROCEDURE print_foglalkozas(o_nev varchar2) IS
    CURSOR foglalkozasok IS
    SELECT *
    FROM DOLGOZO d
    JOIN OSZTALY o
    ON d.oazon = o.oazon
    WHERE o.onev = o_nev
    ORDER BY d.dnev;

    v_str VARCHAR2(100) := NULL;
    foglalkozas VARCHAR2(100);
BEGIN
    FOR row IN foglalkozasok LOOP
        foglalkozas := row.foglalkozas;

        IF v_str IS NOT NULL THEN
            v_str := v_str || '-' || foglalkozas;
        ELSE
            v_str := v_str || foglalkozas;
        END IF;
    END LOOP;

    DBMS_OUTPUT.PUT_LINE(v_str);
END;

execute print_foglalkozas('ACCOUNTING');  -- példa output: MANAGER-PRESIDENT-CLERK

/* 
    Asszociatív tömb  --> TABLE OF ... INDEX BY ...
    Írjunk meg egy procedúrát, amelyik veszi az első n prímszámot (1. prímszám: 2, 2. prímszám: 3, stb.)
    és beleteszi azokat egy asszociatív tömbbe. A procedúra a végén írja ki a tömb utolsó elemét és a
    prímszámok összegét.
*/
CREATE OR REPLACE PROCEDURE primes(n INTEGER) IS
    TYPE prime_array_type IS TABLE OF NUMBER INDEX BY BINARY_INTEGER;
    primes prime_array_type;
    idx BINARY_INTEGER := 1;
    primes_sum NUMBER := 0;
BEGIN
    FOR i IN 1..n LOOP
        IF PRIME(i) = 1 THEN
            primes(idx) := i;
            idx := idx + 1;
        END IF;
    END LOOP;

    FOR i IN 1..idx - 1 LOOP
        primes_sum := primes_sum + primes(i);
    END LOOP;

    DBMS_OUTPUT.PUT_LINE(primes(primes.COUNT) || ', ' || primes_sum);
END;

execute primes(100);

