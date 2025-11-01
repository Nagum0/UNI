-- Plusz pontos feladat ellenõrzése
-- --------------------------------
-- SET SERVEROUTPUT ON
-- EXECUTE check_group('H12', 1);
-- A plusz pontjaikat megnézhetik az ULLMAN adatbázisban az alábbi lekérdezéssel:
-- --->  SELECT * FROM nikovits.AB2_plus;

-- Elõkészítések
-- =============
-- CREATE TABLE tabla_123 as SELECT * FROM CIKK WHERE 1=2;
-- ALTER TABLE tabla_123 ALLOCATE EXTENT 
-- (SIZE 200K DATAFILE '/u01/app/oracle/oradata/aramis/users02.dbf');  -- itt egy létezõ adatfájlt kell megadni 
-- insert into tabla_123 select * from cikk;
-- commit;
-- grant select on tabla_123 to public;

-- create view v1 as
-- select first_name, last_name, salary, department_name 
-- from nikovits.employees e natural join nikovits.departments
-- where employee_id between 110 and 120;
-- create public synonym sz1 for nikovits.v1; -- system felhasználó adhatja ki


-- Egyéb objektumok (szinonima, nézet, szekvencia, adatbázis-kapcsoló)
-- ----------------
-- (DBA_SYNONYMS, DBA_VIEWS, DBA_SEQUENCES, DBA_DB_LINKS)

-- ------------------------------------------------------------------------------
-- Adjuk ki az alábbi utasítást
--   SELECT * FROM sz1;
-- majd derítsük ki, hogy kinek melyik tábláját kérdeztük le. 
-- (Ha esetleg nézettel találkozunk, azt is fejtsük ki, hogy az mit kérdez le.)

-- SELECT * from dba_objects where lower(object_name) like 'sz1%';
-- SELECT * FROM DBA_SYNONYMS WHERE owner='PUBLIC' AND synonym_name like'SZ1%';
-- SELECT * from dba_objects where lower(object_name) like 'v1%' and owner='NIKOVITS';
-- SELECT view_name, text FROM DBA_VIEWS WHERE owner='NIKOVITS' AND view_name='V1';
-- SELECT * from dba_objects where lower(object_name) like 'employ%' and owner='NIKOVITS';
-- SELECT * from dba_objects where lower(object_name) like 'departm%' and owner='NIKOVITS';
-- ------------------------------------------------------------------------------
-- Hozzunk létre egy szekvenciát, amelyik az osztály azonosítókat fogja generálni
-- a számunkra. Minden osztály azonosító a 10-nek többszöröse legyen.
-- Vigyünk fel 3 új osztályt és osztályonként minimum 3 dolgozót a táblákba. 
-- Az osztály azonosítókat a szekvencia segítségével állítsuk elõ, és ezt tegyük
-- be a táblába. (Vagyis ne kézzel írjuk be a 10, 20, 30 ... stb. azonosítót.)
-- A felvitel után módosítsuk a 10-es osztály azonosítóját a következõ érvényes (generált)
-- osztály azonosítóra. (Itt is a szekvencia segítségével adjuk meg, hogy mi lesz a 
-- következõ azonosító.) A 10-es osztály dolgozóinak az osztályazonosító ertékét is 
-- módosítsuk az új értékre.
-- -------------------------------------------------------------------------------
-- Elosztott adatbázis -> egy lekérdezésben két adatbázis tábláit is le tudjuk kérdezni.
-- Erre való az adatbázis-kapcsoló (Database Link)
-- Hozzunk létre adatbázis-kapcsolót (database link) az ULLMAN adatbázisban,
-- amelyik a másik adatbázisra mutat. 
--   CREATE DATABASE LINK aramisdb CONNECT TO felhasznalo IDENTIFIED BY jelszo    -- saját felhasználó és jelszó
--   USING 'aramis.inf.elte.hu:1521/aramis';
-- Ennek segítségével adjuk meg a következõ lekérdezéseket. 
-- A lekérdezések alapjául szolgáló táblák:

-- NIKOVITS.VILAG_ORSZAGAI   ULLMAN adatbázis
-- NIKOVITS.FOLYOK           ARAMIS adatbázis

