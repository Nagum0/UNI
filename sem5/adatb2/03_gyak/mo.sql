-- Plusz pontos feladat ellenõrzése
-- --------------------------------
-- SET SERVEROUTPUT ON
-- EXECUTE check_group('P8', 2);
-- A plusz pontjaikat megnézhetik az ULLMAN adatbázisban az alábbi lekérdezéssel:
-- --->  SELECT * FROM nikovits.AB2_plus;

-- ROWID adattípus formátuma és jelentése (lásd még DBMS_ROWID package)
-- --------------------------------------------------------------------

-- 18 karakteren irodik ki, a kovetkezo formaban: OOOOOOFFFBBBBBBRRR
-- OOOOOO -  az objektum azonositoja (egészen pontosan az úgynevezett adatobjektum azonosítója)
-- FFF    -  fajl azonositoja (tablateren beluli relativ sorszam)
-- BBBBBB -  blokk azonosito (a fajlon beluli sorszam)
-- RRR    -  sor azonosito (a blokkon beluli sorszam)

-- A ROWID megjeleniteskor 64-es alapu kodolasban jelenik meg (Base64). 
-- Az egyes szamoknak (0-63) a következo karakterek felelnek meg:
-- A-Z -> (0-25), a-z -> (26-51), 0-9 -> (52-61), '+' -> (62), '/' -> (63)

-- Pl. 'AAAAAB' -> 000001

-- 1.
-- A NIKOVITS felhasználó CIKK táblája hány blokkot foglal le az adatbázisban? (blokkszám)
-- (Vagyis hány olyan blokk van, ami ennek a táblának a szegmenséhez tartozik és így már 
-- más táblához nem rendelhetõ hozzá?)
-- ------------------------------------------
SELECT bytes, blocks FROM dba_segments
WHERE owner='NIKOVITS' AND segment_name='CIKK' AND segment_type='TABLE';

-- 2.
-- A NIKOVITS felhasználó CIKK táblájának adatai hány blokkban helyezkednek el? (blokkszám)
-- (Vagyis a tábla sorai ténylegesen hány blokkban vannak tárolva?)
-- !!! -> Ez a kérdés nem ugyanaz mint az elõzõ, mert a tábla blokkjai lehetnek üresek is.
-- ---------------------------------------------
SELECT DISTINCT dbms_rowid.rowid_relative_fno(ROWID) fajl,
       dbms_rowid.rowid_block_number(ROWID) blokk
FROM nikovits.cikk;

-- Vagy rögtön megszámolva az elõ lekérdezés által felsorolt adatblokkokat:
-- ------------------------------------------------------------------------ 
SELECT count(*) FROM
(SELECT DISTINCT dbms_rowid.rowid_relative_fno(ROWID) fajl,
        dbms_rowid.rowid_block_number(ROWID) blokk
 FROM nikovits.cikk);

-- 3.
-- Az egyes blokkokban hány sor van? (file_id, blokk_id, darab)
-- ------------------------------------------------------------
-- SELECT dbms_rowid.rowid_relative_fno(ROWID) fajl,
--        dbms_rowid.rowid_block_number(ROWID) blokk, count(*)
-- FROM nikovits.cikk
-- GROUP BY dbms_rowid.rowid_relative_fno(ROWID), dbms_rowid.rowid_block_number(ROWID);

-- Hozzunk létre egy CIKK_PROBA nevû táblát az EXAMPLE táblatéren, amelynek szerkezete azonos a nikovits.cikk 
-- tábláéval és pontosan 128 KB helyet foglal az adatbázisban. Foglaljunk le manuálisan további 
-- 128 KB helyet a táblához. Vigyünk fel sorokat addig, amig az elsõ blokk tele nem 
-- lesz, és 1 további sora lesz még a táblának a második blokkban.
-- (A felvitelt plsql programmal végezzük és ne kézzel, mert úgy kicsit sokáig tartana.)
-- További segítség és példák találhatók az ab2_oracle.docx állományban.
-- -------------------------------------------------------------------------------------
-- ALTER SESSION SET deferred_segment_creation = FALSE;

