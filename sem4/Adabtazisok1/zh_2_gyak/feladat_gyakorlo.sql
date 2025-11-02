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
SELECT DISTINCT c.cnev
FROM CIKK c
JOIN SZALLIT sz
ON c.ckod = sz.ckod
GROUP BY c.cnev
HAVING COUNT(DISTINCT sz.pkod) >= 1 
AND COUNT(DISTINCT sz.pkod) < (
    SELECT COUNT(*)
    FROM PROJEKT
);

-- Adjuk meg azon cikkek kódját és nevét, amelyeket kevesebb mint 6 projekthez szállítanak. [ckod, cnev]
SELECT DISTINCT c.ckod, c.cnev
FROM CIKK c
JOIN SZALLIT sz
ON c.ckod = sz.ckod
GROUP BY c.ckod, c.cnev
HAVING COUNT(DISTINCT sz.pkod) < 6;

-- Adjuk meg azon zöld ('zold') színű cikkek nevét, amelyeket minden projekthez szállítanak. [cnev]
WITH
zoldek AS (
    SELECT *
    FROM CIKK
    WHERE szin = 'zold'
)
SELECT z.cnev
FROM zoldek z
JOIN SZALLIT sz
ON z.ckod = sz.ckod
GROUP BY z.cnev
HAVING COUNT(DISTINCT sz.pkod) = (
    SELECT COUNT(*)
    FROM PROJEKT
);

-- Adjuk meg azon zöld ('zold') színű cikkek nevét, amelyet valamelyik projekthez nem szállítanak. [cnev]
WITH
zoldek AS (
    SELECT *
    FROM CIKK
    WHERE szin = 'zold'
)
SELECT z.cnev
FROM zoldek z
JOIN SZALLIT sz
ON z.ckod = sz.ckod
GROUP BY z.cnev
HAVING COUNT(DISTINCT sz.pkod) >= 1
AND COUNT(DISTINCT sz.pkod) < (
    SELECT COUNT(*)
    FROM PROJEKT
);

-- Adjuk meg azon projektek nevét, amelyekhez minden zöld ('zold') színű cikket szállítanak. [pnev]
WITH
zoldek AS (
    SELECT *
    FROM CIKK
    WHERE szin = 'zold'
),
zold_projektek AS (
    SELECT sz.pkod
    FROM zoldek z
    JOIN SZALLIT sz
    ON z.ckod = sz.ckod
    GROUP BY sz.pkod
    HAVING COUNT(DISTINCT z.ckod) = (
        SELECT COUNT(*)
        FROM zoldek
    )
)
SELECT p.pnev
FROM PROJEKT p
JOIN zold_projektek z
ON p.pkod = z.pkod;

-- Adjuk meg azon szállítók nevét és telephelyét, akik valamelyik cikket minden projekthez szállítják. [sznev, telephely]
WITH
projekt_szamok AS (
    SELECT COUNT(DISTINCT pkod) AS pcount
    FROM PROJEKT
),
minden_szallitok AS (
    SELECT sz.szkod, c.ckod
    FROM CIKK c
    JOIN SZALLIT sz
    ON c.ckod = sz.ckod
    GROUP BY sz.szkod, c.ckod
    HAVING COUNT(DISTINCT sz.pkod) = (SELECT pcount FROM projekt_szamok)
)
SELECT sz.sznev, sz.telephely
FROM SZALLITO sz
JOIN minden_szallitok m
ON sz.szkod = m.szkod;

