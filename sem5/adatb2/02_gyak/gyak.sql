-- Továbbra is kötelező az első feladatsorban említett GYAK01 nevű tábla létrehozása mindkét adatbázisban.

-- Feladat plusz pontokért (részleteket lásd --> zh1_info.txt a Teams-ben)
-- ------------------------------------------------------------------------------
-- Írják meg az alábbi 14. feladatban szereplő NEWEST_TABLE nevű procedúrát.
-- Azt, hogy az output helyes-e ellenőrizni tudják a feladat után megadott 'CHECK_PLSQL'
-- procedúra futtatásával.
-- A feladat célja, hogy átismételjék a PL/SQL nyelv legfontosabb konstrukciót.

-- Határidő: a következő gyakorlat kezdete.
-- =============================================================================
--  Kérem olvassák el a fájl végén lévő megjegyzést a sokáig futó programokról,       <--- Fontos információ
--  illetve a beragadt session-ök a kilövéséről!
-- =============================================================================

-- Egyéb objektumok (szinonima, nézet, szekvencia, adatbázis-kapcsoló)
-- ----------------
-- (DBA_SYNONYMS, DBA_VIEWS, DBA_SEQUENCES, DBA_DB_LINKS)

-- ------------------------------------------------------------------------------
-- Adjuk ki az alábbi utasítást 
--   SELECT * FROM sz1;
-- majd derítsük ki, hogy kinek melyik tábláját kérdeztük le. 
-- (Ha esetleg nézettel találkozunk, azt is fejtsük ki, hogy az mit kérdez le.)
-- ------------------------------------------------------------------------------
-- Hozzunk létre egy szekvenciát, amelyik az osztály azonosítókat fogja generálni
-- a számunkra. Minden osztály azonosító a 10-nek többszöröse legyen.
-- Vigyünk fel 3 új osztályt és osztályonként minimum 3 dolgozót a táblákba. 
-- Az osztály azonosítókat a szekvencia segítségével állítsuk elő, és ezt tegyük
-- be a táblába. (Vagyis ne kézzel írjuk be a 10, 20, 30 ... stb. azonosítót.)
-- A felvitel után módosítsuk a 10-es osztály azonosítóját a következő érvényes (generált)
-- osztály azonosítóra. (Itt is a szekvencia segítségével adjuk meg, hogy mi lesz a 
-- következő azonosító.) A 10-es osztály dolgozóinak az osztályazonosító ertékét is 
-- módosítsuk az új értékre.
-- -------------------------------------------------------------------------------
-- Elosztott adatbázis -> egy lekérdezésben két adatbázis tábláit is le tudjuk kérdezni.
-- Erre való az adatbázis-kapcsoló (Database Link)
-- Hozzunk létre adatbázis-kapcsolót (Database Link) az ULLMAN adatbázisban,
-- amelyik a másik (ARAMIS) adatbázisra mutat. 
--   CREATE DATABASE LINK aramisdb CONNECT TO felhasznalo IDENTIFIED BY jelszo   -- saját felhasználó és jelszó
--   USING 'aramis.inf.elte.hu:1521/aramis';
-- Ennek segítségével adjuk meg a következő lekérdezéseket. 
-- A lekérdezések alapjául szolgáló táblák:

-- NIKOVITS.VILAG_ORSZAGAI   ULLMAN adatbázis
-- NIKOVITS.FOLYOK           ARAMIS adatbázis

-- Az országok egyedi azonosítója a TLD (Top Level Domain) oszlop.
-- Az ország hivatalos nyelveit vesszőkkel elválasztva a NYELV oszlop tartalmazza.
-- A GDP (Gross Domestic Product -> hazai bruttó össztermék) dollárban van megadva.
-- A folyók egyedi azonosítója a NEV oszlop.
-- A folyók vízhozama m3/s-ban van megadva, a vízgyűjtő területük km2-ben.
-- A folyó által érintett országok azonosítóit (TLD) a forrástól a torkolatig 
-- (megfelelő sorrendben vesszőkkel elválasztva) az ORSZAGOK oszlop tartalmazza.
-- A FORRAS_ORSZAG és TORKOLAT_ORSZAG hasonló módon a megfelelő országok azonosítóit
-- tartalmazza. (Vigyázat!!! egy folyó torkolata országhatárra is eshet, pl. Duna)


