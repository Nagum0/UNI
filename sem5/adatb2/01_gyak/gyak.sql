-- Kötelező feladat az 1. gyakorlathoz
-- ------------------------------------------
-- Hozzunk létre mindkét adatbázisban (ullman, aramis) egy GYAK01 nevű táblát, 
-- aminek egy oszlopa van, és az a NIKOVITS felhasználó olyan tábláinak nevét 
-- tartalmazza, amelyek nevében van 'B' betű.
-- A feladat célja, hogy lássam, be tudtak-e jelentkezni mindkét adatbázisba.
-- Ha valaki technikai problémába ütközik, emailben vagy konzultáció keretében
-- kérjen segítséget a gyakorlatvezetőtől.

-- Határidő: a következő gyakorlat kezdete. (Egy hét alatt kérjen segítséget, aki elakadna.)
-- ===========================================================================
-- Egy adatbázisban nem csak olyan táblák vannak, amiket a felhasználók hoztak létre,
-- hanem sok olyan tábla is, amik az adatbázisban tárolt különböző dolgok tulajdonságairól
-- tárolnak információkat. Ezeket a táblákat (vagy nézeteket) együtt katalógusnak vagy 
-- másképpen adatszótárnak hívjuk. Minden adatbázisban van katalógus, de az abban szereplő 
-- táblák (nézetek) száma és szerkezete különböző. 
-- Mi a következőkben az ORACLE adatbázist fogjuk megvizsgálni, de másik adatbázis-kezelő
-- esetén is hasonló módszert kellene követnünk.

-- A katalógus maga is egy adatbázisnak (táblák, nézetek halmazának) tekinthető, amit lekérdezve
-- többet tudhatunk meg az ORACLE adatbázisban tárolt dolgokról és azok tulajdonságairól.
-- A katalógus tábláinak (nézeteinek) elnevezése: DBA_..., ALL_..., USER_...
-- A katalógus másik szokásos elnevezése: adatszótár (Data Dictionary), 
-- vagy rendszerkatalógus (SYSTEM CATALOG).

-- Vigyázat !!!
-- Az alábbiakban ha egy objektumnak vagy egy felhasználónak a neve kisbetűvel 
-- szerepel a feladat szövegében, az nem jelenti, hogy ez az adatszótárban is kisbetűvel
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
-- az alábbi kérdésekre. A kérdések után szögletes zárójelben a végeredmény elvárt oszlopai szerepelnek.

SELECT * FROM DBA_OBJECTS;

-- 1.
-- --> Futtassuk a következő SQL utasítást: SELECT sysdate FROM dual;
-- Kinek a tulajdonában van a DUAL nevű tábla? [owner, object_name]
-- --> Futtassuk a következő utasításokat:
--     SELECT * FROM user_tables; (hozzunk létre egy tetszőleges táblát, majd futtassuk ismét)
--     SELECT * FROM all_tables; 
-- Kinek a tulajdonában van az ALL_TABLES nevű tábla/nézet ? [owner, object_name, object_type]

SELECT sysdate FROM DUAL;

SELECT owner, object_name
FROM DBA_OBJECTS
WHERE object_name='DUAL';

SELECT * FROM USER_TABLES;
SELECT * FROM ALL_TABLES;

SELECT owner, object_name, object_type
FROM DBA_OBJECTS
WHERE object_name='ALL_TABLES';

-- 2.
-- --> Futtassuk a következő utasításokat:
--     SELECT COUNT(*) FROM all_tables;
--     SELECT COUNT(*) FROM dba_tables;
-- Miért kapunk különböző értékeket? (--> a különbség a jogosultságokban van)
-- Kinek a tulajdonában van a DBA_TABLES nevű, illetve a DUAL nevű szinonima? [owner, object_name, object_type]
--   Az 1. és 2. feladat megmagyarázza, hogy miért tudjuk elérni a DUAL táblát, illetve a DBA_TABLES
--   nézetet anélkül, hogy minősítenénk őket a tulajdonos nevével így -> tulajdonos.objektum.

SELECT COUNT(*) FROM all_tables;
SELECT COUNT(*) FROM dba_tables;

SELECT owner, object_name, object_type
FROM DBA_OBJECTS
WHERE object_type='SYNONYM'
AND (
    object_name='DBA_TABLES'
    OR object_name='DUAL'
);

-- 3.
-- --> Az adatbázisban sokféle objektum van: tábla, nézet, index, szinonima ...
-- Milyen típusú objektumai vannak az ORAUSER nevű felhasználónak az adatbázisban? [object_type]