-- Adjuk meg azon szállítók nevét és telephelyét, akik valamelyik cikket minden pécsi ('Pecs') projekthez szállítják. [sznev, telephely]
WITH
pecsi_projektek AS (
    SELECT COUNT(DISTINCT pkod) AS pcount
    FROM PROJEKT
    WHERE helyszin = 'Pecs'
),
pecsi_szallitasok AS (
    SELECT *
    FROM SZALLIT sz
    WHERE sz.pkod IN (
        SELECT p.pkod
        FROM PROJEKT p
        WHERE p.helyszin = 'Pecs'
    )
),
minden_pecsi_szallitok AS (
    SELECT sz.szkod, c.ckod
    FROM pecsi_szallitasok sz
    JOIN CIKK c
    ON sz.ckod = c.ckod
    GROUP BY sz.szkod, c.ckod
    HAVING COUNT(DISTINCT sz.pkod) = (SELECT pcount FROM pecsi_projektek)
)
SELECT sz.sznev, sz.telephely
FROM SZALLITO sz
JOIN minden_pecsi_szallitok m
ON sz.szkod = m.szkod;

-- Adjuk meg azon szállítók nevét és telephelyét, akik valamelyik kék ('kek') cikket minden projekthez szállítják. [sznev, telephely]
WITH
minden_projekt AS (
    SELECT COUNT(DISTINCT pkod) AS pcount
    FROM PROJEKT
),
kek_cikk_szallitasok AS (
    SELECT c.ckod, sz.pkod, sz.szkod
    FROM CIKK c
    JOIN SZALLIT sz
    ON c.ckod = sz.ckod
    WHERE c.szin = 'kek'
),
minden_kek_cikk_szallitok AS (
    SELECT k.szkod, k.ckod
    FROM kek_cikk_szallitasok k
    GROUP BY k.szkod, k.ckod
    HAVING COUNT(DISTINCT k.pkod) = (SELECT pcount FROM minden_projekt)
)
SELECT sz.sznev, sz.telephely
FROM minden_kek_cikk_szallitok m
JOIN SZALLITO sz
ON sz.szkod = m.szkod;

-- Adjuk meg azon szállítók nevét, akik minden cikket szállítanak minden projekthez. [sznev]
-- 2 megoldasom van:
-- 1.: Itt azt nezem, hogy az adott szallito minden cikket es minden projekthez szallit (ezek lehetnek fuggetlenek most)
WITH
minden_projekt AS (
    SELECT COUNT(DISTINCT pkod) as pcount
    FROM PROJEKT
),
minden_cikk AS (
    SELECT COUNT(DISTINCT ckod) as ccount
    FROM CIKK
),
mindent_szallitok AS (
    SELECT sz.szkod
    FROM SZALLIT sz
    GROUP BY sz.szkod
    HAVING COUNT(DISTINCT sz.ckod) = (SELECT ccount FROM minden_cikk)
    AND COUNT(DISTINCT sz.pkod) = (SELECT pcount FROM minden_projekt)
)
SELECT sz.sznev
FROM SZALLITO sz
JOIN mindent_szallitok m
ON sz.szkod = m.szkod;

-- 2.: Itt azt nezem, hogy az adott szallito az adott projekthez minden cikket szallit es ellenorzom, hogy 
--     az adott szallito minden projekthez szallit (ez sztem igy nem jo, de mar leszarom)
WITH
minden_projekt AS (
    SELECT COUNT(DISTINCT pkod) as pcount
    FROM PROJEKT
),
minden_cikk AS (
    SELECT COUNT(DISTINCT ckod) as ccount
    FROM CIKK
),
mindent_szallitok AS (
    SELECT sz.szkod, sz.pkod
    FROM SZALLIT sz
    GROUP BY sz.szkod, sz.pkod
    HAVING COUNT(DISTINCT sz.ckod) = (SELECT ccount FROM minden_cikk)
    AND EXISTS (
        SELECT 1
        FROM SZALLIT sz2
        WHERE sz2.szkod = sz.szkod
        GROUP BY sz2.szkod
        HAVING COUNT(DISTINCT sz2.pkod) = (SELECT pcount FROM minden_projekt)
    )
)
SELECT sz.sznev
FROM SZALLITO sz
JOIN mindent_szallitok m
ON sz.szkod = m.szkod;