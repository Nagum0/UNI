SELECT * FROM Dolgozo;
SELECT * FROM Fiz_kategoria;
SELECT * FROM Osztaly;
SELECT * FROM Szeret;

-- FELADATOK 1

-- Adjuk meg azoknak a nevét és kétszeres fizetését, akik a 10-es osztályon dolgoznak.
-- π dnev, fizetes * 2 → fiz σ oazon = 10 Dolgozo
SELECT dnev, fizetes * 2 AS fiz
FROM Dolgozo
WHERE oazon = 10;

-- Kik azok a dolgozók, akik 1982.01.01 után léptek be a céghez?
-- π dnev σ belepes > 1982-01-01 Dolgozo
SELECT dnev
FROM Dolgozo
WHERE belepes > TO_DATE('1982-01-01', 'YYYY-MM-DD');

-- Kik azok, akiknek nincs főnöke?
-- π dnev σ fonoke = NULL Dolgozo
SELECT dnev
FROM Dolgozo
WHERE fonoke IS NULL;

-- Kik azok a dolgozók, akiknek a nevében van 'A' betű?
-- π dnev σ dnev LIKE '%A%' Dolgozo
SELECT dnev
FROM Dolgozo
WHERE dnev LIKE '%A%';

-- Kik azok a dolgozók, akiknek a nevében van két 'L' betű?
-- π dnev σ dnev LIKE '%L%L%' Dolgozo
SELECT dnev
FROM Dolgozo
WHERE dnev LIKE '%L%L%';

-- Kik azok a dolgozók, akiknek a fizetése 2000 és 3000 között van?
-- π dnev, fizetes σ 2000 <= fizetes ∧ fizetes <= 3000 Dolgozo
SELECT dnev, fizetes
FROM Dolgozo
WHERE 2000 <= fizetes AND fizetes <= 3000;

-- Adjuk meg a dolgozók adatait fizetés szerint növekvő sorrendben.
-- τ fizetes asc Dolgozo
SELECT *
FROM Dolgozo
ORDER BY fizetes ASC;

-- Adjuk meg a dolgozók adatait fizetés szerint csökkenő, azon belül név szerinti sorrendben.
-- τ fizetes desc, dnev Dolgozo
SELECT *
FROM Dolgozo
ORDER BY fizetes DESC, dnev;

-- Melyek azok a gyümölcsök, amelyeket Micimackó szeret?
-- π gyumolcs σ nev = 'Micimackó' Szeret
SELECT DISTINCT gyumolcs
FROM Szeret
WHERE nev = 'Micimackó';

-- Melyek azok a gyümölcsök, amelyeket Micimackó nem szeret? (de valaki más igen)
-- π gyumolcs Szeret - π gyumolcs σ nev = 'Micimackó' Szeret
SELECT DISTINCT gyumolcs
FROM Szeret
MINUS
SELECT DISTINCT gyumolcs
FROM Szeret
WHERE nev = 'Micimackó';

-- Kik szeretik az almát?
-- 
SELECT nev
FROM Szeret
WHERE gyumolcs = 'alma';

-- Kik szeretik az almát is és a körtét is?
-- π s1.nev σ s1.nev = s2.nev ∧ s1.gyumolcs = 'alma' ∧ s2.gyumolcs = 'körte' (Szeret ⨯ Szeret)
SELECT DISTINCT s1.nev
FROM Szeret s1, Szeret s2
WHERE s1.nev = s2.nev
AND s1.gyumolcs = 'alma'
AND s2.gyumolcs = 'körte';

-- Kik azok, akik szeretik az almát, de nem szeretik a körtét?
-- (π nev σ gyumolcs = 'alma' Szeret) - (π nev σ gyumolcs = 'körte' Szeret)
SELECT nev
FROM Szeret 
WHERE gyumolcs = 'alma'
MINUS
SELECT nev
FROM Szeret
WHERE gyumolcs = 'körte';

-- FELADATOK 2

-- Kik szeretnek legalább kétféle gyümölcsöt?
-- π nev, c (σ c >= 2 γ nev; count(gyumolcs)→c Szeret)
SELECT nev
FROM Szeret
GROUP BY nev
HAVING COUNT(DISTINCT gyumolcs) >= 2;

SELECT DISTINCT s1.nev
FROM Szeret s1, Szeret s2
WHERE s1.nev = s2.nev
AND s1.gyumolcs != s2.gyumolcs;

-- Kik szeretnek legalább háromféle gyümölcsöt?
-- π nev (σ c >= 3 γ nev; count(gyumolcs)→c Szeret)
SELECT nev
FROM Szeret
GROUP BY nev
HAVING COUNT(DISTINCT gyumolcs) >= 3;