-- - Adjuk meg azoknak az országoknak a nevét, amelyeket a Mekong nevű folyó érint.

-- -* Adjuk meg azoknak az országoknak a nevét, amelyeket a Mekong nevű folyó érint.
--    Most az országok nevét a megfelelő sorrendben (folyásirányban) adjuk meg.
-- ---------------------------------------------------------------------------------


-- Adattárolással kapcsolatos fogalmak
-- -----------------------------------
-- (DBA_TABLES, DBA_DATA_FILES, DBA_TEMP_FILES, DBA_TABLESPACES, DBA_SEGMENTS, DBA_EXTENTS, DBA_FREE_SPACE)

SELECT * FROM DBA_DATA_FILES;
SELECT * FROM DBA_TEMP_FILES;
SELECT * FROM DBA_TABLESPACES;

-- 1.
-- Adjuk meg az adatbázishoz tartozó adatfile-ok (és temporális fájlok) nevét és méretét
-- méret szerint csökkenő sorrendben. (név, méret)

SELECT file_name, bytes
FROM DBA_DATA_FILES
UNION
SELECT file_name, bytes
FROM DBA_TEMP_FILES
ORDER BY bytes DESC;

-- 2.
-- Adjuk meg, hogy milyen táblaterek vannak létrehozva az adatbazisban,
-- az egyes táblaterek hány adatfájlbol állnak, és mekkora az összméretük.
-- (tablater_nev, fajlok_szama, osszmeret)
-- !!! Vigyázat, van temporális táblatér is.

WITH all_data_files AS (
    SELECT tablespace_name, file_name, bytes
    FROM DBA_DATA_FILES
    UNION
    SELECT tablespace_name, file_name, bytes
    FROM DBA_TEMP_FILES
)
SELECT DISTINCT tablespace_name, COUNT(DISTINCT file_name) AS faljok_szama, SUM(bytes) AS osszmeret
FROM all_data_files
GROUP BY tablespace_name;

-- 3.
-- Mekkora az adatblokkok merete a USERS táblatéren?

SELECT block_size
FROM DBA_TABLESPACES
WHERE tablespace_name='USERS';

-- 4.
-- Van-e olyan táblatér, amelynek nincs DBA_DATA_FILES-beli adatfájlja?
-- Ennek adatai hol tárolódnak? -> DBA_TEMP_FILES

SELECT DISTINCT tablespace_name
FROM DBA_TABLESPACES
MINUS
SELECT DISTINCT tablespace_name
FROM DBA_DATA_FILES;

-- 5.
-- Melyik a legnagyobb méretű tábla szegmens az adatbázisban és hány extensből áll? 
-- (tulajdonos, szegmens_név, darab)
-- (A particionált táblákat most ne vegyük figyelembe, ezekről majd később lesz szó.)
-- DBA_SEGMENTS, DBA_EXTENTS, DBA_FREE_SPACE

SELECT * FROM DBA_SEGMENTS;

SELECT owner, segment_name, extents
FROM DBA_SEGMENTS
WHERE segment_type='TABLE'
AND bytes=(
    SELECT MAX(bytes)
    FROM DBA_SEGMENTS
    WHERE segment_type='TABLE'
);

-- 6.
-- Melyik a legnagyobb meretű index szegmens az adatbázisban és hány blokkból áll?
-- (tulajdonos, szegmens_név, darab)
-- (A particionalt indexeket most ne vegyük figyelembe.)

SELECT owner, segment_name, blocks
FROM DBA_SEGMENTS
WHERE segment_type='INDEX'
AND bytes=(
    SELECT MAX(bytes)
    FROM DBA_SEGMENTS
    WHERE segment_type='INDEX'
);