-- A fenti utasítás egy inicializációs paraméter értékét változtatja meg. Ha a paraméter 
-- értéke TRUE lenne, akkor csak késleltetve, az elsõ beszúráskor jönne létre a szegmens.
-- Az inicializációs paraméter(ek) aktuális értékét megnézhetjük session szinten:
-- -> SELECT * FROM v$parameter WHERE name like '%deferred%segment%';  
-- illetve instance szinten:
-- -> SELECT * FROM v$system_parameter WHERE name like '%deferred%segment%';

-- -- Létrehozzuk a táblát a megfelelõ helyfoglalási paraméterekkel:
-- CREATE TABLE cikk_proba
-- TABLESPACE example
-- STORAGE (INITIAL 128K  MINEXTENTS 1  MAXEXTENTS 200  PCTINCREASE 0)
-- AS 
-- SELECT * FROM nikovits.cikk WHERE 1=2;

-- -- Újabb extenst foglalunk le a tábla számára (a táblatér egy létezõ fájlja legyen !!!)
-- ALTER TABLE cikk_proba ALLOCATE EXTENT 
-- (SIZE 128K DATAFILE '/u01/app/oracle/oradata/ullman/example01.dbf');

-- -- Majd egyesével sorokat szúrunk be, és mindig megnézzük, hogy van-e már 2 blokk
-- DECLARE
--  v_blokkszam NUMBER := 0; -- nemüres blokkok száma 
--  v_sorsz NUMBER := 1;
-- BEGIN
--   WHILE v_blokkszam < 2 AND v_sorsz < 1000 LOOP     
--     INSERT INTO cikk_proba SELECT * FROM nikovits.cikk WHERE ckod=v_sorsz;
--     v_sorsz := v_sorsz + 1;
--     SELECT COUNT(DISTINCT dbms_rowid.rowid_relative_fno(ROWID)||
--                 dbms_rowid.rowid_block_number(ROWID)) INTO v_blokkszam
--     FROM nikovits.cikk_proba;
--   END LOOP;
--   COMMIT;
-- END;
-- /
-- -- A végén ellenõrizhetjük, hogy tényleg 2 blokkban vannak a sorok:
-- SELECT dbms_rowid.rowid_relative_fno(ROWID) fajl,
--        dbms_rowid.rowid_block_number(ROWID) blokk, count(*)
-- FROM nikovits.cikk_proba
-- GROUP BY dbms_rowid.rowid_relative_fno(ROWID), dbms_rowid.rowid_block_number(ROWID);
-- -- Azt is nézzük meg, hogy mennyi helyet foglal:
-- SELECT segment_name, extent_id, bytes FROM dba_extents WHERE owner=user and segment_name='CIKK_PROBA';

-- Próbáljuk ki az elõzõt ismét, de most a PCTFREE értéket állítsuk 40-re. 
-- Mindkét esetben ellenõrizzük is, hogy a sorok tényleg két blokkban vannak,
-- és a másodikban csak egyetlen sor van.
-- --------------------------------------------------------------------------
-- DROP TABLE cikk_proba;
-- CREATE TABLE cikk_proba
-- TABLESPACE example PCTFREE 40
-- STORAGE (INITIAL 128K  MINEXTENTS 1  MAXEXTENTS 200  PCTINCREASE 0)
-- AS 
-- SELECT * FROM nikovits.cikk WHERE 1=2;

-- A PL/SQL programot ismét lefuttatva, látható, hogy most kevesebb sor fér el a 2 blokkban.

-- 4.
-- Állapítsuk meg, hogy a NIKOVITS.ELADASOK táblának a következõ adatokkal azonosított sora
-- (szla_szam=100) melyik adatfájlban van, azon belül melyik blokkban, és a blokkon belül hányadik a sor?
-- (file_név, blokk_id, sorszám)
-- --------------------------------------------------------------
-- SELECT  dbms_rowid.rowid_object(ROWID) adatobj, 
--         dbms_rowid.rowid_relative_fno(ROWID) fajl,
--         dbms_rowid.rowid_block_number(ROWID) blokk,
--         dbms_rowid.rowid_row_number(ROWID) sor
-- FROM nikovits.eladasok 
-- WHERE szla_szam=100;

