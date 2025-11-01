-- A múlt heti kötelezõ feladat ellenõrzése:
-- set serveroutput on
-- execute list_students('H12','gyak01');

-- Kérem, hogy mindenki csinálja meg a feladatot, vagyis hozza létre a táblát
-- még akkor is, ha nem volt ott az 1. gyakorlaton.
-- ==========================================================================

-- A rendszerkatalógus maga is egy adatbázisnak tekinthetõ, amit lekérdezve egyre többet
-- tudhatunk meg az ORACLE adatbázisban tárolt dolgokról és azok tulajdonságairól.
-- A rendszerkatalógus tábláinak (nézeteinek) elnevezése: DBA_..., ALL_..., USER_...
-- A rendszerkatalógus másik szokásos elnevezése: adatszótár (Data Dictionary)

-- Vigyázat !!!
-- Az alábbiakban ha egy objektumnak vagy egy felhasználónak a neve kisbetûvel 
-- szerepel a feladat szövegében, az nem jelenti, hogy ez az adatszótárban is kisbetûvel
-- van tárolva. Pl. orauser - ORAUSER felhasználó, emp - EMP tábla.

-- CREATE table proba(o integer);  --> A tábla neve az adatszótárakban 'PROBA' lesz.
-- CREATE table "proba"(o integer);  --> A tábla neve az adatszótárakban 'proba' lesz.

-- Adatbázis objektumok (DBA_OBJECTS)
-- ----------------------------------
-- Az alábbi lekérdezések segítenek feltérképezni, hogy milyen objektumok
-- vannak egy Oracle adatbázisban, ki a tulajdonosuk, mikor hozták létre azokat, stb.
-- A kérdések után zárójelben az elvárt végeredmény oszlopai szerepelnek.
-- ---------------------------------------------------------------------------------
-- Feladatok
-- ---------
-- Adjunk meg SQL lekérdezést, illetve írjunk PL/SQL programot (ahol ez van megadva)
-- az alábbi kérdésekre. A kérdések után szögletes zárójelben a végeredmény oszlopai szerepelnek.

-- 1.
-- Kinek a tulajdonában van a DUAL nevû tábla? [owner, object_name]
-- -- kérdezzük le mindjárt a DBA_TABLES-t is, és az objektumok típusát is
 SELECT owner, object_name, object_type FROM dba_objects WHERE object_name IN ('DBA_TABLES', 'DUAL');

-- 2.
-- Kinek a tulajdonában van a DBA_TABLES nevû, illetve a DUAL nevû szinonima? [owner, object_name, object_type]

-- 3.
-- Milyen típusú objektumai vannak az ORAUSER nevû felhasználónak az adatbázisban? [object_type]
 SELECT distinct object_type FROM dba_objects
 WHERE owner='ORAUSER';

-- 4.
-- Hány különbözõ típusú objektum van nyilvántartva az adatbázisban? [darab]
 SELECT count(distinct object_type) FROM dba_objects;

-- 5.
-- Melyek ezek a típusok? [object_type]
 SELECT distinct object_type FROM dba_objects;

-- 6.
-- Kik azok a felhasználók, akiknek több mint 10 féle objektumuk van? [owner]
--  --> COUNT(DISTINCT ...) 

-- 7.
-- Kik azok a felhasználók, akiknek van triggere és nézete is? [owner]
--  --> metszet

-- 8.
-- Kik azok a felhasználók, akiknek van nézete, de nincs triggere? [owner]
 SELECT distinct owner FROM dba_objects WHERE object_type='VIEW'
  MINUS
 SELECT distinct owner FROM dba_objects WHERE object_type='TRIGGER';

-- 9.
-- Kik azok a felhasználók, akiknek több mint n táblájuk, de maximum m indexük van? [owner]
-- (n és m értékét adjuk meg úgy, hogy kb. 1-15 között legyen a sorok száma, pl. n=20, m=15)
 SELECT distinct owner FROM dba_objects WHERE object_type='TABLE'
 GROUP BY owner
 HAVING count(*) > 20
  MINUS
 SELECT distinct owner FROM dba_objects WHERE object_type='INDEX'
 GROUP BY owner
 HAVING count(*) > 15;

-- 10.
-- Melyek azok az objektum típusok, amelyek tényleges tárolást igényelnek, vagyis
-- tartoznak hozzájuk adatblokkok? [object_type]
--  (Az olyan objektumoknak, amik nem igényelnek tényleges tárolást, pl. nézet,
--   csak a definíciója tárolódik az adatszótárban. A megoldáshoz a data_object_id oszlopot
--   vizsgáljuk meg.)
 SELECT DISTINCT object_type FROM dba_objects WHERE data_object_id IS NOT NULL;

-- 11.
-- Melyek azok az objektum típusok, amelyek nem igényelnek tényleges tárolást, vagyis nem
-- tartoznak hozzájuk adatblokkok? [object_type]
-- Az utóbbi két lekérdezés metszete nem üres. Vajon miért? -> lásd majd partícionálás
 SELECT DISTINCT object_type FROM dba_objects WHERE data_object_id IS NULL;

