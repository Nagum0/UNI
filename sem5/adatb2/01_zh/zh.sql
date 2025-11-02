-- -------------------------------------------------------------------------------------------------------------
-- GYAK 02
-- Adattárolással kapcsolatos fogalmak
-- -----------------------------------
-- (DBA_TABLES, DBA_DATA_FILES, DBA_TEMP_FILES, DBA_TABLESPACES, DBA_SEGMENTS, DBA_EXTENTS, DBA_FREE_SPACE)

SELECT * FROM DBA_TABLES;
SELECT * FROM DBA_DATA_FILES;
SELECT * FROM DBA_TEMP_FILES;
SELECT * FROM DBA_TABLESPACES;
SELECT * FROM DBA_SEGMENTS;
SELECT * FROM DBA_EXTENTS;
SELECT * FROM DBA_FREE_SPACE;

-- 1.
-- Adjuk meg az adatbázishoz tartozó adatfile-ok (és temporális fájlok) nevét és méretét
-- méret szerint csökkenő sorrendben. (név, méret)

SELECT FILE_NAME, BYTES
FROM DBA_DATA_FILES
UNION
SELECT FILE_NAME, BYTES
FROM DBA_TEMP_FILES
ORDER BY BYTES DESC;


-- 2.
-- Adjuk meg, hogy milyen táblaterek vannak létrehozva az adatbazisban,
-- az egyes táblaterek hány adatfájlbol állnak, és mekkora az összméretük.
-- (tablater_nev, fajlok_szama, osszmeret)
-- !!! Vigyázat, van temporális táblatér is.

SELECT TABLESPACE_NAME, COUNT(*), SUM(BYTES)
FROM DBA_DATA_FILES
GROUP BY TABLESPACE_NAME
UNION
SELECT TABLESPACE_NAME, COUNT(*), SUM(BYTES)
FROM DBA_TEMP_FILES
GROUP BY TABLESPACE_NAME;

-- 3.
-- Mekkora az adatblokkok merete a USERS táblatéren?

SELECT BLOCK_SIZE
FROM DBA_TABLESPACES;

-- 4.
-- Van-e olyan táblatér, amelynek nincs DBA_DATA_FILES-beli adatfájlja?
-- Ennek adatai hol tárolódnak? -> DBA_TEMP_FILES

SELECT TABLESPACE_NAME
FROM DBA_TABLESPACES
MINUS
SELECT TABLESPACE_NAME
FROM DBA_DATA_FILES;

-- 5.
-- Melyik a legnagyobb méretű tábla szegmens az adatbázisban és hány extensből áll? 
-- (tulajdonos, szegmens_név, darab)
-- (A particionált táblákat most ne vegyük figyelembe, ezekről majd később lesz szó.)

SELECT OWNER, SEGMENT_NAME, EXTENTS
FROM DBA_SEGMENTS
WHERE SEGMENT_TYPE='TABLE'
ORDER BY BYTES DESC
FETCH FIRST 1 ROW ONLY;

-- 6.
-- Melyik a legnagyobb meretű index szegmens az adatbázisban és hány blokkból áll?
-- (tulajdonos, szegmens_név, darab)
-- (A particionalt indexeket most ne vegyük figyelembe.)

SELECT OWNER, SEGMENT_NAME, BLOCKS
FROM DBA_SEGMENTS
WHERE SEGMENT_TYPE='INDEX'
ORDER BY BYTES DESC
FETCH FIRST 1 ROW ONLY;

-- 7.
-- Adjuk meg adatfájlonkent, hogy az egyes adatfájlokban mennyi a foglalt 
-- hely osszesen. (fájlnév, fájl_méret, foglalt_hely)

SELECT df.FILE_NAME, df.BYTES, SUM(de.BYTES)
FROM DBA_DATA_FILES df
JOIN DBA_EXTENTS de
ON df.FILE_ID=de.FILE_ID
GROUP BY df.FILE_NAME, df.BYTES;

-- 8.
-- Melyik két felhasználó objektumai foglalnak összesen a legtöbb helyet az adatbázisban?
-- Vagyis ki foglal a legtöbb helyet, és ki a második legtöbbet?