-- Az elõzõ feladatban megadott sor melyik partícióban van?
-- Mennyi az objektum azonosítója, és ez milyen objektum?
-- -------------------------------------------------------
-- SELECT  o.object_name, o.subobject_name, o.object_type,o.data_object_id
-- FROM nikovits.eladasok e, dba_objects o
-- WHERE dbms_rowid.rowid_object(e.ROWID) = o.data_object_id 
-- AND szla_szam=100;

-- --> A fenti tábla egy speciálisan tárolt, úgynevezett partícionált tábla, aminek 3 szegmense van, lásd az alábbiakat:
-- SELECT * FROM dba_objects WHERE OWNER='NIKOVITS' AND object_name = 'ELADASOK';
-- SELECT * FROM dba_segments WHERE OWNER='NIKOVITS' AND segment_name = 'ELADASOK';
-- -----------------------------------------------------------------------
-- 5.
-- Írjunk meg egy PLSQL procedúrát, amelyik kiírja, hogy a NIKOVITS.TABLA_123 táblának melyik 
-- adatblokkjában hány sor van. (Output formátuma soronként: file_id; blokk_id -> darab;)
-- Vigyázat!!! Azokat az adatblokkokat is ki kell írni, amelyekben a sorok száma 0, de a tábla
-- szegmenséhez tartoznak.
-- -- elõtte GRANT SELECT ON tabla_123 to PUBLIC;

-- CREATE OR REPLACE PROCEDURE num_of_rows IS 
-- ...
-- SET SERVEROUTPUT ON
-- EXECUTE num_of_rows();

-- Megjegyzés:
-- Egy lehetséges megoldás, ha lekérdezzük a táblához tartozó összes adatblokk fájl- és blokkazonosítóját,
-- majd ciklusban egyesével lekérdezzük, hogy hány sor van az adott blokkban.
-- Ez a megoldás nagyobb méretû táblára nagyon-nagyon lassú lesz, nem fog lefutni elfogadható idõn belül.

-- Futtassuk le az alábbi utasításokat és nézzük meg, mitörténik a sorazonosítókkal:
-- CREATE TABLE test123(col1 INT, col2 VARCHAR(20));
-- INSERT INTO test123 VALUES(1,'text1');
-- INSERT INTO test123 VALUES(2,'text2');
-- INSERT INTO test123 VALUES(3,'text3');
-- DELETE FROM test123 WHERE col1=2;
-- INSERT INTO test123 VALUES(4,'text4');
-- SELECT col2, dbms_rowid.rowid_relative_fno(ROWID) fnum, dbms_rowid.rowid_block_number(ROWID) bnum,
--        dbms_rowid.rowid_row_number(ROWID) rnum
-- FROM TEST123;
-- ---------------------
-- text1  2   369523  0
-- text3  2   369523  2
-- text4  2   369523  3

-- ========================================================
-- 6.
-- További példák a ROWID használatára
-- -----------------------------------
-- Hozzunk letre egy EXCEPTIONS nevu tablat az utlexcpt.sql nevu script 
-- alapjan, majd egy olyan constraintet, amelyet a tablaban levo sorok
-- kozul nehany megsert. (Emiatt a constraint letrehozasa hibauzenetet
-- kell, hogy eredmenyezzen.) Allapitsuk meg az EXCEPTIONS nevu tabla 
-- segitsegevel, hogy mely sorok sertik meg az imenti constraintet. 

-- Az utlexcpt.sql nevû script a következõ utasítást tartalmazza:

-- CREATE TABLE exceptions(row_id rowid, owner varchar2(30),
--     table_name varchar2(30), constraint varchar2(30));


-- ------------------------------------------------------------------------
-- A fenti megoldását lásd az ab2_oracle.docx állományban, kb. a 10. oldalon