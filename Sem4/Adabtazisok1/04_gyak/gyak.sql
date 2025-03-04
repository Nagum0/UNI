-- Ismetles

SELECT DISTINCT dnev, fizetes
FROM DOLGOZO
MINUS
SELECT DISTINCT d1.dnev, d1.fizetes
FROM DOLGOZO d1, DOLGOZO d2
WHERE d1.fizetes < d2.fizetes;

SELECT DISTINCT dnev
FROM DOLGOZO
WHERE fizetes = (SELECT MAX(fizetes) FROM DOLGOZO);

SELECT *
FROM DOLGOZO, FIZ_KATEGORIA
WHERE fizetes BETWEEN also AND felso;

-- Aggregalo fuggvenyek

CREATE TABLE GYAK4
AS
(
    SELECT 
    d.oazon AS Oazon, 
    o.telephely AS TELEPHELY, 
    TRUNC(AVG(d.fizetes), 2) AS AtlagFiz
    FROM DOLGOZO d, OSZTALY o
    WHERE d.oazon = o.oazon
    GROUP BY d.oazon, telephely
);