SELECT OWNER
FROM DBA_EXTENTS
GROUP BY OWNER, SEGMENT_NAME
ORDER BY SUM(BYTES) DESC
FETCH FIRST 2 ROWS ONLY;

-- 9.
-- Hány extens van a 'users02.dbf' adatfájlban? Mekkora ezek összmérete? (darab, össz)

SELECT df.FILE_NAME, SUM(de.BYTES)
FROM DBA_DATA_FILES df
JOIN DBA_EXTENTS de
ON df.FILE_ID=de.FILE_ID
WHERE df.FILE_NAME LIKE '%users02.dbf%'
GROUP BY df.FILE_NAME;

-- Hány összefüggő szabad terület van a 'users02.dbf' adatfájlban? Mekkora ezek összmérete? (darab, össz)

SELECT df.FILE_NAME, SUM(dfs.BYTES)
FROM DBA_DATA_FILES df
JOIN DBA_FREE_SPACE dfs
ON df.FILE_ID=dfs.FILE_ID
WHERE df.FILE_NAME LIKE '%users02.dbf%'
GROUP BY df.FILE_NAME;

-- Hány százalékban foglalt a 'users02.dbf' adatfájl?

-- 10.
-- Van-e a NIKOVITS felhasználónak olyan táblája, amelyik több adatfájlban is foglal helyet?

SELECT SEGMENT_NAME
FROM DBA_EXTENTS
WHERE OWNER='NIKOVITS'
AND SEGMENT_TYPE='TABLE'
GROUP BY SEGMENT_NAME
HAVING COUNT(DISTINCT FILE_ID) > 1;

-- 11.
-- Válasszunk ki a fenti táblákból egyet (pl. tabla_123) és adjuk meg, hogy ez a 
-- tábla mely adatfájlokban foglal helyet.

SELECT df.FILE_NAME
FROM DBA_DATA_FILES df
JOIN DBA_EXTENTS de
ON df.FILE_ID=de.FILE_ID
WHERE de.OWNER='NIKOVITS'
AND de.SEGMENT_NAME='TABLA_123';

-- 12.
-- Melyik táblatéren van az ORAUSER felhasználó DOLGOZO táblája? (táblatér)

SELECT TABLESPACE_NAME
FROM DBA_SEGMENTS
WHERE OWNER='ORAUSER'
AND SEGMENT_NAME='DOLGOZO';

-- 13.
-- Melyik táblatéren van a NIKOVITS felhasználó ELADASOK táblája? (táblatér)
-- (Miért lesz null?)

-- -------------------------------------------------------------------------------------------------------------
-- GYAK 03
-- 1.
-- A NIKOVITS felhasználó CIKK táblája hány blokkot foglal az adatbázisban? (blokkszám)
-- (Vagyis hány olyan blokk van, ami ennek a táblának a szegmenséhez tartozik és így már 
-- más táblához nem rendelhető hozzá?)

SELECT BLOCKS
FROM DBA_SEGMENTS
WHERE OWNER='NIKOVITS'
AND SEGMENT_NAME='CIKK';

-- 2.
-- A NIKOVITS felhasználó CIKK táblájának adatai hány blokkban helyezkednek el? (blokkszám)
-- (Vagyis a tábla sorai ténylegesen hány blokkban vannak tárolva?)
-- !!! -> Ez a kérdés nem ugyanaz mint az előző, mert a tábla blokkjai lehetnek üresek is.

WITH BLOCKS AS (
    SELECT DISTINCT DBMS_ROWID.ROWID_BLOCK_NUMBER(ROWID)
    FROM NIKOVITS.CIKK
)
SELECT COUNT(*)
FROM BLOCKS;

-- 3.
-- Az egyes blokkokban hány sor van? (file_id, blokk_id, darab)

SELECT DBMS_ROWID.ROWID_BLOCK_NUMBER(ROWID), COUNT(DBMS_ROWID.ROWID_ROW_NUMBER(ROWID))
FROM NIKOVITS.CIKK
GROUP BY DBMS_ROWID.ROWID_BLOCK_NUMBER(ROWID);

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