SELECT DISTINCT object_type
FROM DBA_OBJECTS
WHERE owner='ORAUSER';

-- 4.
-- Hány különböző fajta objektum (TABLE, INDEX stb.) van a jelenlegi adatbázisban? [darab]

SELECT COUNT(DISTINCT object_type) AS darab
FROM DBA_OBJECTS;

-- 5.
-- Melyek ezek az objektum típusok? (Pl. TABLE, VIEW ...) Soroljuk fel egy lekérdezéssel. [object_type]

SELECT DISTINCT object_type
FROM DBA_OBJECTS;

-- 6.
-- Kik azok a felhasználók, akiknek több mint 10 féle különböző objektumuk van? [owner]

SELECT owner
FROM DBA_OBJECTS
GROUP BY owner
HAVING COUNT(DISTINCT object_type) > 10;

-- 7.
-- Kik azok a felhasználók, akiknek van triggere (TRIGGER vagy trigger ?!) és nézete (VIEW) is? [owner]
-- --> vigyázzunk az objektumok nevénél a kisbetű/nagybetű-re.

SELECT owner
FROM DBA_OBJECTS
WHERE object_type='TRIGGER'
INTERSECT
SELECT owner
FROM DBA_OBJECTS
WHERE object_type='VIEW';

-- 8.
-- Kik azok a felhasználók, akiknek van nézete, de nincs triggere? [owner]

SELECT owner
FROM DBA_OBJECTS
WHERE object_type='VIEW'
MINUS
SELECT owner
FROM DBA_OBJECTS
WHERE object_type='TRIGGER';

-- 9.
-- Kik azok a felhasználók, akiknek több mint n táblájuk, de maximum m indexük van? [owner]
-- (n és m értékét adjuk meg úgy, hogy kb. 1-15 között legyen a sorok száma, pl. n=20, m=15)

SELECT owner
FROM DBA_OBJECTS
WHERE object_type='TABLE'
GROUP BY owner
HAVING COUNT(object_type) > 7
INTERSECT
SELECT owner
FROM DBA_OBJECTS
WHERE object_type='INDEX'
GROUP BY owner
HAVING COUNT(object_type) <= 5;

-- 10.
-- Melyek azok az objektum típusok, amelyek tényleges fizikai tárolást igényelnek, vagyis
-- tartoznak hozzájuk adatfájlokban lefoglalt adatblokkok? [object_type]
-- --> Az olyan objektumoknak, amik nem igényelnek tényleges tárolást, pl. nézet, szinonima,
--     csak a definíciója tárolódik az adatszótárban. A megoldáshoz a DATA_OBJECT_ID oszlopot
--     vizsgáljuk meg.

SELECT DISTINCT object_type
FROM DBA_OBJECTS
WHERE data_object_id IS NOT NULL;

-- 11.
-- Melyek azok az objektum típusok, amelyek nem igényelnek tényleges tárolást, vagyis nem
-- tartoznak hozzájuk adatblokkok? [object_type]
-- --> Az utóbbi két lekérdezés metszete nem üres. Vajon miért? -> lásd majd partícionálás
-- --> Vannak olyan TABLE típusú objektumok, amelyek látszólag nem igényelnek fizikai tárolást. 
-- --> Pedig valójában igen. Majd később megnézzük a részleteket.

SELECT DISTINCT object_type
FROM DBA_OBJECTS
WHERE data_object_id IS NULL;

-- 12.
-- Keressük meg az utóbbi két lekérdezés metszetét. [object_type]
-- --> Ezek olyan objektum típusok, amelyekből előfordul adatblokkokal rendelkező
--     és adatblokkokal nem rendelkező is. -> lásd később

SELECT DISTINCT object_type
FROM DBA_OBJECTS
WHERE data_object_id IS NOT NULL
INTERSECT
SELECT DISTINCT object_type
FROM DBA_OBJECTS
WHERE data_object_id IS NULL;

-- Táblák (és nézetek) oszlopai (DBA_TAB_COLUMNS)
-- ----------------------------------------------
-- Az alábbi kérdésekkel egy tábla (nézet) oszlopait vizsgálhatjuk meg részletesen, vagyis
-- az oszlop nevét, sorszámát (hányadik oszlop), típusát, azt hogy elfogadja-e a NULL
-- értéket, van-e alapértelmezett értéke, stb.
-- --------------------------------------------------------------------------------

SELECT * FROM DBA_TAB_COLUMNS
WHERE owner='UAUYQF';

-- 13.
-- Hány oszlopa van a nikovits.emp táblának? [darab]

