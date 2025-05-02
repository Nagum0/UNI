-- NIKOVITS.CIKK     (ckod, cnev, szin, suly)              -- cikkek kódja, neve, színe, súlya
-- NIKOVITS.PROJEKT  (pkod, pnev, helyszin)                -- projektek kódja, neve, helyszíne
-- NIKOVITS.SZALLITO (szkod, sznev, statusz, telephely)    -- szállítók kódja, neve, státusza, telephelye
-- NIKOVITS.SZALLIT  (szkod, ckod, pkod, mennyiseg, datum) -- a szallító a cikket a projekthez szállítja

-- Adjuk meg azon cikkek kódját és nevét, amelyeket valamelyik pécsi ('Pecs') szállító szállít. [ckod, cnev]
SELECT ckod, cnev
FROM CIKK NATURAL JOIN SZALLIT
WHERE szkod IN (
    SELECT szkod
    FROM SZALLITO
    WHERE telephely = 'Pecs'
);

-- Adjuk meg, hogy hány ilyen cikk van. [darab]
SELECT COUNT(DISTINCT ckod) AS darab
FROM CIKK NATURAL JOIN SZALLIT
WHERE szkod IN (
    SELECT szkod
    FROM SZALLITO
    WHERE telephely = 'Pecs'
);

-- Adjuk meg azon cikkek kódját és nevét, amelyeket egyik pécsi szállító sem szállít. [ckod, cnev]
SELECT ckod, cnev
FROM CIKK
MINUS
SELECT ckod, cnev
FROM CIKK NATURAL JOIN SZALLIT
WHERE szkod IN (
    SELECT szkod
    FROM SZALLITO
    WHERE telephely = 'Pecs'
);

-- Adjuk meg, hogy hány ilyen cikk van. [darab]
WITH
nincs_pecs AS (
    SELECT ckod, cnev
    FROM CIKK
    MINUS
    SELECT ckod, cnev
    FROM CIKK NATURAL JOIN SZALLIT
    WHERE szkod IN (
        SELECT szkod
        FROM SZALLITO
        WHERE telephely = 'Pecs'
    )
)
SELECT COUNT(DISTINCT ckod)
FROM nincs_pecs;

-- Adjuk meg azon szállítók nevét, akiknek a státusza 10-nél nagyobb és budapesti projektbe szállítanak szék nevű cikket. ('Budapest', 'szek')  [sznev]
SELECT DISTINCT sznev
FROM SZALLITO NATURAL JOIN SZALLIT
WHERE statusz > 10 
AND EXISTS (
    SELECT 1
    FROM PROJEKT proj
    WHERE proj.pkod = pkod
    AND proj.helyszin = 'Budapest'
)
AND EXISTS (
    SELECT 1
    FROM CIKK cs
    WHERE cs.ckod = ckod
    AND cs.cnev = 'szek'
);

-- Adjuk meg azon projektek kódját, amelyekhez szállítanak kék cikket. ('kek')  [pkod]
SELECT p.pkod
FROM PROJEKT p
JOIN SZALLIT sz
ON p.pkod = sz.pkod
WHERE EXISTS (
    SELECT 1
    FROM CIKK c
    WHERE c.ckod = sz.ckod
    AND c.szin = 'kek'
);

-- Adjuk meg azon projektek kódját és nevét, amelyekhez szállítanak kék cikket. [pkod, pnev]
SELECT p.pkod, p.pnev
FROM PROJEKT p
JOIN SZALLIT sz
ON p.pkod = sz.pkod
WHERE EXISTS (
    SELECT 1
    FROM CIKK c
    WHERE c.ckod = sz.ckod
    AND c.szin = 'kek'
);

-- Adjuk meg azon projektek kódját és nevét, amelyekhez nem szállítanak kék cikket. [pkod, pnev]
SELECT p.pkod, p.pnev
FROM PROJEKT p
JOIN SZALLIT sz
ON p.pkod = sz.pkod
MINUS
SELECT p.pkod, p.pnev
FROM PROJEKT p
JOIN SZALLIT sz
ON p.pkod = sz.pkod
WHERE EXISTS (
    SELECT 1
    FROM CIKK c
    WHERE c.ckod = sz.ckod
    AND c.szin = 'kek'
);

-- Adjuk meg azon cikkek kódját, amelyeket szállítanak valahova. [ckod]
SELECT ckod
FROM CIKK
INTERSECT
SELECT ckod
FROM SZALLIT;

-- Adjuk meg, hogy hány ilyen cikk van. [darab]
WITH
szallitanak AS (
    SELECT ckod
    FROM CIKK
    INTERSECT
    SELECT ckod
    FROM SZALLIT
)
SELECT COUNT(DISTINCT ckod)
FROM szallitanak;

-- Adjuk meg azon cikkek kódját, amelyeket nem szállítanak sehova. [ckod]
SELECT ckod
FROM CIKK
MINUS
SELECT ckod
FROM SZALLIT;

-- Adjuk meg azon cikkek kódját és nevét, amelyeket sehova nem szállítanak.  [ckod, cnev]
WITH
nem_szallitanak AS (
    SELECT ckod
    FROM CIKK
    MINUS
    SELECT ckod
    FROM SZALLIT
)
SELECT c.ckod, c.cnev
FROM CIKK c
JOIN nem_szallitanak n
ON c.ckod = n.ckod;

-- Adjuk meg azon kék ('kek') cikkek kódját, amelyeket szállítanak valahova. [ckod]
SELECT ckod
FROM CIKK
WHERE szin = 'kek'
AND ckod IN (
    SELECT ckod
    FROM CIKK
    INTERSECT
    SELECT ckod
    FROM SZALLIT
);

-- Adjuk meg azon piros színű cikkek kódját, amelyeket sehova nem szállítanak. [ckod]
SELECT ckod
FROM CIKK
WHERE szin = 'piros'
AND ckod IN (
    SELECT ckod
    FROM CIKK
    MINUS
    SELECT ckod
    FROM SZALLIT
);

-- Adjuk meg azon cikkek nevét, amelyeket minden projekthez szállítanak. [cnev]
SELECT c.cnev
FROM SZALLIT sz
JOIN CIKK c
ON sz.ckod = c.ckod
GROUP BY c.cnev
HAVING COUNT(DISTINCT sz.pkod) = (
    SELECT COUNT(DISTINCT pkod)
    FROM PROJEKT
);

-- Melyik cikket hány különböző projekthez szállítják? [ckod, cnev, darab]
SELECT c.cnev, c.ckod, COUNT(DISTINCT sz.pkod) AS darab
FROM SZALLIT sz
JOIN CIKK c
ON sz.ckod = c.ckod
GROUP BY c.ckod, c.cnev;

-- Melyik cikket szállítják a legtöbb projekthez? (Leolvassuk a rendezett listából) [ckod, cnev]
-- Majd adjuk meg leolvasás nélkül felső-N elemzés segítségével. [ckod, cnev]
WITH
darabok AS (
    SELECT c.cnev, c.ckod, COUNT(DISTINCT sz.pkod) AS darab
    FROM SZALLIT sz
    JOIN CIKK c
    ON sz.ckod = c.ckod
    GROUP BY c.ckod, c.cnev
)
SELECT c.ckod, c.cnev
FROM CIKK c
JOIN darabok d
ON c.ckod = d.ckod
WHERE d.darab = (
    SELECT MAX(darab)
    FROM darabok
);

-- Adjuk meg azon cikkek nevét, amelyeket valamelyik projekthez nem szállítanak. [cnev]
-- ...