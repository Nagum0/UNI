SELECT * FROM SZERET;

-- 1.  Melyek azok a gyümölcsök, amelyeket Micimackó szeret?
SELECT DISTINCT gyumolcs FROM SZERET WHERE nev='Micimack�';

-- 2.  Melyek azok a gyümölcsök, amelyeket Micimackó nem szeret? (de valaki más igen)
SELECT DISTINCT gyumolcs FROM SZERET 
MINUS 
SELECT DISTINCT gyumolcs FROM SZERET WHERE nev='Micimac�';

-- 3.  Kik szeretik az almát?
SELECT DISTINCT nev FROM SZERET WHERE gyumolcs='alma';

-- 4.  Kik nem szeretik a körtét? (de valami mást igen)
SELECT DISTINCT nev FROM SZERET 
MINUS 
SELECT DISTINCT nev FROM SZERET WHERE gyumolcs='k�rte';

-- 5.a  Kik szeretik vagy a dinnyét vagy a körtét (megengedo)?
SELECT DISTINCT nev FROM SZERET WHERE gyumolcs='dinnye' 
UNION 
SELECT DISTINCT nev FROM SZERET WHERE gyumolcs='k�rte';

-- 5.b Kik szeretik vagy a dinnyet vagy a k�rtet (kizaro)?
(SELECT DISTINCT nev FROM SZERET WHERE gyumolcs='eper' 
UNION 
SELECT DISTINCT nev FROM SZERET WHERE gyumolcs='k�rte')
MINUS
(SELECT DISTINCT nev FROM SZERET WHERE gyumolcs='eper' 
INTERSECT 
SELECT DISTINCT nev FROM SZERET WHERE gyumolcs='k�rte');

-- 6.  Kik szeretik az almát is és a körtét is?
SELECT DISTINCT nev FROM SZERET WHERE gyumolcs='alma' 
INTERSECT 
SELECT DISTINCT nev FROM SZERET WHERE gyumolcs='k�rte';

-- 7.  Kik azok, akik szeretik az almát, de nem szeretik a körtét?
SELECT nev FROM SZERET WHERE gyumolcs='alma' 
INTERSECT 
SELECT nev FROM SZERET WHERE gyumolcs!='k�rte';
