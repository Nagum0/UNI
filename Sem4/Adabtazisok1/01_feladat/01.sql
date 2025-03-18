-- Feladat: 1
SELECT * FROM DOLGOZO WHERE fizetes > 2800;

-- Feladat: 2
SELECT * FROM DOLGOZO WHERE oazon = 10 OR oazon = 20;

-- Feladat: 3
SELECT dkod, dnev FROM DOLGOZO WHERE jutalek IS NOT NULL AND jutalek > 600;
SELECT dkod, dnev FROM DOLGOZO WHERE nvl(jutalek, 0) > 600; -- Itt az nvl fv. atalakitja a NULL-t 0-ra

-- Feladat: 4
SELECT * FROM DOLGOZO WHERE jutalek < 600;

-- Feladat: 5
SELECT * FROM DOLGOZO WHERE jutalek IS NULL;

-- Feladat: 6
SELECT foglalkozas FROM DOLGOZO;

-- Feladat: 7
SELECT fizetes * 2 FROM DOLGOZO WHERE oazon = 10;

-- Feladat: 8
SELECT * FROM DOLGOZO WHERE belepes > '1982.01.01';

-- Feladat: 9
SELECT * FROM DOLGOZO WHERE fonoke IS NULL;

-- Feladat: 10
SELECT * FROM DOLGOZO WHERE dnev LIKE '%A%';

-- Feladat: 11
SELECT * FROM DOLGOZO WHERE dnev LIKE '%L%L%';

-- Feladat: 12
SELECT * FROM DOLGOZO WHERE fizetes BETWEEN 2000 AND 3000;

-- Feladat: 13
SELECT * FROM DOLGOZO ORDER BY fizetes ASC;

-- Feladat: 14
SELECT * FROM DOLGOZO ORDER BY fizetes DESC, dnev ASC;

-- Feladat: 15
SELECT * FROM DOLGOZO WHERE fonoke = 7839;
