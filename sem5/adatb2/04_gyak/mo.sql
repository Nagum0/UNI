-- Oracle indexek  
-- --------------
-- (DBA_INDEXES, DBA_IND_COLUMNS, DBA_IND_EXPRESSIONS)

-- Hozzunk létre egy vagy több táblához több különbözõ indexet, legyen köztük több oszlopos,
-- csökkenõ sorrendû, bitmap, függvény alapú stb. (Ehhez használhatók az ab2_oracle.docx
-- állományban szereplõ példák, vagy a cr_index.txt-ben szereplõk.)
-- Az alábbi lekérdezésekkel megállapítjuk az iménti indexeknek mindenféle tulajdonságait a 
-- katalógusokból.

-- 1.
-- Adjuk meg azoknak a tábláknak a nevét, amelyeknek van csökkenõ sorrendben indexelt oszlopa. (tulajdonos: NIKOVITS)
-- --------------------------------------------------------------------------------
 SELECT table_owner, table_name, index_name, column_name FROM dba_ind_columns 
 WHERE descend='DESC' AND index_owner='NIKOVITS';

-- Miért ilyen furcsa az oszlopnév? Mi az oszlop tényleges neve?
-- -> lásd DBA_IND_EXPRESSIONS
--  SELECT i.index_owner, i.index_name, e.column_expression FROM dba_ind_columns i, dba_ind_expressions e
--  WHERE i.index_owner=e.index_owner AND i.index_name=e.index_name AND i.column_position=e.column_position
--  AND i.descend='DESC' AND i.index_owner='NIKOVITS';

-- 2.
-- Adjuk meg azoknak az indexeknek a nevét, amelyek legalább 9 oszloposak.
-- (Vagyis a táblának legalább 9 oszlopát vagy egyéb kifejezését indexelik.)
-- --------------------------------------------------------------------------------
 SELECT index_owner, index_name FROM dba_ind_columns 
 GROUP BY index_owner, index_name HAVING count(*) >=9;

-- 3.
-- Adjuk meg a NIKOVITS.CUSTOMERS táblára létrehozott bitmap indexek nevét.
-- Elõtte:
-- create bitmap index CUSTOMERS_MARITAL_BIX on customers(cust_marital_status);
-- create bitmap index CUSTOMERS_YOB_BIX on customers(cust_year_of_birth);
-- --------------------------------------------------------------------------------
 SELECT index_name FROM dba_indexes 
 WHERE table_owner='NIKOVITS' AND table_name='CUSTOMERS' AND index_type='BITMAP';

-- 4.
-- Adjuk meg azon kétoszlopos indexek nevét és tulajdonosát, amelyeknek legalább 
-- az egyik kifejezése függvény alapú. (tulajdonos, név)
-- --------------------------------------------------------------------------------
 SELECT index_owner, index_name FROM dba_ind_columns 
 GROUP BY index_owner, index_name HAVING count(*) =2
  INTERSECT
 SELECT index_owner, index_name FROM dba_ind_expressions;

-- 5.
-- Adjuk meg az egyikükre, pl. a NIKOVITS tulajdonában lévõre, hogy milyen kifejezések szerint 
-- vannak indexelve a soraik. (Vagyis mi a függvény/kifejezés, ami alapján a bejegyzések készülnek.)
-- --------------------------------------------------------------------------------
--  SELECT * FROM dba_ind_expressions WHERE index_owner='NIKOVITS';

-- 6.
-- Írjunk meg egy plsql procedúrát, amelyik a paraméterül kapott táblára vonatkozóan 
-- kiírja a tábla indexeit és azok méretét. 
-- CREATE OR REPLACE PROCEDURE list_indexes(p_owner VARCHAR2, p_table VARCHAR2) IS
-- ...
-- Tesztelés:
-- SET SERVEROUTPUT ON
-- EXECUTE list_indexes('nikovits', 'customers');
-- EXECUTE list_indexes('nikovits', 'emp');
-- -----------------------------------------------------------------------

-- 7.
-- Adjuk meg azon táblák nevét és tulajdonosát, amelyeknek van dátum (DATE) típusú oszlopa, és
-- a táblára létre van hozva BITMAP index.
 SELECT owner, table_name FROM dba_tab_columns WHERE data_type='DATE' 
  INTERSECT
 SELECT owner, table_name FROM dba_indexes WHERE index_type='BITMAP'; 

-- 8.
-- Adjuk meg a NIKOVITS felhasználó olyan tábláinak a nevét, amelyeknek legalább 2 extense van
-- és a táblára nincs létrehozva index.
 SELECT segment_name FROM dba_segments WHERE owner='NIKOVITS' AND extents > 1 AND segment_type='TABLE'
  MINUS
 SELECT table_name FROM dba_indexes WHERE table_owner='NIKOVITS'; 