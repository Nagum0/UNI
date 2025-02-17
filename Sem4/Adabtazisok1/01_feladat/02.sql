SELECT * FROM SZERET;

-- 1.  Melyek azok a gyümölcsök, amelyeket Micimackó szeret?
SELECT gyumolcs FROM SZERET WHERE nev='Micimackó';

-- 2.  Melyek azok a gyümölcsök, amelyeket Micimackó nem szeret? (de valaki más igen)
SELECT gyumolcs FROM SZERET WHERE nev!='Micimackó';

-- 3.  Kik szeretik az almát?
SELECT nev FROM SZERET WHERE gyumolcs='alma';

-- 4.  Kik nem szeretik a körtét? (de valami mást igen)
SELECT nev FROM SZERET WHERE gyumolcs!='körte';

-- 5.  Kik szeretik vagy a dinnyét vagy a körtét?
SELECT nev FROM SZERET WHERE gyumolcs='dinnye' UNION SELECT nev FROM SZERET WHERE gyumolcs='körte';

-- 6.  Kik szeretik az almát is és a körtét is?
SELECT nev FROM SZERET WHERE gyumolcs='alma' INTERSECT SELECT nev FROM SZERET WHERE gyumolcs='körte';

-- 7.  Kik azok, akik szeretik az almát, de nem szeretik a körtét?
SELECT nev FROM SZERET WHERE gyumolcs='alma' INTERSECT SELECT nev FROM SZERET WHERE gyumolcs!='körte';