CREATE TABLE CIKK_PROBA 
TABLESPACE EXAMPLE
STORAGE (INITIAL 128K)
AS SELECT * FROM NIKOVITS.CIKK;

SELECT *
FROM DBA_EXTENTS
WHERE OWNER='UAUYQF'
AND SEGMENT_NAME='CIKK_PROBA';

ALTER TABLE CIKK_PROBA
ALLOCATE EXTENT (SIZE 128K);

-- 4. (csak Ullman)
-- Állapítsuk meg, hogy a NIKOVITS.ELADASOK táblának a következő adatokkal azonosított sora
-- (szla_szam=100) melyik adatfájlban van, azon belül melyik blokkban, és a blokkon belül hányadik a sor?
-- (file_név, blokk_id, sorszám)

SELECT
    DBMS_ROWID.ROWID_RELATIVE_FNO(ROWID),
    DBMS_ROWID.ROWID_BLOCK_NUMBER(ROWID),
    DBMS_ROWID.ROWID_ROW_NUMBER(ROWID)
FROM NIKOVITS.ELADASOK
WHERE SZLA_SZAM=100;

-- -------------------------------------------------------------------------------------------------------------
-- GYAK 04
-- (DBA_INDEXES, DBA_IND_COLUMNS, DBA_IND_EXPRESSIONS)

SELECT * FROM DBA_INDEXES WHERE OWNER='UAUYQF';
SELECT * FROM DBA_IND_COLUMNS;
SELECT * FROM DBA_IND_EXPRESSIONS;

-- Hozzunk létre egy vagy több táblához több különböző indexet, legyen köztük több oszlopos,
-- csökkenő sorrendű, bitmap, függvény alapú stb. (Ehhez használhatók az ab2_oracle.docx
-- állományban szereplő példák, vagy a cr_index.txt-ben szereplők.)
-- Az alábbi lekérdezésekkel megállapítjuk az iménti indexeknek mindenféle tulajdonságait a 
-- katalógusokból.

-- 1.
-- Adjuk meg azoknak a tábláknak a nevét, amelyeknek van csökkenő sorrendben indexelt oszlopa.

SELECT TABLE_NAME
FROM DBA_IND_COLUMNS
WHERE DESCEND='DESC';

-- Miért ilyen furcsa az oszlopnév? Mi az oszlop tényleges neve?
-- -> lásd DBA_IND_EXPRESSIONS

-- 2.
-- Adjuk meg azoknak az indexeknek a nevét, amelyek legalább 9 oszloposak.
-- (Vagyis a táblának legalább 9 oszlopát vagy egyéb kifejezését indexelik.)

SELECT INDEX_NAME
FROM DBA_IND_COLUMNS
GROUP BY INDEX_OWNER, INDEX_NAME
HAVING COUNT(*) >= 9;

-- 3.
-- Adjuk meg a NIKOVITS.CUSTOMERS táblára létrehozott bitmap indexek nevét.

SELECT INDEX_NAME
FROM DBA_INDEXES
WHERE OWNER='NIKOVITS'
AND TABLE_NAME='CUSTOMERS'
AND TABLE_TYPE='TABLE'
AND INDEX_TYPE='BITMAP';

-- 4.
-- Adjuk meg azon kétoszlopos indexek nevét és tulajdonosát, amelyeknek legalább 
-- az egyik kifejezése függvény alapú.

SELECT di.OWNER, di.INDEX_NAME
FROM DBA_INDEXES di
JOIN DBA_IND_COLUMNS dic
ON di.INDEX_NAME=dic.INDEX_NAME
AND di.OWNER=dic.INDEX_OWNER
WHERE di.INDEX_TYPE LIKE '%FUNCTION-BASED%'
GROUP BY di.OWNER, di.INDEX_NAME
HAVING COUNT(*)=2;

