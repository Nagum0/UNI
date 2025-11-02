SELECT *
FROM SZERET s; -- s a SZERET aliasa (a FROM elott es utan is lehet hasznalni)

SELECT *
FROM SZERET s1, SZERET s2; -- a tablak direktszorzatat adja meg (a ugyanaz a ket table akkor kotelezo az alias)

-- HF: 
--      feladat2.txt kotelezo feladata
--      feladat2.txt elso feladatsor
--      feledat2.txt maosdik feladatsor part 2

SELECT *
FROM DOLGOZO, OSZTALY;

SELECT *
FROM DOLGOZO NATURAL JOIN OSZTALY; -- Ha van ket kozos attributum a ket table kozt akkor joinol ossze

SELECT *
FROM DOLGOZO d, OSZTALY o
WHERE d.oazon = o.oazon; -- Ez ugyanazt eri el mint a NATURAL JOIN

SELECT *
FROM DOLGOZO d1, DOLGOZO d2
WHERE d1.fonoke = d2.dkod;