SELECT COUNT(DISTINCT column_id) AS darab
FROM DBA_TAB_COLUMNS
WHERE owner='NIKOVITS'
AND table_name='EMP';

-- 14.
-- Milyen típusú a nikovits.emp tábla 6. oszlopa? [data_type]

SELECT data_type
FROM DBA_TAB_COLUMNS
WHERE owner='NIKOVITS'
AND table_name='EMP'
AND column_id=6;

-- 15.
-- Adjuk meg azoknak a tábláknak a tulajdonosát és nevét, amelyeknek van 'Z' betűvel 
-- kezdődő oszlopa. [owner, table_name]

SELECT DISTINCT owner, table_name
FROM DBA_TAB_COLUMNS
WHERE column_name LIKE 'Z%';

-- 16.
-- Adjuk meg azoknak a tábláknak a tulajdonosát és nevét, amelyeknek legalább 8 
-- darab dátum tipusú oszlopa van. [owner, table_name]

SELECT owner, table_name
FROM DBA_TAB_COLUMNS
WHERE data_type='DATE'
GROUP BY owner, table_name
HAVING COUNT(*) >= 8;

-- 17.
-- Adjuk meg azoknak a tábláknak a tulajdonosát és nevét, amelyeknek 1. es 4. oszlopa is
-- VARCHAR2 tipusú, az oszlop hossza mindegy. [owner, table_name]

SELECT owner, table_name
FROM DBA_TAB_COLUMNS
WHERE column_id=1
AND data_type='VARCHAR2'
INTERSECT
SELECT owner, table_name
FROM DBA_TAB_COLUMNS
WHERE column_id=4
AND data_type='VARCHAR2';

-- -----------------------------------------------------------------------
-- 18.
-- Írjunk meg egy PLSQL procedúrát, amelyik a paraméterül kapott karakterlánc alapján 
-- kiírja azoknak a tábláknak a nevét és tulajdonosát, amelyek az adott karakterlánccal 
-- kezdődnek. (Ha a paraméter kisbetűs, akkor is működjön a procedúra!)
-- A fenti procedúra segítségével írjuk ki a Z betűvel kezdődő táblák nevét és tulajdonosát.
-- CREATE OR REPLACE PROCEDURE table_print(p_kar VARCHAR2) IS 
-- ...
-- Futtatás:
-- SET SERVEROUTPUT ON
-- EXECUTE table_print('Z');
-- -----------------------------------------------------------------------
-- 19.
-- Írjunk meg egy PLSQL függvényt, amelyik paraméterül kap egy felhasználónevet,
-- és visszaadja az adott felhasználó olyan táblái vagy nézetei közül ábécé szerinti elsőt,
-- amelyiknek van DATE típusú oszlopa, de nincs NUMBER típusú oszlopa.
-- Írjunk bele minimális hibakezelést is, pl. 'non-existing user', 'no such table or view'.
-- CREATE OR REPLACE FUNCTION first_tab_view(p_owner VARCHAR2) RETURN VARCHAR2 IS 
-- ...
-- Futtatás:
-- SELECT first_tab_view('nikovits') FROM dual;
-- SELECT first_tab_view('bubu') FROM dual;
-- -----------------------------------------------------------------------

-- Példa
-- =======================================================================
-- Futtassuk le az alábbi SQL és PL/SQL utasításokat és nézzük meg, hogy
-- mi kerül a táblába.
-- =======================================================================
-- CREATE TABLE test1(col1 INTEGER PRIMARY KEY, col2 VARCHAR2(20));

-- CREATE SEQUENCE seq1 
-- MINVALUE 1 MAXVALUE 100 INCREMENT BY 5 START WITH 50 CYCLE;

-- CREATE OR REPLACE TRIGGER test1_bir -- before insert row
-- BEFORE INSERT ON test1 
-- FOR EACH ROW 
-- WHEN (new.col1 is null) 
-- BEGIN
--   :new.col1 := seq1.nextval;
-- END;
-- /
-- BEGIN
--  FOR i IN 1..14 LOOP 
--   INSERT INTO test1 VALUES(null, 'trigger'||to_char(i,'FM09'));
--  END LOOP;
--  INSERT INTO test1 VALUES(seq1.currval + 1, 'sequence + 1'); 
--  COMMIT;
-- END;
-- /
-- SELECT * FROM test1 ORDER BY col2;

-- DROP TABLE test1;    -- a trigger is törlődni fog
-- DROP sequence seq1;  -- a szekvencia nincs a táblához kötve