-- 5.
-- Adjuk meg az egyikükre, pl. a NIKOVITS felhasználó tulajdonában lévőre, hogy milyen kifejezések szerint 
-- vannak indexelve a soraik. (Vagyis mi a függvény/kifejezés, ami alapján a bejegyzések készülnek.)

SELECT COLUMN_EXPRESSION
FROM DBA_IND_EXPRESSIONS
WHERE INDEX_OWNER='NIKOVITS';

-- -------------------------------------------------------------------------------------------------------------
-- GYAK 05
-- Index-szervezett tábla
-- ----------------------
-- 1.
-- Adjuk meg a NIKOVITS felhasználó tulajdonában levő index-szervezett táblák nevét.
-- (Melyik táblatéren vannak ezek a táblák? -> miért nem látható?)

SELECT TABLE_NAME
FROM DBA_TABLES
WHERE OWNER='NIKOVITS'
AND IOT_TYPE='IOT';

-- 2.
-- Adjuk meg a fenti táblák index részét, és azt, hogy ezek az index részek (szegmensek) 
-- melyik táblatéren vannak?

SELECT INDEX_NAME, TABLESPACE_NAME
FROM DBA_INDEXES
WHERE OWNER='NIKOVITS'
AND INDEX_TYPE LIKE '%IOT%TOP%';

-- 3.
-- Keressük meg a szegmensek között az előző táblákat illetve indexeket, és adjuk
-- meg a nevüket és méretüket.

SELECT ds.SEGMENT_NAME, ds.BYTES
FROM DBA_SEGMENTS ds
JOIN DBA_INDEXES di
ON ds.OWNER=di.OWNER
AND ds.SEGMENT_NAME=di.INDEX_NAME
WHERE di.OWNER='NIKOVITS'
AND di.INDEX_TYPE LIKE '%IOT%TOP%';

-- 4.
-- Keressük meg az adatbázis objektumok között a fenti táblákat és indexeket, és adjuk
-- meg az objektum azonosítójukat és adatobjektum azonosítójukat (DATA_OBJECT_ID).

SELECT dbo.OBJECT_NAME, dbo.OBJECT_ID, dbo.DATA_OBJECT_ID
FROM DBA_OBJECTS dbo
JOIN DBA_INDEXES di
ON dbo.OWNER=di.OWNER
AND dbo.OBJECT_NAME=di.INDEX_NAME
WHERE dbo.OWNER='NIKOVITS'
AND di.INDEX_TYPE LIKE '%IOT%TOP%';

-- 5.
-- Adjuk meg a fenti táblák túlcsordulási (OVERFLOW) részeit (ha van).

SELECT *
FROM DBA_TABLES
WHERE OWNER='NIKOVITS'
AND IOT_TYPE='IOT_OVERFLOW';

-- 6.
-- Keressük meg a túlcsordulási részeket a szegmensek között és adjuk meg a méretüket.

SELECT ds.SEGMENT_NAME, ds.BYTES
FROM DBA_SEGMENTS ds
JOIN DBA_TABLES dt
ON ds.OWNER=dt.OWNER
AND ds.SEGMENT_NAME=dt.TABLE_NAME
WHERE ds.OWNER='NIKOVITS'
AND dt.IOT_TYPE='IOT_OVERFLOW';

-- 7.
-- Keressük meg a NIKOVITS.CIK_IOT index szervezett tábla részeit 
-- (tábla szegmens, túlcsordulási szegmens, a tábla indexei), adjuk meg az
-- objektum azonosítóikat és az adatobjektum azonosítóikat.
-- (object_name, object_type, object_id, data_object_id)

-- 8.
-- Adjuk meg azokat az index szervezett táblákat, amelyeknek pontosan 
-- 1 dátum (DATE) típusú oszlopa van. (owner, table_name)

-- Partícionálás
-- -------------
-- (DBA_PART_TABLES, DBA_PART_INDEXES, DBA_TAB_PARTITIONS, DBA_IND_PARTITIONS, 
-- DBA_TAB_SUBPARTITIONS, DBA_IND_SUBPARTITIONS, DBA_PART_KEY_COLUMNS)

