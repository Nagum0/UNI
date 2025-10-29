-- Feladat plusz pontokért (részleteket lásd --> zh1_info.txt a Teams-ben)
-- -----------------------------------------------------------------------
-- Írják meg az alábbi, 5. feladatban szereplő NUM_OF_ROWS nevű procedúrát.
-- Azt, hogy az output helyes-e ellenőrizni tudják a feladat után megadott 'CHECK_PLSQL'
-- procedúra futtatásával.

-- Határidő: a következő gyakorlat kezdete.
-- ===========================================================================

-- Példa:
-- Az alábbi egy példa, amely bemutatja, hogy mennyit tudnak javítani a lekérdezések hatékonyságán a
-- különböző indexek. A múlt heti feladatsorban (ab2_feladat2.txt) szerepelt egy time_limit nevű procedúra.
-- Futtassuk le a procedúrát, majd hozzunk létre egy indexet és futtassuk újra. 
-- Hasonlítsuk össze a futási időket.

-- set serveroutput on
-- execute time_limit(2); 
-- CREATE INDEX customers_idx ON customers(cust_id);       -- indexet hozunk létre
-- execute time_limit(2); 
-- DROP INDEX customers_idx;                               -- eldobjuk az indexet
-- -----------------------------------------------------------------------

-- Papíron megoldandó feladat
-- ==========================

-- Kiterjeszthető hasító index (segítség: UW_dinamikus_tordeles.docx)
-- ---------------------------
-- A kosártömb mérete mindig pontosan 2**i.
-- Tegyük fel, hogy egy blokkba 2 rekord fér el, j értéke (a blokkok jobb oldalán) azt jelzi, 
-- hogy hány bit használatos a blokkhoz tartozás eldöntésére.

-- i=1
--   ----       
-- 0 | -|-->  [0001](1) 
--   |  |             
-- 1 | -|-->  [1001,1100](1) 
--   ----                  
-- kosártömb  adatblokkok

-- Szúrjuk be az alábbi hasító értékkel rendelkező sorokat egymás után, és minden 
-- újabb blokk létrehozása után rajzoljuk újra a kosártömböt és a blokkokat. 

-- 0011, 0110, 1011, 0111, 1110, 1111, 0100


-- Egy kis segítség:
-- ----------------

-- A K kulcsú rekordot h(K) első i bitje alapján helyezzük el úgy, hogy követjük 
-- a kosártömb ezen bejegyzéséhez tartozó mutatót.
-- Ha nincs hely a megtalált blokkban akkor a következőt tesszük:
-- 1. Ha j < i akkor újabb blokkot hozunk létre és a j+1-edik bit alapján kettéosztjuk a 
--    rekordokat a két blokk között (mindkét blokkra j+1 lesz az új érték), majd 
--    a kosártömb szükséges mutatóit az új blokkra irányítjuk.
-- 2. Ha j = i akkor először i-t növeljük 1-gyel, megduplázzuk a kosártömböt, új mutatókat
--    teszünk bele, majd alkalmazzuk 1.-et.


-- Lineáris hasító index 
-- ---------------------
-- Tegyük fel, hogy egy blokkba 2 rekord fér el és a kosarak az alábbi rekordokat tartalmazzák:

-- 0 --> [0000,1110]
-- 1 --> [0101]

-- Az előre megadott küszöbszám (rekordok száma/kosarak száma) legyen 2,4.
-- Jelenleg i=1, n=2 (n: a kosarak száma), m=1 (m: a legnagyobb használt kosárindex)

-- Szúrjuk be az alábbi hasító értékkel rendelkező sorokat egymás után, és minden 
-- újabb kosár megnyitás után rajzoljuk újra a kosarakat. 

-- 0001, 0110, 1011, 0111, 1100, 1111, 1000

-- A kosarakat 0-tól indexeljük, és a kosár sorszámát binárisan ábrázoljuk, vagyis
-- majd a 2. kosár -> 10, 3. kosár -> 11, 9. kosár -> 1001 stb.
-- Az előre megadott küszöbszám (rekordok száma/kosarak száma) legyen 2,4.
-- Jelenleg m = 1 (a legnagyobb használt kosárindex)

