-- 16. Kik azok a dolgozók, akiknek a főnöke KING? (nem leolvasva)
SELECT DISTINCT d1.dnev
FROM DOLGOZO d1, DOLGOZO d2
WHERE d1.fonoke = d2.dkod
AND d2.dnev = 'KING';

-- 17. Adjuk meg azoknak a főnököknek a nevét, akiknek a foglalkozása nem 'MANAGER'. (dnev)
SELECT DISTINCT dnev
FROM DOLGOZO
WHERE foglalkozas != 'MANAGER'
INTERSECT
SELECT DISTINCT d1.dnev
FROM DOLGOZO d1, DOLGOZO d2
WHERE d1.dkod = d2.fonoke;

-- 18. Adjuk meg azokat a dolgozókat, akik többet keresnek a főnöküknél.
SELECT DISTINCT d1.dnev
FROM DOLGOZO d1, DOLGOZO d2
WHERE d1.fonoke = d2.dkod
AND d1.fizetes > d2.fizetes;

-- 19. Kik azok a dolgozók, akik főnökének a főnöke KING?
SELECT DISTINCT d1.dnev
FROM DOLGOZO d1, DOLGOZO d2, DOLGOZO d3
WHERE d1.fonoke = d2.dkod
AND d2.fonoke = d3.dkod
AND d3.dnev = 'KING';

-- 20. Kik azok a dolgozók, akik osztályának telephelye DALLAS vagy CHICAGO?
SELECT DISTINCT dnev
FROM DOLGOZO NATURAL JOIN OSZTALY
WHERE telephely = 'DALLAS' 
OR telephely = 'CHICAGO';

-- 21. Kik azok a dolgozók, akik osztályának telephelye nem DALLAS és nem CHICAGO?
SELECT DISTINCT dnev
FROM DOLGOZO NATURAL JOIN OSZTALY
WHERE telephely != 'DALLAS' 
AND telephely != 'CHICAGO';

-- 22. Adjuk meg azoknak a nevét, akiknek a fizetése > 2000 vagy a CHICAGO-i osztályon dolgoznak.
SELECT DISTINCT dnev
FROM DOLGOZO NATURAL JOIN OSZTALY
WHERE fizetes > 2000
OR telephely = 'CHICAGO';

-- 23. Melyik osztálynak nincs dolgozója?
SELECT o1.onev
FROM OSZTALY o1
MINUS
SELECT o2.onev
FROM DOLGOZO NATURAL JOIN OSZTALY o2;

-- 24. Adjuk meg azokat a dolgozókat, akiknek van 2000-nél nagyobb fizetésű beosztottja.
SELECT DISTINCT d1.dnev
FROM DOLGOZO d1, DOLGOZO d2
WHERE d1.dkod = d2.fonoke
AND d2.fizetes > 2000;

-- 25. Adjuk meg azokat a dolgozókat, akiknek nincs 2000-nél nagyobb fizetésű beosztottja.
SELECT DISTINCT d1.dnev
FROM DOLGOZO d1, DOLGOZO d2
WHERE d1.dkod = d2.fonoke
MINUS
SELECT d1.dnev
FROM DOLGOZO d1, DOLGOZO d2
WHERE d1.dkod = d2.fonoke
AND d2.fizetes > 2000;

-- 26. Adjuk meg azokat a telephelyeket, ahol van elemző (ANALYST) foglalkozású dolgozó.
SELECT DISTINCT telephely
FROM DOLGOZO NATURAL JOIN OSZTALY
WHERE foglalkozas = 'ANALYST';

-- 27. Adjuk meg azokat a telephelyeket, ahol nincs elemző (ANALYST) foglalkozású dolgozó.
SELECT DISTINCT telephely
FROM DOLGOZO NATURAL JOIN OSZTALY
MINUS
SELECT DISTINCT telephely
FROM DOLGOZO NATURAL JOIN OSZTALY
WHERE foglalkozas = 'ANALYST';

-- 28. Adjuk meg azoknak a dolgozóknak a nevét, akiknek a legnagyobb a fizetésük.
SELECT DISTINCT dnev, fizetes
FROM DOLGOZO
MINUS
SELECT DISTINCT d1.dnev, d1.fizetes
FROM DOLGOZO d1, DOLGOZO d2
WHERE d1.fizetes < d2.fizetes;

SELECT DISTINCT dnev
FROM DOLGOZO
WHERE fizetes = (SELECT MAX(fizetes) FROM DOLGOZO);
