-- FELEADATOK 1

-- Adjuk meg azoknak a nevét és kétszeres fizetését, akik a 10-es osztályon dolgoznak.
-- π dnev, fizetes * 2 → fiz σ oazon = 10 Dolgozo
SELECT dnev, fizetes * 2 AS fiz
FROM Dolgozo
WHERE oazon = 10

-- Kik azok a dolgozók, akik 1982.01.01 után léptek be a céghez?
-- 
