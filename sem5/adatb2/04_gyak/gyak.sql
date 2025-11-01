-- Feladat plusz pontokért (részleteket lásd --> zh1_info.txt a Teams-ben)
-- -----------------------------------------------------------------------
-- Írják meg az alábbi, 6. feladatban szereplő LIST_INDEXES nevű procedúrát.
-- Azt, hogy az output helyes-e ellenőrizni tudják a feladat után megadott 'CHECK_PLSQL'
-- procedúra futtatásával.

-- Határidő: a következő gyakorlat kezdete.
-- ===========================================================================

-- B+ fa index
-- -----------
-- Az alábbi feladatban a tankönyben leírt algoritmussal építsünk fel egy B+ fát!

-- Tegyük fel, hogy egy B+ fa blokkjaiba 3 kulcs fér el plusz 4 mutató. A kulcsok 
-- különbözőek. Szúrjuk be a B+ fába az alábbi kulcsértékeket a megadott sorrendben:
-- 39,15,50,70,79,83,72,43,75,45,60,80
-- Adjuk meg a B+ fa minden olyan állapotát, amikor egy csomópont kettéosztására volt szükség.
-- Például, az első kettéosztás utáni állapot:
--                           50
--                     15|39    50|70

-- Egy kis segítség:
-- ----------------

-- Levél csúcs kettéosztásakor minden kulcsot megőrzünk a régi és az új (szomszédos) csúcsban.
-- 1 új kulcs-mutató párt küldünk felfelé a szülő csúcsba, amit ott kell elhelyezni.

-- Belső csúcs kettéosztásakor (N,M csúcsra) a mutatók első fele az N-be kerül, a második az M-be.
-- A kulcsok első fele az N-be kerül a második fele az M-be, de középen kimarad egy kulcs,
-- ami az M-en keresztül (első gyermekén keresztül) elérhető legkisebb kulcsot tartalmazza. 
-- Ez nem kerül sem N-be, sem M-be, hanem ez megy fölfelé N és M közös szülőjébe az M-re mutató
-- mutatóval együtt.

-- --------------------------------------------------------------------------------------------------
-- Bitmap index (Feladat1)

-- DKOD DNEV   FIZETES  FOGLALKOZAS  BELEPES  OAZON
-- ---------------------------------------------------
-- 1    SMITH     800   CLERK        1980     20   
-- 2    ALLEN    1600   SALESMAN     1981     30	   
-- 3    WARD     1250   SALESMAN     1981     30	   
-- 4    JONES    2975   MANAGER      1981     20	   
-- 5    MARTIN   1250   SALESMAN     1981     30	   
-- 6    BLAKE    2850   MANAGER      1981     30	   
-- 7    CLARK    2450   MANAGER      1981     10	   
-- 8    SCOTT    3000   ANALYST      1982     20	   
-- 9    KING     5000   PRESIDENT    1981     10	   
-- 10   TURNER   1500   SALESMAN     1981     30	   
-- 11   ADAMS    1100   CLERK        1983     20	   
-- 12   JAMES     950   CLERK        1981     30	   
-- 13   FORD     3000   ANALYST      1981     20	   
-- 14   MILLER   1300   CLERK        1982     10	 


-- a) Készítsen bitmap indexet a fenti DOLGOZO tábla OAZON oszlopára és adja meg a bitvektorokat.

-- b) Tegyük fel, hogy a FOGLALKOZAS, a BELEPES és az OAZON oszlopokra létezik bitmap index (3 index).
--    Készítsük el az alábbi lekérdezésekhez szükséges bitvektorokat, majd végezzük el rajtuk a szükséges 
--    műveleteket, és adjuk meg azt az előállt bitvektort, ami alapján a végeredmény sorok megkaphatók.

-- Lekérdezés1 
-- - Adjuk meg azoknak a dolgozóknak a nevét, akik 1981-ben léptek be és a foglalkozásuk hivatalnok (CLERK),
--   vagy a 20-as osztályon dolgoznak és a foglalkozásuk MANAGER.
-- Lekérdezés2
-- - Adjuk meg azoknak a dolgozóknak a nevét, akik nem 1981-ben léptek be és a 10-es vagy a 30-as 
--   osztályon dolgoznak.