-- Szúrjuk be az alábbi hasító értékkel rendelkező sorokat egymás után, és minden 
-- újabb kosár megnyitás után rajzoljuk újra a kosarakat. 

-- 0001, 0110, 1011, 0111, 1100, 1111, 1000


-- Egy kis segítség:
-- ----------------

-- Ha n kosarunk van, akkor a K kulcsú rekordot h(K) utolsó i bitje alapján tesszük a 
-- megfelelő kosárba (i=log2n, illetve annak felső egész része). 
-- Ha nincs benne hely, akkor újabb blokkot láncolunk ehhez a kosárhoz.
-- Ha nincs ilyen kosár, akkor az első bitben különböző kosárba tesszük. (1xxxx helyett 0xxxx-be)
-- Ha az előre megadott küszöböt átléptük, akkor új kosarat nyitunk és esetlegesen 
--  átpakoljuk a szükséges rekordokat az új kosárba.
-- Szükség esetén növeljük i-t. A kosarak sorszáma: 0,1,2,3,4 ... (binárisan ábrázolva).


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
-- A NIKOVITS felhasználó CIKK táblája hány blokkot foglal az adatbázisban? (blokkszám)
-- (Vagyis hány olyan blokk van, ami ennek a táblának a szegmenséhez tartozik és így már 
-- más táblához nem rendelhető hozzá?)

SELECT SUM(blocks)
FROM DBA_EXTENTS
WHERE owner='NIKOVITS'
AND segment_name='CIKK'
AND segment_type='TABLE'
GROUP BY segment_name;

-- 2.
-- A NIKOVITS felhasználó CIKK táblájának adatai hány blokkban helyezkednek el? (blokkszám)
-- (Vagyis a tábla sorai ténylegesen hány blokkban vannak tárolva?)
-- !!! -> Ez a kérdés nem ugyanaz mint az előző, mert a tábla blokkjai lehetnek üresek is.

SELECT blocks
FROM DBA_TABLES
WHERE owner='NIKOVITS'
AND TABLE_NAME='CIKK';

-- 3.
-- Az egyes blokkokban hány sor van? (file_id, blokk_id, darab)

SELECT 
    DBMS_ROWID.ROWID_RELATIVE_FNO(rowid) AS file_id,
    DBMS_ROWID.ROWID_BLOCK_NUMBER(rowid) AS block_id,
    COUNT(*) AS darab
FROM NIKOVITS.CIKK
GROUP BY 
    DBMS_ROWID.ROWID_RELATIVE_FNO(rowid),
    DBMS_ROWID.ROWID_BLOCK_NUMBER(rowid)
ORDER BY file_id, block_id;

-- ------------------------------------------------------------------------------------------
-- Hozzunk létre egy CIKK_PROBA nevű táblát az EXAMPLE táblatéren, amelynek szerkezete azonos 
-- a nikovits.cikk tábláéval és pontosan 128 KB helyet foglal az adatbázisban. Foglaljunk le 
-- manuálisan további 128 KB helyet a táblához. Vigyünk fel sorokat addig, amig az első blokk 
-- tele nem lesz, és 1 további sora lesz még a táblának a második blokkban.
-- (A felvitelt plsql programmal végezzük és ne kézzel, mert úgy kicsit sokáig tartana.)

-- Próbáljuk ki az előzőt ismét, de most a PCTFREE értéket állítsuk 40-re. 
-- Mindkét esetben ellenőrizzük is, hogy a sorok tényleg két blokkban vannak,
-- és a másodikban csak egyetlen sor van.
-- ------------------------------------------------------------------------------------------

DROP TABLE UJCIKK;

CREATE TABLE UJCIKK
TABLESPACE EXAMPLE
AS
SELECT *
FROM NIKOVITS.CIKK 
WHERE 0=1;

CREATE TABLE UJCIKK
TABLESPACE EXAMPLE
STORAGE (INITIAL 128K)
AS
SELECT *
FROM NIKOVITS.CIKK 
WHERE 0=1;