-- Az országok egyedi azonosítója a TLD (Top Level Domain) oszlop.
-- Az ország hivatalos nyelveit vesszõkkel elválasztva a NYELV oszlop tartalmazza.
-- A GDP (Gross Domestic Product -> hazai bruttó össztermék) dollárban van megadva.
-- A folyók egyedi azonosítója a NEV oszlop.
-- A folyók vízhozama m3/s-ban van megadva, a vízgyûjtõ területük km2-ben.
-- A folyó által érintett országok azonosítóit (TLD) a forrástól a torkolatig 
-- (megfelelõ sorrendben vesszõkkel elválasztva) az ORSZAGOK oszlop tartalmazza.
-- A FORRAS_ORSZAG és TORKOLAT_ORSZAG hasonló módon a megfelelõ országok azonosítóit
-- tartalmazza. (Vigyázat!!! egy folyó torkolata országhatárra is eshet, pl. Duna)


-- - Adjuk meg azoknak az országoknak a nevét, amelyeket a Mekong nevû folyó érint.

SELECT f.nev, o.nev, o.tld, f.orszagok 
FROM NIKOVITS.vilag_orszagai o, NIKOVITS.folyok@aramisdb f
WHERE f.nev = 'Mekong' AND f.orszagok LIKE '%'||o.tld||'%';

-- -* Adjuk meg azoknak az országoknak a nevét, amelyeket a Mekong nevû folyó érint.
--    Most az országok nevét a megfelelõ sorrendben (folyásirányban) adjuk meg.
--    -> ötlet: ORDER BY INSTR(...)
-- ---------------------------------------------------------------------------------

-- Adattárolással kapcsolatos fogalmak
-- -----------------------------------
-- (DBA_TABLES, DBA_DATA_FILES, DBA_TEMP_FILES, DBA_TABLESPACES, DBA_SEGMENTS, DBA_EXTENTS, DBA_FREE_SPACE)

-- 1.
-- Adjuk meg az adatbázishoz tartozó adatfile-ok (és temporális fájlok) nevét és méretét
-- méret szerint csökkenõ sorrendben. (név, méret)
-- --------------------------------------------------------------------
SELECT file_name, bytes FROM dba_data_files
 union
SELECT file_name, bytes FROM dba_temp_files
ORDER BY bytes DESC;

-- 2.
-- Adjuk meg, hogy milyen táblaterek vannak létrehozva az adatbázisban,
-- az egyes táblaterek hány adatfájlbol állnak, és mekkora az összméretük.
-- (tablater_nev, fajlok_szama, osszmeret)
-- !!! Vigyázat, van temporális táblatér is.
-- --------------------------------------------------------------------
SELECT tablespace_name, count(*), sum(bytes) FROM dba_data_files group by tablespace_name
 UNION
SELECT tablespace_name, count(*), sum(bytes) FROM dba_temp_files group by tablespace_name;

-- 3.
-- Mekkora az adatblokkok merete a USERS táblatéren?
-- --> DBA_TABLESPACES.BLOCK_SIZE

-- 4.
-- Van-e olyan táblatér, amelynek nincs DBA_DATA_FILES-beli adatfájlja?
-- Ennek adatai hol tárolódnak? -> DBA_TEMP_FILES
-- --------------------------------------------------------------------
SELECT tablespace_name FROM dba_tablespaces WHERE tablespace_name NOT IN
 (SELECT tablespace_name FROM dba_data_files);
SELECT file_name, tablespace_name FROM dba_temp_files;

-- 5.
-- Melyik a legnagyobb méretû tábla szegmens az adatbázisban és hány extensbõl áll? 
-- (tulajdonos, szegmens_név, darab)
-- (A particionált táblákat most ne vegyük figyelembe.)
-- --------------------------------------------------------------------
SELECT owner, segment_name, extents FROM dba_segments
WHERE segment_type='TABLE' 
ORDER BY bytes DESC 
FETCH FIRST 1 rows ONLY;

-- 6.
-- Melyik a legnagyobb meretû index szegmens az adatbázisban és hány blokkból áll?
-- (tulajdonos, szegmens_név, darab)
-- (A particionált indexeket most ne vegyuk figyelembe.)
-- -- hasonló az elõzõhöz

