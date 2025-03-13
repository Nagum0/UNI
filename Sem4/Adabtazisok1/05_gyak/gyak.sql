SELECT DISTINCT oazon
FROM Dolgozo
MINUS
SELECT oazon
FROM Dolgozo, Fiz_kategoria
WHERE fizetes BETWEEN also AND felso
AND kategoria = 1;

SELECT telephely, COUNT(*)
FROM DOLGOZO d, OSZTALY o
WHERE d.oazon (+) = o.oazon
GROUP BY telephely;
 
SELECT o.telephely, NVL(d.dnev, 'Nincs')
FROM DOLGOZO d, OSZTALY o
WHERE d.oazon(+) = o.oazon;

SELECT NVL(o.telephely, 'Nincs'), d.dnev
FROM DOLGOZO d, OSZTALY o
WHERE d.oazon = o.oazon(+);

SELECT *
FROM DOLGOZO d LEFT OUTER JOIN OSZTALY o 
ON d.oazon = o.oazon;

SELECT NVL(o.telephely, 'Nincs'), NVL(dnev, 'Nincs')
FROM DOLGOZO d FULL OUTER JOIN OSZTALY o 
ON d.oazon = o.oazon;

-- Kotelezo feladat
CREATE TABLE R(A VARCHAR(10), B INTEGER, C INTEGER);
INSERT INTO R VALUES('X',1, 2);
INSERT INTO R VALUES('Y',2, 3);
INSERT INTO R VALUES('Y',3, 4);
INSERT INTO R VALUES('X',1, 5);
INSERT INTO R VALUES('Y',3, 5);
INSERT INTO R VALUES('X',4, 2);
INSERT INTO R VALUES('X',4, 4);

CREATE TABLE S(C INTEGER, D INTEGER);
INSERT INTO S VALUES(2, 8);
INSERT INTO S VALUES(2, 15);
INSERT INTO S VALUES(3, 9);
INSERT INTO S VALUES(3, 14);
INSERT INTO S VALUES(4, 11);
INSERT INTO S VALUES(4, 17);
INSERT INTO S VALUES(2, 1);
INSERT INTO S VALUES(6, 20);

-- Feladat 1. Kit. Rel. Algebra -> SQL

-- ? A; AVG(D) ? av (? B >= 2 (R x S))
CREATE TABLE GYAK5 AS
SELECT A, AVG(D) AS av
FROM R, S
WHERE B >= 2
GROUP BY A;

SELECT o.oazon, o.onev
FROM OSZTALY o
WHERE NOT EXISTS (
    SELECT 1
    FROM DOLGOZO d
    WHERE d.oazon = o.oazon);