-- 1.
-- Adjuk meg a NIKOVITS felhasználó tulajdonában levő partícionált táblák nevét és a 
-- particionálás típusát. (táblanév, típus)
-- 2.
-- Soroljuk fel a NIKOVITS.ELADASOK tábla partícióit valamint, hogy hány blokkot foglalnak
-- az egyes partíciók. (név, blokkok)
-- (Vigyázat! Egyes adatszótárak csak becsült méretet tartalmaznak. Ne azt adják meg.
-- A pontos méreteket az extenseknél és szegmenseknél keressük.)
-- 3.
-- Adjuk meg, hogy a NIKOVITS.ELADASOK tábla mely oszlop(ok) szerint van particionálva, valamint 
-- adjuk meg az oszlopok sorrendjét a partícionáló oszlopokon belül. (oszlop, sorrend)
-- 4.
-- Adjuk meg, hogy a NIKOVITS.ELADASOK3 tábla második partíciójában milyen értékek szerepelhetnek. (érték)
-- 5.
-- Adjuk meg egy partícionált tábla (pl. NIKOVITS.ELADASOK) logikai és fizikai részeit.
--    (object_name, object_type, subobject_name, object_id, data_object_id) 
-- Maga a tábla most is logikai objektum, a partíciói vannak fizikailag tárolva.
-- Nézzük meg az objektumok (DBA_OBJECTS) és a szegmensek (DBA_SEGMENTS) között is.
-- 6.
-- Illetve ha alpartíciói is vannak (pl. nikovits.eladasok4), akkor csak az alpartíciók 
-- vannak tárolva. (object_name, object_type, subobject_name, object_id, data_object_id)
-- Nézzük meg az objektumok és a szegmensek között is.
-- (segment_name, segment_type, bytes)

-- Klaszter (CLUSTER)
-- ------------------
-- (DBA_CLUSTERS, DBA_CLU_COLUMNS, DBA_TABLES, DBA_CLUSTER_HASH_EXPRESSIONS)

-- Hozzunk létre egy DOLGOZO(dazon, nev, beosztas, fonoke, fizetes, oazon ... stb.) 
-- és egy OSZTALY(oazon, nev, telephely ... stb.) nevű táblát. 
-- (lásd NIKOVITS.DOLGOZO és NIKOVITS.OSZTALY)
-- A két táblának az osztály azonosítója (oazon) lesz a közös oszlopa. A két táblát 
-- egy index alapú CLUSTEREN hozzuk létre. (Előbb persze létre kell hozni a clustert is.)
-- Majd tegyünk bele 3 osztályt, és osztályonként két dolgozót.

-- 1.
-- Adjunk meg egy olyan clustert az adatbázisban (ha van ilyen), amelyen még nincs
-- egy tábla sem. (tulajdonos, klaszternév)

-- 2.
-- Adjunk meg egy olyant, amelyiken pontosan 2 tábla van. (tulajdonos, klaszternév)

-- 3.
-- Adjunk meg egy olyan clustert, amelynek a cluster kulcsa 3 oszlopból áll.
-- Vigyázat, több tábla is lehet rajta!!! (tulajdonos, klaszternév)

-- 4.
-- HASH CLUSTER
-- Hány olyan hash cluster van az adatbázisban, amely nem az oracle alapértelmezés 
-- szerinti hash függvényén alapul? (darab)

-- 5.
-- Hozzunk létre egy hash clustert és rajta két táblát, majd szúrjunk be a 
-- táblákba sorokat úgy, hogy a két táblának 2-2 sora ugyanabba a blokkba 
-- kerüljön. Ellenőrizzük is egy lekérdezéssel, hogy a 4 sor valóban ugyanabban 
-- a blokkban van-e. (A ROWID lekérdezésével)
-- TIPP: A sorok elhelyezését befolyásolni tudjuk a HASH IS megadásával.

-- 6.
-- Írjunk meg egy PL/SQL procedúrát, amely kiírja egy tábla tárolási módját (HEAP, PARTITION, IOT, CLUSTER) 
-- Az output formája: Clustered: NO Partitioned: YES IOT: NO