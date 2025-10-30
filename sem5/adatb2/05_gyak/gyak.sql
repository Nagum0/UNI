-- Kötelező feladat az 5. gyakorlathoz
-- ------------------------------------------
-- Készítsék el az alábbi (Pratícionált tábláknál szereplő) 8. feladatban megadott EMPTY_BLOCKS nevű procedúrát.
-- Azt, hogy az output helyes-e ellenőrizni tudják a feladat után megadott 'CHECK_PLSQL' procedúra futtatásával.
-- ===========================================================================

-- Index-szervezett tábla
-- ----------------------
-- 1.
-- Adjuk meg a NIKOVITS felhasználó tulajdonában levő index-szervezett táblák nevét.
-- (Melyik táblatéren vannak ezek a táblák? -> miért nem látható?)

SELECT table_name
FROM DBA_INDEXES
WHERE owner='NIKOVITS'
AND index_type LIKE '%IOT%';

-- 2.
-- Adjuk meg a fenti táblák index részét, és azt, hogy ezek az index részek (szegmensek) 
-- melyik táblatéren vannak?

SELECT di.index_name, ds.tablespace_name
FROM DBA_INDEXES di
JOIN DBA_SEGMENTS ds
ON ds.segment_name=di.index_name
AND di.owner=ds.owner
WHERE di.owner='NIKOVITS'
AND di.index_type LIKE '%IOT%';

-- 3.
-- Keressük meg a szegmensek között az előző táblákat illetve indexeket, és adjuk
-- meg a méretüket.

-- 4.
-- Keressük meg az adatbázis objektumok között a fenti táblákat és indexeket, és adjuk
-- meg az objektum azonosítójukat és adatobjektum azonosítójukat (DATA_OBJECT_ID).

-- 5.
-- Adjuk meg a fenti táblák túlcsordulási részeit (ha van).

-- 6.
-- Keressük meg a túlcsordulási részeket a szegmensek között és adjuk meg a méretüket.

-- 7.
-- Keressük meg a NIKOVITS.CIK_IOT index szervezett tábla részeit 
-- (tábla szegmens, túlcsordulási szegmens, a tábla indexei), adjuk meg az
-- objektum azonosítóikat és az adatobjektum azonosítóikat.
-- (object_name, object_type, object_id, data_object_id)

-- 8.
-- Adjuk meg azokat az index szervezett táblákat, amelyeknek pontosan 
-- 1 dátum típusú oszlopa van. (owner, table_name)

-- 9.
-- Írjunk meg egy plsql procedúrát, amelyik a paraméterül kapott index szervezett 
-- tábláról kiírja a tábla méretét. 
-- Vigyázzunk, mert a táblának lehet index és túlcsordulási szegmense is!
-- CREATE OR REPLACE PROCEDURE iot_size(p_owner VARCHAR2, p_table VARCHAR2) IS 
-- ...
-- SET SERVEROUTPUT ON
-- EXECUTE iot_size('nikovits', 'cikk_iot');
-- -----------------------------------------------------------------------

-- Partícionálás
-- -------------
-- (DBA_PART_TABLES, DBA_PART_INDEXES, DBA_TAB_PARTITIONS, DBA_IND_PARTITIONS, 
-- DBA_TAB_SUBPARTITIONS, DBA_IND_SUBPARTITIONS, DBA_PART_KEY_COLUMNS)

SELECT * FROM DBA_PART_TABLES;
SELECT * FROM DBA_PART_INDEXES;
SELECT * FROM DBA_TAB_PARTITIONS;

-- 1.
-- Adjuk meg a NIKOVITS felhasználó tulajdonában levő partícionált táblák nevét és a 
-- particionálás típusát. (táblanév, típus)

SELECT table_name, partitioning_type
FROM DBA_PART_TABLES
WHERE owner='NIKOVITS';

-- 2.
-- Soroljuk fel a NIKOVITS.ELADASOK tábla partícióit valamint, hogy hány blokkot foglalnak
-- az egyes partíciók. (név, blokkok)
-- (Vigyázat! Egyes adatszótárak csak becsült méretet tartalmaznak.
-- A pontos méreteket az extenseknél és szegmenseknél keressük.)

SELECT partition_name, blocks
FROM DBA_EXTENTS
WHERE owner='NIKOVITS'
AND segment_name='ELADASOK'
AND partition_name IS NOT NULL;

-- 3.
-- Adjuk meg, hogy a NIKOVITS.ELADASOK tábla mely oszlop(ok) szerint van particionálva, valamint 
-- adjuk meg az oszlopok sorrendjét a partícionáló oszlopokon belül. (oszlop, sorrend)

SELECT * 
FROM DBA_PART_KEY_COLUMNS
WHERE owner='NIKOVITS'
AND name='ELADASOK'
AND object_type='TABLE'
ORDER BY column_position;

-- 4.
-- Adjuk meg, hogy a NIKOVITS.ELADASOK3 tábla második partíciójában milyen értékek szerepelhetnek. (érték)