-- 7.
-- Adjuk meg adatfájlonkent, hogy az egyes adatfájlokban mennyi a foglalt 
-- hely osszesen. (fájlnév, fájl_méret, foglalt_hely)
-- --------------------------------------------------------------------
-- -- az extenseinek a méretét kell összeadni
SELECT f.file_name, f.bytes meret, sum(e.bytes) foglalt FROM dba_data_files f, dba_extents e
WHERE f.file_id=e.file_id GROUP BY f.file_name, f.bytes;

-- 8.
-- Melyik két felhasználó objektumai foglalnak összesen a legtöbb helyet az adatbázisban?
-- Vagyis ki foglal a legtöbb helyet, és ki a második legtöbbet?
-- --------------------------------------------------------------------
SELECT owner, SUM(bytes) FROM dba_segments GROUP BY owner ORDER BY 2 DESC
FETCH FIRST 2 ROWS ONLY;

-- 9.
-- Hány extens van a 'users02.dbf' adatfájlban? Mekkora ezek összmérete? (darab, össz)
-- Hány összefüggõ szabad terület van a 'users02.dbf' adatfájlban? Mekkora ezek összmérete? (darab, össz)
-- Hány százalékban foglalt a 'users02.dbf' adatfájl?
-- --------------------------------------------------------------------
SELECT count(*), sum(e.bytes) FROM dba_data_files f, dba_extents e
WHERE file_name like '%/users02%' AND f.file_id=e.file_id;

SELECT count(*), sum(fr.bytes) FROM dba_data_files f, dba_free_space fr
WHERE file_name LIKE '%/users02%' AND f.file_id=fr.file_id;

SELECT sum(e.bytes)/f.bytes FROM dba_data_files f, dba_extents e
WHERE file_name LIKE '%/users02%' AND f.file_id=e.file_id
GROUP BY f.bytes;

-- 10.
-- Van-e a NIKOVITS felhasználónak olyan táblája, amelyik több adatfájlban is foglal helyet?
-- --------------------------------------------------------------------
SELECT segment_name, count(distinct file_id)
FROM dba_extents WHERE owner='NIKOVITS' AND segment_type='TABLE'
GROUP BY segment_name HAVING count(distinct file_id) > 1;

-- 11.
-- Válasszunk ki a fenti táblákból egyet (pl. TABLA_123) és adjuk meg, hogy ez a 
-- tábla mely adatfájlokban foglal helyet.

-- 12.
-- Melyik táblatéren van az ORAUSER felhasználó DOLGOZO táblája?
-- --------------------------------------------------------------------
-- SELECT tablespace_name FROM dba_tables WHERE owner='ORAUSER' AND table_name='DOLGOZO';

-- 13.
-- Melyik táblatéren van a NIKOVITS felhasználó ELADASOK táblája? (Miért lesz null? --> Ullman adatbázis)
-- --> Mert ez egy úgynevezett partícionált tábla, aminek minden partíciója külön szegmenst alkot,
--     és ezek a szegmensek más-más táblatéren lehetnek. Az Aramis nem támogatja a partícionált táblákat.
-- -----------------------------------------------------------------------
-- 14.
-- Írjunk meg egy PLSQL procedúrát, amelyik a paraméterül kapott felhasználónévre kiírja 
-- a felhasználó legutoljára létrehozott tábláját, annak méretét byte-okban, valamint a létrehozás
-- dátumát.

-- CREATE OR REPLACE PROCEDURE newest_table(p_user VARCHAR2) IS 
-- ...
-- Teszt:
-- SET SERVEROUTPUT ON
-- EXECUTE newest_table('nikovits');
-- EXECUTE newest_table('orauser');

-- Megjegyzés!
-- Próbáljuk ki a procedúrát a saját felhasználónevünket megadva paraméterként, az alábbi tábla létrehozása után:
--   CREATE TABLE t_without_segment(o INT) SEGMENT CREATION DEFERRED;  -- csak az Enterprise Edition-ben (Ullman)
-- Majd szúrjunk be 1 sort és próbáljuk ki újra.
--   INSERT INTO t_without_segment VALUES(100);