-- 12.
-- Keressük meg az utóbbi két lekérdezés metszetét. [object_type]
-- (Ezek olyan objektum típusok, amelyekbõl elõfordul adatblokkokal rendelkezõ
-- és adatblokkokal nem rendelkezõ is.)
 SELECT distinct object_type FROM dba_objects WHERE NVL(data_object_id,0) = 0
  INTERSECT
 SELECT distinct object_type FROM dba_objects WHERE NVL(data_object_id,0) != 0;
 

-- Táblák oszlopai (DBA_TAB_COLUMNS)
-- ---------------------------------
-- Az alábbi kérdésekkel egy tábla oszlopait vizsgálhatjuk meg részletesen, vagyis
-- az oszlop nevét, sorszámát (hányadik oszlop), típusát, azt hogy elfogadja-e a NULL
-- értéket, van-e alapértelmezett értéke, stb.
-- --------------------------------------------------------------------------------

-- 13.
-- Hány oszlopa van a nikovits.emp táblának? [darab]
--  --> Vigyázat! több felhasználónak is lehet azonos nevû táblája.

-- 14.
-- Milyen típusú a nikovits.emp tábla 6. oszlopa? [data_type]
--  --> column_id = 6

-- 15.
-- Adjuk meg azoknak a tábláknak a tulajdonosát és nevét, amelyeknek van 'Z' betûvel 
-- kezdõdõ oszlopa. [owner, table_name]

-- 16.
-- Adjuk meg azoknak a tábláknak a tulajdonosát és nevét, amelyeknek legalább 8 
-- darab dátum tipusú oszlopa van. [owner, table_name]
 SELECT owner, table_name FROM dba_tab_columns
 WHERE data_type='DATE'
 GROUP BY owner, table_name
 HAVING count(*) >= 8;

-- 17.
-- Adjuk meg azoknak a tábláknak a tulajdonosát és nevét, amelyeknek 1. es 4. oszlopa is
-- VARCHAR2 tipusú, az oszlop hossza mindegy. [owner, table_name]
 SELECT owner, table_name FROM dba_tab_columns
 WHERE column_id=1 AND data_type='VARCHAR2'
  INTERSECT
 SELECT owner, table_name FROM dba_tab_columns
 WHERE column_id=4 AND data_type='VARCHAR2';

-- -----------------------------------------------------------------------
-- 18.
-- Írjunk meg egy plsql procedúrát, amelyik a paraméterül kapott karakterlánc alapján 
-- kiírja azoknak a tábláknak a nevét és tulajdonosát, amelyek az adott karakterlánccal 
-- kezdõdnek. (Ha a paraméter kisbetûs, akkor is mûködjön a procedúra!)
--      PROCEDURE table_print(p_kar VARCHAR2) 
-- A fenti procedúra segítségével írjuk ki a Z betûvel kezdõdõ táblák nevét és tulajdonosát.

-- CREATE OR REPLACE PROCEDURE table_print(p_kar VARCHAR2) is
--   CURSOR curs1 IS 
--   select owner,table_name from dba_tables
--   where upper(table_name) like upper(p_kar)||'%';
--   rec curs1%ROWTYPE;
-- BEGIN
--   OPEN curs1;
--   LOOP
--     FETCH curs1 INTO rec;
--     EXIT WHEN curs1%NOTFOUND;
--     dbms_output.put_line(rec.owner||' - '||rec.table_name);
--   END LOOP;
--   CLOSE curs1;
-- END;
-- /
-- Futtatás:
-- SET SERVEROUTPUT ON
-- EXECUTE table_print('Z');


-- 19.
-- Írjunk meg egy PLSQL függvényt, amelyik paraméterül kap egy felhasználónevet,
-- és visszaadja az adott felhasználó olyan táblái vagy nézetei közül ábécé szerinti elsõt,
-- amelyiknek van DATE típusú oszlopa, de nincs NUMBER típusú oszlopa.
-- Írjunk bele minimális hibakezelést is, pl. 'non-existing user', 'no such table or view'.

-- CREATE OR REPLACE FUNCTION first_tab_view(p_owner VARCHAR2) RETURN VARCHAR2 IS 
--   ret_val VARCHAR2(1000); v_num NUMBER(10);
-- BEGIN
--   SELECT count(*) INTO v_num FROM dba_users WHERE username=upper(p_owner);
--   IF v_num=0 THEN return 'Non-existing user'; END IF; 
--   SELECT table_name INTO ret_val FROM
--   (SELECT table_name FROM dba_tab_columns WHERE OWNER=upper(p_owner) AND data_type='DATE'
--    MINUS
--   SELECT table_name FROM dba_tab_columns WHERE OWNER=upper(p_owner) AND data_type='NUMBER'
--   ORDER BY 1 FETCH FIRST 1 ROWS ONLY);
--   RETURN ret_val;
-- EXCEPTION WHEN NO_DATA_FOUND THEN return 'User has no such tables or views';  
-- END;
-- /
-- Futtatás:
-- SELECT first_tab_view('nikovits') FROM dual;
-- SELECT first_tab_view('bubu') FROM dual;