-- 7.
-- Adjuk meg adatfájlonkent, hogy az egyes adatfájlokban mennyi a foglalt 
-- hely osszesen. (fájlnév, fájl_méret, foglalt_hely)

SELECT df.file_name, df.bytes, SUM(de.bytes)
FROM DBA_DATA_FILES df
JOIN DBA_EXTENTS de
ON df.file_id=de.file_id
GROUP BY df.file_name, df.bytes;

-- 8.
-- Melyik két felhasználó objektumai foglalnak összesen a legtöbb helyet az adatbázisban?
-- Vagyis ki foglal a legtöbb helyet, és ki a második legtöbbet?

SELECT * FROM DBA_OBJECTS;
SELECT * FROM DBA_SEGMENTS WHERE owner='UAUYQF';
SELECT * FROM DBA_EXTENTS WHERE owner='UAUYQF';

SELECT owner, SUM(bytes)
FROM DBA_EXTENTS
GROUP BY owner
ORDER BY SUM(bytes) DESC
FETCH FIRST 2 ROWS ONLY;

-- 9.
-- Hány extens van a 'users02.dbf' adatfájlban? Mekkora ezek összmérete? (darab, össz)
-- Hány összefüggő szabad terület van a 'users02.dbf' adatfájlban? Mekkora ezek összmérete? (darab, össz)
-- Hány százalékban foglalt a 'users02.dbf' adatfájl?

SELECT df.file_name, COUNT(*), SUM(de.bytes)
FROM DBA_DATA_FILES df
JOIN DBA_EXTENTS de
ON df.file_id=de.file_id
WHERE file_name LIKE '%users02.dbf%'
GROUP BY df.file_name;

SELECT * FROM DBA_FREE_SPACE;

SELECT df.file_name, COUNT(*), SUM(dfs.bytes)
FROM DBA_DATA_FILES df
JOIN DBA_FREE_SPACE dfs
ON df.file_id=dfs.file_id
WHERE file_name LIKE '%users02.dbf%'
GROUP BY df.file_name;

SELECT df.file_name, COUNT(*), (SUM(de.bytes) / df.bytes) * 100
FROM DBA_DATA_FILES df
JOIN DBA_EXTENTS de
ON df.file_id=de.file_id
WHERE file_name LIKE '%users02.dbf%'
GROUP BY df.file_name, df.bytes;

-- 10.
-- Van-e a NIKOVITS felhasználónak olyan táblája, amelyik több adatfájlban is foglal helyet?

SELECT de.segment_name
FROM DBA_DATA_FILES df
JOIN DBA_EXTENTS de
ON df.file_id=de.file_id
WHERE owner='NIKOVITS'
AND segment_type='TABLE'
GROUP BY de.segment_name
HAVING COUNT(DISTINCT df.file_name) > 1;

-- 11.
-- Válasszunk ki a fenti táblákból egyet (pl. tabla_123) és adjuk meg, hogy ez a 
-- tábla mely adatfájlokban foglal helyet.

SELECT df.file_name
FROM DBA_DATA_FILES df
JOIN DBA_EXTENTS de
ON df.file_id=de.file_id
WHERE de.segment_name='TABLA_123';

-- 12.
-- Melyik táblatéren van az ORAUSER felhasználó DOLGOZO táblája? (táblatér)

SELECT tablespace_name
FROM DBA_SEGMENTS
WHERE owner='ORAUSER'
AND segment_name='DOLGOZO'
AND segment_type='TABLE';

-- 13.
-- Melyik táblatéren van a NIKOVITS felhasználó ELADASOK táblája? (táblatér)
-- (Miért lesz null?)

SELECT tablespace_name
FROM DBA_SEGMENTS
WHERE owner='NIKOVITS'
AND segment_name='ELADASOK'
AND segment_type='TABLE';