-- --------------------------------------------------------------------------------------------------
-- Bitmap index (Feladat2)

-- Tömörítsük a következő bitvektort a szakaszhossz kódolással. (lásd UW_szakaszhossz_kodolas.docx)
-- 010000000000000000000000000000010000000000000000000000000000000001000000000000001

-- Fejtsük vissza a következő, szakaszhossz kódolással tömörített bitvektort:
-- 1111010101001011

-- --------------------------------------------------------------------------------------------------
-- Bitmap index (Feladat3)

-- Tegyük fel, hogy a DOLGOZO tábla FIZETÉS és OAZON (osztály azonosító) oszlopára a következő 
-- bitmap indexek vannak létrehozva.

-- Fizetés Bitvektor
-- ------- ----------
-- 1000    0010010000
-- 2000    0100100001
-- 3000    1000001100
-- 4000    0001000010

-- Oazon  Bitvector
-- ------ ----------
-- 10     1000100001
-- 20     0110001000
-- 30     0001010110

-- a) Hány dolgozó dolgozik a 10-es osztályon?
-- b) Hány dolgozónak magasabb a fizetése 2500-nál a 30-as osztályon?
-- c) Mennyi az átlagfizetés a 10-es osztályon?

-- --------------------------------------------------------------------------------------------------
-- Bitmap index (Feladat4)

-- Tegyük fel, hogy adottak az R relációra vonatkozóan az alábbi paraméterek:
-- T(R) = 1000, V(R,A) = 20.   [T(R): R tábla sorainak száma, V(R,A): R.A-ban előforduló különböző értékek száma]
-- a) Hány bitvektor van az 'A' oszlopra létrehozott bitmap indexben? 
-- b) Hány darab '1'-es van az egész bitmap indexben?
-- c) Átlagosan hány 0-ás bit van az egyes bitvektorokban? 

-- --------------------------------------------------------------------------------------------------
-- Oracle indexek  
-- --------------
-- (DBA_INDEXES, DBA_IND_COLUMNS, DBA_IND_EXPRESSIONS)

SELECT * FROM DBA_INDEXES;
SELECT * FROM DBA_IND_COLUMNS;
SELECT * FROM DBA_IND_EXPRESSIONS;

-- Hozzunk létre egy vagy több táblához több különböző indexet, legyen köztük több oszlopos,
-- csökkenő sorrendű, bitmap, függvény alapú stb. (Ehhez használhatók az ab2_oracle.docx
-- állományban szereplő példák, vagy a cr_index.txt-ben szereplők.)
-- Az alábbi lekérdezésekkel megállapítjuk az iménti indexeknek mindenféle tulajdonságait a 
-- katalógusokból.

SELECT *
FROM DBA_INDEXES
WHERE owner='UAUYQF';

CREATE TABLE emp AS SELECT * FROM nikovits.emp;

CREATE UNIQUE INDEX  emp1 ON emp (ename);
CREATE INDEX         emp2 ON emp (job, sal DESC);
CREATE INDEX         emp3 ON emp (job, sal) REVERSE;
CREATE INDEX         emp4 ON emp (deptno, job, sal) COMPRESS 2;
CREATE BITMAP INDEX  emp5 ON emp (mgr);
CREATE INDEX         emp6 ON emp (SUBSTR(ename, 2, 2), job);
CREATE INDEX         emp7 ON emp (SUBSTR(ename, 2, 2), job, sal);

-- 1.
-- Adjuk meg azoknak a tábláknak a nevét, amelyeknek van csökkenő sorrendben indexelt oszlopa.

SELECT table_name
FROM DBA_IND_COLUMNS
WHERE descend='DESC';

-- 2.
-- Adjuk meg azoknak az indexeknek a nevét, amelyek legalább 9 oszloposak.
-- (Vagyis a táblának legalább 9 oszlopát vagy egyéb kifejezését indexelik.)

SELECT index_owner, index_name
FROM DBA_IND_COLUMNS
GROUP BY index_owner, index_name
HAVING COUNT(*) >= 9;

-- 3.
-- Adjuk meg a NIKOVITS.CUSTOMERS táblára létrehozott bitmap indexek nevét.

