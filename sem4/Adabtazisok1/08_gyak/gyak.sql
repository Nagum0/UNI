
-- Melyik cikket szállítják a legtöbb projekthez?
CREATE OR REPLACE VIEW cikk_proj_db
AS 
SELECT cikk.ckod ckod, cnev, COUNT(DISTINCT pkod) darab FROM cikk, szallit
WHERE cikk.ckod=szallit.ckod
GROUP BY cikk.ckod, cnev;
-- SELECT * FROM cikk_proj_db order by darab DESC;

SELECT ckod, cnev, darab FROM cikk_proj_db
WHERE darab = (SELECT MAX(darab) FROM cikk_proj_db);

/*
A lekérdezés úgy is megadható, hogy ne kelljen nézetet létrehozni.
Az alábbi lekérdezésben a "nézet" csak a lekérdezés idejére jön létre.
Ezt úgy is hívjuk, hogy INLINE nézet.
*/

SELECT ckod, cnev, darab FROM
  (SELECT cikk.ckod ckod, cnev, COUNT(DISTINCT pkod) darab 
   FROM cikk, szallit
   WHERE cikk.ckod=szallit.ckod
   GROUP BY cikk.ckod, cnev) cikk_proj_db
WHERE darab = (SELECT MAX(darab) FROM 
                   (SELECT cikk.ckod ckod, cnev, COUNT(DISTINCT pkod) darab 
                    FROM cikk, szallit
                    WHERE cikk.ckod=szallit.ckod
                    GROUP BY cikk.ckod, cnev) 
               ) 
;
/*
A fenti lekérdezésben kétszer kellett leírnunk ugyanazt a "nézetet" -> cikk_proj_db
Ezt megspórolhatjuk az alábbi szintaxissal. Most is csak a lekérdezés idejére 
jön létre a nézet.
*/
WITH 
  cikk_proj_db AS (
    SELECT cikk.ckod ckod, cnev, COUNT(DISTINCT pkod) darab 
    FROM cikk, szallit
    WHERE cikk.ckod=szallit.ckod
    GROUP BY cikk.ckod, cnev)
SELECT ckod, cnev, darab FROM cikk_proj_db
WHERE darab = (SELECT MAX(darab) FROM cikk_proj_db);


Vegyünk egy másik példát:
képezzük osztályonként az összfizetést, vegyük ezen számok átlagát, és adjuk 
meg, hogy mely osztályokon nagyobb ennél az átlagnál az összfizetés.

--DROP VIEW osztaly_osszfiz;
CREATE OR REPLACE VIEW osztaly_osszfiz 
AS 
SELECT onev, SUM(fizetes) ossz_fiz
FROM dolgozo d, osztaly o
WHERE d.oazon = o.oazon
GROUP BY onev;
--SELECT * FROM osztaly_osszfiz;

--DROP VIEW atlag_koltseg;
CREATE OR REPLACE VIEW atlag_koltseg 
AS
SELECT SUM(ossz_fiz)/COUNT(*) atlag
FROM osztaly_osszfiz;
--SELECT * FROM atlag_koltseg;

SELECT * FROM osztaly_osszfiz
WHERE ossz_fiz  >  (SELECT atlag FROM atlag_koltseg);

-- Ugyanez WITH-del megadva:

WITH
  osztaly_osszfiz AS (
    SELECT onev, SUM(fizetes) ossz_fiz
    FROM dolgozo d, osztaly o
    WHERE d.oazon = o.oazon
    GROUP BY onev),
  atlag_koltseg AS (
    SELECT SUM(ossz_fiz)/COUNT(*) atlag
    FROM osztaly_osszfiz)
SELECT * FROM osztaly_osszfiz
WHERE ossz_fiz  >  (SELECT atlag FROM atlag_koltseg);

CREATE TABLE dolg2 AS SELECT * FROM nikovits.dolgozo;
CREATE TABLE oszt2 AS SELECT * FROM nikovits.osztaly;

--
-- CTAS peldak
--

drop table szeret;
drop table dolgozo;
drop table osztaly;
drop table fiz_kategoria;
drop table employees;
drop table departments;
drop table szallit;
drop table szallito;
drop table cikk;
drop table projekt;
drop table emp;
drop table dept;

create table szeret as select * from nikovits.szeret;
create table dolgozo as select * from nikovits.dolgozo;
create table osztaly as select * from nikovits.osztaly;
create table fiz_kategoria as select * from nikovits.fiz_kategoria;
create table employees as select * from nikovits.employees;
create table departments as select * from nikovits.departments;
create table szallit as select * from nikovits.szallit;
create table szallito as select * from nikovits.szallito;
create table cikk as select * from nikovits.cikk;
create table projekt as select * from nikovits.projekt;
create table emp as select * from nikovits.emp;
create table dept as select * from nikovits.dept;

SELECT * FROM CIKK;
SELECT * FROM PROJEKT;
SELECT * FROM SZALLITO;
SELECT * FROM SZALLIT;

-- Adjuk meg azon cikkek kódját és nevét, amelyeket valamelyik pécsi ('Pecs') szállító szállít. [ckod, cnev]
SELECT DISTINCT ckod, cnev
FROM (SZALLIT NATURAL JOIN SZALLITO) NATURAL JOIN CIKK
WHERE telephely = 'Pecs';

SELECT ckod, cnev
FROM CIKK
WHERE ckod IN (
    SELECT ckod
    FROM SZALLIT NATURAL JOIN SZALLITO
    WHERE telephely = 'Pecs'
);