-- -----------------------------------------------------------------------
-- 14.
-- Írjunk meg egy PLSQL procedúrát, amelyik a paraméterül kapott felhasználónévre kiírja 
-- a felhasználó legutoljára létrehozott tábláját, annak méretét byte-okban, valamint a létrehozás
-- dátumát. Az output formátuma a következő legyen:

-- Table_name: NNNNNN   Size: SSSSSS bytes   Created: yyyy.mm.dd.hh:mi

-- Ha a felhasználónak több táblája is ugyanabban az időpontban jött létre, akkor azt vegyük, amelyik
-- ezek közül ábécé sorrendben az első. (A DATE adattípus másodperc pontossággal tárolja az időpontot.)
-- Vigyázzanak a dátum és idő formátumára! 03 óra és 15 óra nem ugyanaz.

-- CREATE OR REPLACE PROCEDURE newest_table(p_user VARCHAR2) IS 
-- ...
-- Teszt:
-- SET SERVEROUTPUT ON
-- EXECUTE newest_table('nikovits');
-- EXECUTE newest_table('orauser');

-- Ellenőrzés:
-- ----------
-- EXECUTE check_plsql('newest_table(''nikovits'')');
-- EXECUTE check_plsql('newest_table(''orauser'')');

-- Megjegyzés!
-- Próbáljuk ki a procedúrát a saját felhasználónevünket megadva paraméterként, az alábbi tábla létrehozása után:
--   CREATE TABLE t_without_segment(o INT) SEGMENT CREATION DEFERRED;     -- csak az Enterprise Edition-ben (Ullman)
-- Majd szúrjunk be 1 sort és próbáljuk ki újra.
--   INSERT INTO t_without_segment VALUES(100);
-- =============================================================================
--          Megjegyzés a sokáig futó programokkal kapcsolatban.
-- =============================================================================
-- Nagyobb táblák esetén előfordulhat, hogy a programunk kivárhatatlanul sokáig futna.
-- Épp emiatt mindig építsenek be a programjukba valamilyen, az alábbihoz hasonló időkorlátot.
-- A programokat úgy írják meg, hogy azok gyorsan, hatékonyan működjenek akár nagyobb táblára is.
-- Ha bármelyik programjuk 60 másodpercnél tovább fut, nem fogom értékelni a zh-ban sem, és nem adok rá pontot.
-- Az alábbi program például gyorsan lefut az EMP táblára, de nem fut le gyorsan a CUSTOMERS táblára.
-- (Feltéve, hogy nincs létrehozva index egyik táblára sem.)

-- CREATE OR REPLACE PROCEDURE time_limit(p integer) IS
--   rnd INTEGER; cnt INTEGER; start_time DATE; run_time NUMBER;
-- BEGIN 
--   SELECT sysdate INTO start_time FROM dual;
--   FOR I IN 1..20000 LOOP
--     SELECT round(dbms_random.VALUE(1,10000)) INTO rnd FROM dual; 
--     IF p = 1 THEN
--       SELECT count(*) INTO cnt FROM nikovits.emp WHERE empno = rnd;          /* small table */
--     ELSE
--       SELECT count(*) INTO cnt FROM nikovits.customers WHERE cust_id = rnd;  /* large table */
--     END IF;
-- --  run time limit in seconds
--     SELECT (sysdate-start_time)*24*60*60 INTO run_time FROM dual;
--     IF run_time > 30 THEN dbms_output.put_line('Timeout!!!'); RETURN; END IF;
--   END LOOP;
--   dbms_output.put_line('Completed, no Timeout');
-- END;
-- /
-- set serveroutput on
-- execute time_limit(1);
-- execute time_limit(2);
-- =============================================================================
-- Mit tegyünk, ha egy program/lekérdezés végtelen ciklusba kerül vagy csak nagyon        <--- Fontos információ
-- sokáig fut? Hogyan lőjük ki a saját beragadt session-ünket? 
-- Lásd https://people.inf.elte.hu/nikovits/AB2/PLSQL/pl_00_peldak.txt      