-- Mekkora a maximalis fizetes a dolgozok kozott?
SELECT MAX(fizetes)
FROM DOLGOZO;

-- Mennyi a dolgozok osszfizetese?
SELECT SUM(fizetes)
FROM DOLGOZO;

-- Mennyi a 20-as osztalyon az osszfizetes es az atlagfizetés? (Atlag, Ossz)
SELECT 
SUM(fizetes) AS Ossz,
TRUNC(AVG(fizetes), 2) AS Atlag
FROM DOLGOZO
WHERE oazon = 20;

-- Adjuk meg, hogy hany kulonbozo foglalkozas fordul elo a dolgozok kozott.
SELECT COUNT(DISTINCT foglalkozas)
FROM DOLGOZO;

-- Hany olyan dolgozo van, akinek a fizetese > 2000?
SELECT COUNT(*)
FROM DOLGOZO
WHERE fizetes > 2000;

-- Adjuk meg osztalyonkent az atlagfizetest (oazon, atl_fiz).
SELECT oazon, TRUNC(AVG(fizetes), 2)
FROM DOLGOZO 
GROUP BY oazon;

-- Adjuk meg osztalyonkent a telephelyet es az atlagfizetest (oazon, telephely, atl_fiz).
SELECT oazon, telephely, TRUNC(AVG(fizetes), 2)
FROM DOLGOZO NATURAL JOIN OSZTALY
GROUP BY oazon, telephely;

-- Adjuk meg, hogy az egyes osztalyokon hany ember dolgozik. (oazon, mennyi)
SELECT oazon, COUNT(*) AS mennyi
FROM DOLGOZO
GROUP BY oazon;

-- Adjuk meg azokra az osztalyokra az atlagfizetast, ahol ez nagyobb mint 2000. (oazon, atlag)
SELECT oazon, TRUNC(AVG(fizetes), 2)
FROM DOLGOZO
GROUP BY oazon
HAVING AVG(fizetes) > 2000;

-- Adjuk meg az atlagfizetest azokon az osztalyokon, ahol legalabb 4-en dolgoznak (oazon, atlag)
SELECT oazon, TRUNC(AVG(fizetes), 2)
FROM DOLGOZO
GROUP BY oazon
HAVING COUNT(*) >= 4;

-- Adjuk meg az atlagfizetest es telephelyet azokon az osztalyokon, ahol legalabb 4-en dolgoznak. (oazon, telephely, atlag)
SELECT oazon, telephely, TRUNC(AVG(fizetes), 2)
FROM DOLGOZO NATURAL JOIN OSZTALY
GROUP BY oazon, telephely
HAVING COUNT(*) >= 4;

-- Adjuk meg azon osztalyok nevet es telephelyet, ahol az atlagfizetes nagyobb mint 2000. (onev, telephely)
SELECT onev, telephely
FROM DOLGOZO NATURAL JOIN OSZTALY
GROUP BY onev, telephely
HAVING AVG(fizetes) > 2000;

-- Adjuk meg azokat a fizetesi kategoriakat, amelybe pontosan 3 dolgozo fizetese esik.
SELECT kategoria
FROM DOLGOZO, FIZ_KATEGORIA
WHERE fizetes BETWEEN also AND felso
GROUP BY kategoria
HAVING COUNT(*) = 3;

-- Adjuk meg azokat a fizetesi kategoriakat, amelyekbe eso dolgozok mindannyian ugyanazon az osztalyon dolgoznak. (kategoria)
SELECT kategoria
FROM DOLGOZO, FIZ_KATEGORIA
WHERE fizetes BETWEEN also AND felso
GROUP BY kategoria
HAVING COUNT(DISTINCT oazon) = 1;

-- Adjuk meg azon osztalyok nevet es telephelyet, amelyeknek van 1-es fizetesi kategoriaju dolgozoja. (onev, telephely)
SELECT onev, telephely
FROM DOLGOZO NATURAL JOIN OSZTALY, FIZ_KATEGORIA
WHERE (fizetes BETWEEN also AND felso)
AND kategoria = 1;

-- Adjuk meg azon osztalyok nevet es telephelyet, amelyeknek legalabb 2 fo 1-es fizetesi kategoriaju dolgozoja van.
SELECT onev, telephely, dnev, fizetes, kategoria
FROM DOLGOZO NATURAL JOIN OSZTALY, FIZ_KATEGORIA
WHERE fizetes BETWEEN also AND felso
GROUP BY onev, telephely, dnev, fizetes, kategoria;

SELECT onev, telephely
FROM DOLGOZO NATURAL JOIN OSZTALY, FIZ_KATEGORIA
WHERE (fizetes BETWEEN also AND felso)
AND kategoria = 1
GROUP BY kategoria, telephely, onev
HAVING COUNT(*) >= 2;

-- Keszitsunk listat a paros es paratlan azonositoju (dkod) dolgozok szamarol. (paritas, szam)
SELECT 
    CASE
        WHEN MOD(dkod, 2) = 0 THEN 'paros'
        ELSE 'paratlan'
    END AS paritas,
    COUNT(*) AS szam
FROM DOLGOZO
GROUP BY
    CASE
        WHEN MOD(dkod, 2) = 0 THEN 'paros'
        ELSE 'paratlan'
    END;

SELECT 
    CASE
        WHEN MOD(dkod, 2) = 0 THEN 'paros'
        ELSE 'paratlan'
    END AS paritas,
    dkod
FROM DOLGOZO;

-- Listazzuk ki foglalkozasonkant a dolgozak szamat, atlagfizetasat (kerekitve) numerikusan as grafikusan is.
-- 200-ankent jelenitsunk meg egy '#'-ot. (foglalkozas, szam, atlag, grafika)
SELECT
    foglalkozas,
    COUNT(*) AS szam,
    FLOOR(AVG(fizetes)) AS atlag,
    RPAD('#', FLOOR(AVG(fizetes)) / 200, '#') AS grafika
FROM DOLGOZO
GROUP BY foglalkozas;