SELECT high_value
FROM DBA_TAB_PARTITIONS
WHERE table_owner='NIKOVITS'
AND table_name='ELADASOK3'
AND partition_position=2;

-- 5.
-- Adjuk meg egy partícionált tábla (pl. NIKOVITS.ELADASOK) logikai és fizikai részeit.
--    (object_name, object_type, subobject_name, object_id, data_object_id) 
-- Maga a tábla most is logikai objektum, a partíciói vannak fizikailag tárolva.
-- Nézzük meg az objektumok és a szegmensek között is.

SELECT object_name, object_type, subobject_name, object_id, data_object_id
FROM DBA_OBJECTS
WHERE owner='NIKOVITS'
AND object_name='ELADASOK'
AND object_type='TABLE PARTITION';

SELECT *
FROM DBA_SEGMENTS
WHERE owner='NIKOVITS'
AND segment_name='ELADASOK'
AND segment_type='TABLE PARTITION';

-- 6.
-- Illetve ha alpartíciói is vannak (pl. nikovits.eladasok4), akkor csak az alpartíciók 
-- vannak tárolva. (object_name, object_type, subobject_name, object_id, data_object_id)
-- Nézzük meg az objektumok és a szegmensek között is.
-- (segment_name, segment_type, bytes)

SELECT *
FROM DBA_TAB_PARTITIONS
WHERE table_owner='NIKOVITS'
AND table_name='ELADASOK4';

SELECT *
FROM DBA_TAB_SUBPARTITIONS
WHERE table_owner='NIKOVITS'
AND table_name='ELADASOK4';

-- 7.
-- Melyik a legnagyobb méretű partícionált tábla az adatbázisban a partíciók 
-- összméretét tekintve? Az alpartícióval rendelkező táblákat is vegyük figyelembe.
-- (tulajdonos, táblanév, méret)

WITH total_sizes AS (
    SELECT owner, segment_name, SUM(bytes) AS total_size
    FROM DBA_SEGMENTS
    WHERE segment_type='TABLE PARTITION'
    OR segment_type='TABLE SUBPARTITION'
    GROUP BY owner, segment_name
)
SELECT owner, segment_name, total_size
FROM total_sizes
WHERE total_size=(
    SELECT MAX(total_size)
    FROM total_sizes
);

-- Dinamikus SQL utasítások PL/SQL programban
-- ------------------------------------------
-- 8.
-- Írjunk meg egy PLSQL procedúrát, amelyik kiírja a paraméterül kapott táblára,
-- hogy annak hány üres blokkja van. A procedúrát úgy írjuk meg, hogy az partícionált táblára
-- is működjön. (Output formátum -> Empty Blocks: nnn)

-- CREATE OR REPLACE PROCEDURE empty_blocks(p_owner VARCHAR2, p_table VARCHAR2) IS
-- ...
-- SET SERVEROUTPUT ON
-- EXECUTE empty_blocks('nikovits','customers');
-- EXECUTE empty_blocks('nikovits','eladasok');

-- Ellenőrzés:
-- ----------
-- EXECUTE check_plsql('empty_blocks(''nikovits'', ''customers'')');
-- EXECUTE check_plsql('empty_blocks(''nikovits'', ''eladasok'')');

-- Vigyázat!
-- Ha olyan módon oldják meg a feladatot, ahogy a 3. feladatsor 5. feladatában szereplő num_of_rows()
-- megoldásában látták, az nagy táblák esetén kivárhatatlanul lassú lesz, mert ott minden egyes
-- blokkra megszámoltuk, hogy hány sor van benne.

-- Tipp: 
-- Nézzük meg, hogy összesen hány blokkot tartalmaz(nak) a tábla szegmense(i). (partícionált is lehet !)
-- Számoljuk meg az olyan blokkok számát, amelyek nem üresek. A fenti kettő különbsége adja a végeredményt.
-- Mivel a tábla nevét csak futásidőben fogjuk megtudni, ezért úgynevezett dinamikus SQL utasítást
-- kell használnunk. Ehhez lásd: pl_dinamikusSQL.txt
-- --------------------------------------------------------------------------------

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

-- CREATE OR REPLACE PROCEDURE print_type(p_owner VARCHAR2, p_table VARCHAR2) IS
-- ...
-- Test:
-- -----
-- set serveroutput on
-- execute print_type('nikovits', 'emp');
-- execute print_type('nikovits', 'eladasok5');
-- execute print_type('nikovits', 'cikk_iot');
-- execute print_type('nikovits', 'emp_clt');

-- Segítség:
-- Futtassák le az alábbi lekérdezést.

-- SELECT owner, table_name, cluster_name, partitioned, iot_type 
-- FROM dba_tables WHERE owner='NIKOVITS' 
-- AND table_name IN ('EMP', 'ELADASOK5', 'CIKK_IOT', 'EMP_CLT');

-- A megoldásukat ellenőrizni tudják az alábbi módon:
-- EXECUTE check_plsql('print_type(''nikovits'',''emp_clt'')');