-- Kik szeretnek legfeljebb kétféle gyümölcsöt?
-- π nev (σ c <= 2 γ nev; count(gyumolcs) → c Szeret)
SELECT nev
FROM Szeret
GROUP BY nev
HAVING COUNT(DISTINCT gyumolcs) <= 2;

-- Kik szeretnek pontosan kétféle gyümölcsöt?
-- π nev (σ c = 2 γ nev; count(gyumolcs) → c Szeret)
SELECT nev
FROM Szeret
GROUP BY nev
HAVING COUNT(DISTINCT gyumolcs) = 2;

-- Kik azok a dolgozók, akiknek a főnöke KING?
-- π d1.dnev σ d2.dnev = 'KING' ∧ d1.fonoke = d2.dkod (ρ d1 Dolgozo ⨯ ρ d2 Dolgozo)
SELECT d1.dnev
FROM Dolgozo d1, Dolgozo d2
WHERE d2.dnev = 'KING'
AND d1.fonoke = d2.dkod;

-- Adjuk meg azoknak a főnököknek a nevét, akiknek a foglalkozása nem 'MANAGER'. (dnev)
-- π d1.dnev σ d2.fonoke = d1.dkod ∧ d1.foglalkozas != 'MANAGER' (ρ d1 Dolgozo ⨯ ρ d2 Dolgozo)
SELECT DISTINCT d1.dnev, d1.foglalkozas
FROM Dolgozo d1, Dolgozo d2
WHERE d2.fonoke = d1.dkod
AND d1.foglalkozas != 'MANAGER';

-- Kik azok a dolgozók, akik főnökének a főnöke KING?
SELECT DISTINCT d1.dnev, d2.dnev, d3.dnev
FROM Dolgozo d1, Dolgozo d2, Dolgozo d3
WHERE d1.fonoke = d2.dkod
AND d3.dnev = 'KING'
AND d2.fonoke = d3.dkod;

-- Kik azok a dolgozók, akik osztályának telephelye DALLAS vagy CHICAGO?
-- π dnev, telephely σ telephely = 'DALLAS' ∨ telephely = 'CHICAGO' (Dolgozo ⨝ Osztaly)
SELECT dnev, telephely
FROM Dolgozo NATURAL JOIN Osztaly
WHERE telephely = 'DALLAS' 
OR telephely = 'CHICAGO';

-- Kik azok a dolgozók, akik osztályának telephelye nem DALLAS és nem CHICAGO?
-- (π dnev, telephely (Dolgozo ⨝ Osztaly)) - (π dnev, telephely σ telephely = 'DALLAS' ∨ telephely = 'CHICAGO' (Dolgozo ⨝ Osztaly))
SELECT dnev, telephely
FROM Dolgozo NATURAL JOIN Osztaly
MINUS
SELECT dnev, telephely
FROM Dolgozo NATURAL JOIN Osztaly
WHERE telephely = 'DALLAS' 
OR telephely = 'CHICAGO';

-- Melyik osztálynak nincs dolgozója?
-- π o.oazon σ d.oazon = NULL (ρ d Dolgozo ⟖ d.oazon = o.oazon ρ o Osztaly)
SELECT o.oazon
FROM Dolgozo d RIGHT OUTER JOIN Osztaly o
ON d.oazon = o.oazon
WHERE d.oazon IS NULL;

-- Adjuk meg azoknak a dolgozóknak a nevét, akiknek a legnagyobb a fizetésük.
-- ??
SELECT dnev
FROM Dolgozo
WHERE fizetes = (
    SELECT MAX(fizetes) 
    FROM Dolgozo
);

-- FELADATOK 4

-- 1. Mekkora a maximális fizetés a dolgozók között?
-- pi mfiz gamma MAX(fizetes) -> mfiz (Dolgozo)
SELECT MAX(fizetes)
FROM Dolgozo;

-- 2. Mennyi a dolgozók összfizetése?
-- pi s (gamma SUM(fizetes) -> s (Dolgozo))
SELECT SUM(fizetes)
FROM Dolgozo;

-- 3. Mennyi a 20-as osztályon az összfizetes és az átlagfizetés? (Atlag, Össz)
-- pi atlag, ossz (gamma AVG(fizetes) -> atlag, SUM(fizetes) -> ossz (sigma oazon = 20) (Dolgozo))
SELECT AVG(fizetes) AS Atlag, SUM(fizetes) AS Ossz
FROM Dolgozo
WHERE oazon = 20;

-- 4. Adjuk meg, hogy hány különböző foglalkozás fordul elő a dolgozók között. 
-- gamma COUNT(foglalkozas) -> c (pi foglalkozas (Dolgozo))
SELECT COUNT(DISTINCT foglalkozas)
FROM Dolgozo;

