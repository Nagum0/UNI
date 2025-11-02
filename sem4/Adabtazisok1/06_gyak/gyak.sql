-- SQL-ben adjuk meg, visszaadja azokat a fizetesi kategoriakat amelybe pontosan 3 dolgozo fizetese esik
SELECT kategoria
FROM Dolgozo, Fiz_kategoria
WHERE also <= fizetes AND fizetes <= felso
GROUP BY kategoria
HAVING COUNT(*) = 3;

-- ZH-ban megadni, hogy min futott es a kimenet elso 3 sorat

-- Adjuk meg osztályonként a maximális fizetésû dolgozókat: oazon, dnév, fizetés
SELECT d.oazon, d.dnev, d.fizetes
FROM DOLGOZO d, OSZTALY o
WHERE d.oazon = o.oazon AND d.fizetes = (
    SELECT MAX(fizetes)
    FROM DOLGOZO
    WHERE oazon = d.oazon
    GROUP BY oazon
);

SELECT d.oazon, dnev, fizetes
FROM DOLGOZO d, (
    SELECT oazon, MAX(fizetes) mf 
    FROM DOLGOZO 
    GROUP BY oazon
) tmp
WHERE d.oazon = tmp.oazon AND d.fizetes = mf;

-- Adjuk meg azoknak a nevét, akik minden gyümölcsöt szeretnek. (név)
SELECT nev
FROM SZERET
GROUP BY nev
HAVING COUNT(*) = (
    SELECT COUNT(DISTINCT gyumolcs) 
    FROM SZERET
);

-- Adjuk meg a fonokoket
SELECT DISTINCT d1.dnev
FROM DOLGOZO d1, DOLGOZO d2
WHERE d1.dkod = d2.fonoke;

-- Adjuk meg a legrosszabbul keresõ fõnök fizetését és fizetési kategóriáját. (Fizetés, Kategória)
SELECT minf, kategoria
FROM FIZ_KATEGORIA, (
    SELECT MIN(fizetes) minf
    FROM DOLGOZO
    WHERE dkod IN (
        SELECT fonoke
        FROM DOLGOZO
    )
)
WHERE minf BETWEEN also AND felso;

-- WITH utasitas
WITH
deptCosts AS (
    SELECT onev, SUM(fizetes) AS fizTotal
    FROM DOLGOZO NATURAL JOIN OSZTALY
    GROUP BY onev
),
avgCost AS (
    SELECT TRUNC(AVG(fizTotal), 2) AS fizAtlag
    FROM deptCosts
)
SELECT *
FROM deptCosts
WHERE fizTotal > (
    SELECT fizAtlag
    FROM avgCost
);

-- HF: Feladat 9 FROM feladat5.pdf
WITH 
osztAtlagok AS (
    SELECT oazon, TRUNC(AVG(fizetes), 2) oszt_atlag
    FROM dolgozo
    GROUP BY oazon
),
osszAtlag AS (
    SELECT AVG(fizetes) atlag
    FROM DOLGOZO
)
SELECT onev, oszt_atlag, TRUNC(atlag, 2), oszt_atlag - atlag
FROM osztAtlagok, osszAtlag, OSZTALY o
WHERE osztAtlagok.oazon = o.oazon;

-- KOTELEZO FELADAT
-- STEP 1: Clone nikovits.osztaly
CREATE TABLE GYAK6 AS 
SELECT * FROM OSZTALY;

SELECT *
FROM GYAK6;

-- STEP 2: Delete the items from the table
DELETE
FROM GYAK6
WHERE oazon IN (
    SELECT DISTINCT oazon
    FROM GYAK6 NATURAL JOIN DOLGOZO, FIZ_KATEGORIA
    WHERE fizetes BETWEEN also AND felso
    AND kategoria = 2
);

-- STEP 3: Commit
COMMIT;
