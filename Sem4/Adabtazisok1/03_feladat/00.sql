SELECT *
FROM DOLGOZO;

-- 1.  Adjuk meg azon dolgozókat, akik fizetése osztható 15-tel.
SELECT dnev
FROM DOLGOZO
WHERE MOD(fizetes, 15) = 0;

-- 2.  Kik azok a dolgozók, akik 1982.01.01 után léptek be a céghez?
--    (Aktuális dátumformátumot lásd -> SYSDATE fv.)
SELECT dnev
FROM DOLGOZO
WHERE belepes > '01-JAN-82';

-- 3.  Adjuk meg azon dolgozókat, akik nevének második betűje 'A'. (használjuk a substr függvényt)
SELECT dnev
FROM DOLGOZO
WHERE SUBSTR(dnev, 2, 1) = 'A';

-- 4.  Adjuk meg azon dolgozókat, akik nevében van legalább két 'L' betű. (használjuk az instr függvényt)
SELECT dnev
FROM DOLGOZO
WHERE INSTR(dnev, 'L') > 0
AND INSTR(SUBSTR(dnev, INSTR(dnev, 'L') + 1, LENGTH(dnev)), 'L') > 0;

-- 5.  Adjuk meg a dolgozók nevének utolsó három betűjét. (substr fv.)
SELECT SUBSTR(dnev, LENGTH(dnev) - 2, LENGTH(dnev))
FROM DOLGOZO;

-- 6.  Adjuk meg azon dolgozókat, akik nevének utolsó előtti betűje 'T'. (substr fv.)
SELECT dnev
FROM DOLGOZO
WHERE SUBSTR(dnev, LENGTH(dnev) - 1, 1) = 'T';

-- 7.  Adjuk meg a dolgozók fizetéseinek négyzetgyökét két tizedesre, és ennek egészrészét. (round, sqrt, trunc fv-ek)
SELECT dnev, TRUNC(SQRT(fizetes), 2)
FROM DOLGOZO;

-- 8.  Adjuk meg, hogy hány napja dolgozik a cégnél ADAMS és milyen hónapban lépett be. (dátumaritmetika + dátum függvények)
SELECT MONTHS_BETWEEN(SYSDATE, belepes) / 1, TO_CHAR(belepes, 'MONTH')
FROM DOLGOZO
WHERE dnev = 'ADAMS';

-- 9.  Adjuk meg azokat a dolgozókat, akik keddi napon léptek be. (to_char fv.)
--    (Vigyázzunk a visszaadott értékkel, és annak hosszával!)
SELECT dnev
FROM DOLGOZO
WHERE TO_CHAR(belepes, 'DY') = 'TUE';

-- 10. Adjuk meg azokat a (név, főnök) párokat, ahol a két ember neve ugyanannyi betűből áll. (length fv.)
SELECT d1.dnev, d2.dnev
FROM DOLGOZO d1, DOLGOZO d2
WHERE d1.fonoke = d2.dkod
AND LENGTH(d1.dnev) = LENGTH(d2.dnev);

-- 11. Adjuk meg azon dolgozókat, akik az 1-es fizetési kategóriába tartoznak.
SELECT *
FROM FIZ_KATEGORIA;

SELECT *
FROM DOLGOZO;

SELECT DISTINCT dnev, fizetes
FROM DOLGOZO, FIZ_KATEGORIA
WHERE also <= fizetes
AND fizetes <= felso
AND kategoria = 1;

-- 12. Adjuk meg azon dolgozókat, akiknek a fizetési kategóriája páros szám. (mod() függvény)
SELECT DISTINCT dnev, fizetes, also, felso, kategoria
FROM DOLGOZO, FIZ_KATEGORIA
WHERE also <= fizetes
AND fizetes <= felso
AND MOD(kategoria, 2) = 0;

-- 13. Adjuk meg, hogy hány nap volt KING és JONES belépési dátuma között?
SELECT MONTHS_BETWEEN(d1.belepes, d2.belepes)
FROM DOLGOZO d1, DOLGOZO d2
WHERE d1.dnev = 'KING'
AND d2.dnev = 'JONES';

-- 14. Adjuk meg, hogy milyen napra esett KING belépési dátuma hónapjának utolsó napja. (last_day() függvény)
SELECT TO_CHAR(LAST_DAY(belepes), 'DY')
FROM DOLGOZO
WHERE dnev = 'KING';

-- 15. Adjuk meg, hogy milyen napra esett KING belépési dátuma hónapjának első napja. (trunc fv. dátumra)
SELECT TO_CHAR(TRUNC(belepes, 'MM'), 'DY')
FROM DOLGOZO
WHERE dnev = 'KING';

-- 16. Adjuk meg azon dolgozók nevét, akik osztályának nevében van 'C' betű és fizetési kategóriájuk >=4.
SELECT DISTINCT *
FROM DOLGOZO NATURAL JOIN OSZTALY, FIZ_KATEGORIA
WHERE INSTR(onev, 'C') > 0
AND kategoria >= 4
AND also <= fizetes
AND fizetes <= felso;