SELECT index_name
FROM DBA_INDEXES
WHERE table_owner='NIKOVITS'
AND table_name='CUSTOMERS'
AND index_type='BITMAP';

-- 4.
-- Adjuk meg azon kétoszlopos indexek nevét és tulajdonosát, amelyeknek legalább 
-- az egyik kifejezése függvény alapú.

SELECT di.index_name, di.owner
FROM DBA_INDEXES di
JOIN DBA_IND_COLUMNS dc
ON di.index_name=dc.index_name
AND di.owner=dc.index_owner
WHERE di.index_type LIKE '%FUNCTION%'
GROUP BY di.index_name, di.owner
HAVING COUNT(*)=2;

-- 5.
-- Adjuk meg az egyikükre, pl. a NIKOVITS felhasználó tulajdonában lévőre, hogy milyen kifejezések szerint 
-- vannak indexelve a soraik. (Vagyis mi a függvény/kifejezés, ami alapján a bejegyzések készülnek.)

WITH twos AS (
    SELECT di.index_name, di.owner
    FROM DBA_INDEXES di
    JOIN DBA_IND_COLUMNS dc
    ON di.index_name=dc.index_name
    AND di.owner=dc.index_owner
    WHERE di.index_type LIKE '%FUNCTION%'
    GROUP BY di.index_name, di.owner
    HAVING COUNT(*)=2
)
SELECT column_expression
FROM DBA_IND_EXPRESSIONS de
JOIN twos t
ON de.index_owner=t.owner
AND de.index_name=t.index_name
WHERE de.index_owner='NIKOVITS';

-- 6.
-- Írjunk meg egy plsql procedúrát, amelyik a paraméterül kapott táblára vonatkozóan 
-- kiírja a tábla indexeit és azok méretét bájtban. Az indexeket abc sorrendben, külön sorokban
-- kell kiírni, a méretet szóközzel elválasztva az index nevétől így:
-- INDEX1: 1234  
-- INDEX2: 5678
-- (az index neve után van egy kettőspont)

-- CREATE OR REPLACE PROCEDURE list_indexes(p_owner VARCHAR2, p_table VARCHAR2) IS
-- ...
-- Tesztelés:
-- SET SERVEROUTPUT ON
-- EXECUTE list_indexes('nikovits', 'customers');
-- EXECUTE list_indexes('nikovits', 'emp');

-- Ellenőrzés:
-- ----------
-- EXECUTE check_plsql('list_indexes(''nikovits'', ''customers'')');
-- EXECUTE check_plsql('list_indexes(''nikovits'', ''emp'')');
-- -----------------------------------------------------------------------

-- 7.
-- Adjuk meg azon táblák nevét és tulajdonosát, amelyeknek van dátum (DATE) típusú oszlopa, és
-- a táblára létre van hozva BITMAP index.

SELECT DISTINCT tc.owner, tc.table_name
FROM DBA_TAB_COLUMNS tc
JOIN DBA_INDEXES di
ON tc.owner=di.table_owner
AND tc.table_name=di.table_name
WHERE tc.data_type='DATE'
AND di.index_type='BITMAP';

-- 8.
-- Adjuk meg a NIKOVITS felhasználó olyan tábláinak a nevét, amelyeknek legalább 2 extense van
-- és a táblára nincs létrehozva index.

SELECT segment_name
FROM DBA_EXTENTS
WHERE owner='NIKOVITS'
AND segment_type='TABLE'
GROUP BY segment_name
HAVING COUNT(*) >= 2
AND segment_name NOT IN (
    SELECT table_name
    FROM DBA_INDEXES
);

SELECT dt.table_name
FROM DBA_TABLES dt
WHERE dt.owner = 'NIKOVITS'
  AND EXISTS (
      SELECT 1
      FROM DBA_EXTENTS de
      WHERE de.owner = dt.owner
        AND de.segment_name = dt.table_name
      GROUP BY de.segment_name
      HAVING COUNT(*) >= 2
  )
  AND NOT EXISTS (
      SELECT 1
      FROM DBA_INDEXES di
      WHERE di.table_owner = dt.owner
        AND di.table_name = dt.table_name
  );