select * from dba_tables where owner='UAUYQF' and table_name='UJCIKK';
select * from dba_segments where owner='UAUYQF' and segment_name='UJCIKK';

ALTER TABLE UJCIKK
ALLOCATE EXTENT (SIZE 128K);

/
declare
x number;
begin
    for i in 1..1000 loop
        insert into ujcikk select * from nikovits.cikk where i=ckod;
        select count(distinct substr(rowid,1,15)) into x from ujcikk;
        exit when x>1;  -- if x>1 then exit; end if;
    end loop;
commit;
end;
/

SELECT * FROM UJCIKK;

-- 4. (csak Ullman)
-- Állapítsuk meg, hogy a NIKOVITS.ELADASOK táblának a következő adatokkal azonosított sora
-- (szla_szam=100) melyik adatfájlban van, azon belül melyik blokkban, és a blokkon belül hányadik a sor?
-- (file_név, blokk_id, sorszám)

SELECT 
    df.file_name,
    DBMS_ROWID.ROWID_BLOCK_NUMBER(e.rowid) AS blokk_id,
    DBMS_ROWID.ROWID_ROW_NUMBER(e.rowid) AS sorszam
FROM NIKOVITS.ELADASOK e
JOIN DBA_DATA_FILES df
ON DBMS_ROWID.ROWID_RELATIVE_FNO(e.rowid) = df.file_id
WHERE e.szla_szam = 100;

-- Az előző feladatban megadott sor melyik adatobjektumban van? (objektum_név)
-- Mennyi az objektum azonosítója, és ez milyen objektum? (obj_id, obj_név)

SELECT o.object_name
FROM NIKOVITS.ELADASOK e
JOIN DBA_OBJECTS o
ON DBMS_ROWID.ROWID_OBJECT(e.rowid)=o.object_id
WHERE e.szla_szam=100;

SELECT o.object_name, o.object_id, o.object_type
FROM NIKOVITS.ELADASOK e
JOIN DBA_OBJECTS o
ON DBMS_ROWID.ROWID_OBJECT(e.rowid)=o.object_id
WHERE e.szla_szam=100;

-- -----------------------------------------------------------------------
-- 5.
-- Írjunk meg egy PLSQL procedúrát, amelyik kiírja, hogy a NIKOVITS.TABLA_123 táblának melyik 
-- adatblokkjában hány sor van. Az output formátuma soronként: FILE_ID; BLOKK_ID -> darab;
-- Példa az output egy sorára: 2;563->306;
-- Vigyázat!!! Azokat az adatblokkokat is ki kell írni, amelyekben a sorok száma 0, de a tábla
-- szegmenséhez tartoznak. Az output FILE_ID majd azon belül BLOKK_ID szerint legyen rendezett.

-- CREATE OR REPLACE PROCEDURE num_of_rows IS 
-- ...
-- SET SERVEROUTPUT ON
-- EXECUTE num_of_rows();

-- Ellenőrzés:
-- ----------
-- EXECUTE check_plsql('num_of_rows()');
-- -----------------------------------------------------------------------

-- További példák a ROWID használatára
-- -----------------------------------
-- 6.
-- Hozzunk létre egy EXCEPTIONS nevű táblát az utlexcpt.sql nevű script (lásd alább)
-- alapján, majd egy olyan constraintet, amelyet a táblában levő sorok
-- közül néhány megsért. (Emiatt a constraint létrehozása hibaüzenetet
-- kell, hogy eredményezzen.) Állapitsuk meg az EXCEPTIONS nevű tábla 
-- segitségével, hogy mely sorok sértik meg az iménti constraintet. 

-- Az utlexcpt.sql nevű script a következő utasítást tartalmazza:

-- CREATE TABLE exceptions(row_id rowid, owner varchar2(30),
--     table_name varchar2(30), constraint varchar2(30));

-- Segítség
-- --------
-- A fenti feladat megoldása megtalálható az ab2_oracle.docx állományban a 10. oldalon.