-- 5. Hány olyan dolgozó van, akinek a fizetése > 2000? 
-- gamma COUNT(dnev) -> c (sigma fizetes > 2000 (Dolgozo))
SELECT COUNT(*)
FROM Dolgozo
WHERE fizetes > 2000;

-- 6. Adjuk meg osztályonként az átlagfizetést (oazon, atl_fiz).
-- pi oazon, atl_fiz (gamma oazon; AVG(fizetes) -> atl_fiz (Dolgozo))
SELECT NVL(oazon, 0), AVG(fizetes) AS atl_fiz
FROM Dolgozo
GROUP BY oazon;

-- 7. Adjuk meg osztályonként a telephelyet és az átlagfizetést (oazon, telephely, atl_fiz).
-- pi oazon, telephely, atl_fiz (gamma oazon, telephely; AVG(fizetes) -> atl_fiz (Dolgozo natural join Osztaly))
SELECT oazon, telephely, AVG(fizetes) AS atl_fiz
FROM Dolgozo NATURAL JOIN Osztaly
GROUP BY oazon, telephely;

-- 8. Adjuk meg, hogy az egyes osztályokon hány ember dolgozik. (oazon, mennyi)
-- pi oazon, mennyi (sigma oazon != NULL (gamma oazon; COUNT(*) -> mennyi (Dolgozo)))
SELECT oazon, COUNT(*) AS mennyi
FROM Dolgozo
GROUP BY oazon
HAVING oazon IS NOT NULL;

-- 9. Adjuk meg azokra az osztályokra az átlagfizetést, ahol ez nagyobb mint 2000. (oazon, atlag)
-- pi oazon, atlag (sigma atlag > 2000 (gamma oazon; AVG(fizetes) -> atlag (Dolgozo)))
SELECT oazon, AVG(fizetes) AS atlag
FROM Dolgozo
GROUP BY oazon
HAVING AVG(fizetes) > 2000;

-- 10. Adjuk meg az átlagfizetést azokon az osztályokon, ahol legalább 4-en dolgoznak (oazon, atlag)
-- pi oazon, atlag (sigma c >= 4 (gamma oazon; AVG(fizetes) -> atlag, COUNT(*) -> c (Dolgozo)))
SELECT oazon, AVG(fizetes) AS atlag
FROM Dolgozo
GROUP BY oazon
HAVING COUNT(*) >= 4;

-- 13. Adjuk meg azokat a fizetési kategóriákat, amelybe pontosan 3 dolgozó fizetése esik.
-- pi kategoria (sigma c = 3 (gamma kategoria; COUNT(*) -> c (sigma also <= fizetes and fizetes <= felso (Dolgozo x Fiz_kategoria))))
SELECT kategoria
FROM Dolgozo CROSS JOIN Fiz_kategoria
WHERE fizetes BETWEEN also AND felso
GROUP BY kategoria
HAVING COUNT(*) = 3;

-- 14. Adjuk meg azokat a fizetési kategóriákat, amelyekbe eső dolgozók mindannyian ugyanazon 
-- az osztályon dolgoznak. (kategoria)
-- pi kategoria (sigma c = 1 (gamma kategoria; COUNT(oazon) -> c (pi kategoria, oazon (sigma also <= fizetes and fizetes <= felso (Dolgozo x Fiz_kategoria)))))
SELECT kategoria
FROM Dolgozo CROSS JOIN Fiz_kategoria
WHERE fizetes BETWEEN also AND felso
GROUP BY kategoria
HAVING COUNT(DISTINCT oazon) = 1;

-- 15. Adjuk meg azon osztályok nevét és telephelyét, amelyeknek van 1-es fizetési kategóriájú dolgozója. (onev, telephely)
-- (Ez a feladat már volt korábban, de segíthet a következőnek a megoldásában.)
-- pi onev, telephely (sigma kategoria = 1 (sigma also <= fizetes and fizetes <= felso (Dolgozo natural join Osztaly x Fiz_kategoria)))
SELECT DISTINCT onev, telephely
FROM Dolgozo NATURAL JOIN Osztaly CROSS JOIN Fiz_kategoria
WHERE fizetes BETWEEN also AND felso
AND kategoria = 1;

-- 16. Adjuk meg azon osztályok nevét és telephelyét, amelyeknek legalább 2 fő 1-es fizetési 
-- kategóriájú dolgozója van.
-- pi onev, telephely (sigma c >= 2 (gamma onev, telephely; COUNT(*) -> c (sigma kategori = 1 and also <= fizetes and fizetes <= felso (Dolgozo natural join Osztaly x Fiz_kategoria))))
SELECT DISTINCT onev, telephely
FROM Dolgozo NATURAL JOIN Osztaly CROSS JOIN Fiz_kategoria
WHERE fizetes BETWEEN also AND felso
AND kategoria = 1
GROUP BY onev, telephely
HAVING COUNT(*) >= 2;
