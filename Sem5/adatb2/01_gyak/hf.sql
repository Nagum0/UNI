SELECT * FROM dba_objects;

-- 1. Kinek a tulajdonában van a DBA_TABLES nevű nézet, illetve a DUAL nevű tábla? [owner, object_name, object_type]
SELECT owner, object_name, object_type 
FROM dba_objects
WHERE (object_type = 'VIEW' AND object_name = 'DBA_TABLES')
OR (object_type = 'TABLE' AND object_name = 'DUAL');

-- 2. Kinek a tulajdonában van a DBA_TABLES nevű, illetve a DUAL nevű szinonima? [owner, object_name, object_type]
--   Az iménti két lekérdezés megmagyarázza, hogy miért tudjuk elérni a DUAL táblát, illetve a DBA_TABLES
--   nézetet anélkül, hogy minősítenénk őket a tulajdonos nevével így -> tulajdonos.objektum.
SELECT owner, object_name, object_type 
FROM dba_objects
WHERE (object_name = 'DBA_TABLES' OR object_name = 'VIEW')
AND object_type = 'SYNONYM';

-- 3. Milyen típusú objektumai vannak az orauser nevű felhasználónak az adatbázisban? [object_type]
SELECT object_type 
FROM dba_objects
WHERE owner = 'orauser';

-- 4. Hány különböző típusú objektum van nyilvántartva az adatbázisban? [darab]
SELECT COUNT(DISTINCT object_type) AS darab
FROM dba_objects;

-- 5. Melyek ezek a típusok? [object_type]
SELECT object_type
FROM dba_objects;

-- 6. Kik azok a felhasználók, akiknek több mint 10 féle objektumuk van? [owner]
SELECT owner
FROM dba_objects
GROUP BY owner
HAVING COUNT(DISTINCT object_type) > 10;

-- 7. Kik azok a felhasználók, akiknek van triggere és nézete is? [owner]
SELECT owner
FROM dba_objects
WHERE object_type = 'VIEW'
INTERSECT
SELECT owner
FROM dba_objects
WHERE object_type = 'TRIGGER';

-- 8. Kik azok a felhasználók, akiknek van nézete, de nincs triggere? [owner]
SELECT owner
FROM dba_objects
WHERE object_type = 'VIEW'
MINUS
SELECT owner
FROM dba_objects
WHERE object_type = 'TRIGGER';

-- 9. Kik azok a felhasználók, akiknek több mint n táblájuk, de maximum m indexük van? [owner]
-- (n és m értékét adjuk meg úgy, hogy kb. 1-15 között legyen a sorok száma, pl. n=20, m=15)
SELECT owner
FROM dba_objects
WHERE object_type IN ('TABLE', 'INDEX')
GROUP BY owner
HAVING COUNT(CASE WHEN object_type = 'TABLE' THEN 1 END) > 20
AND COUNT(CASE WHEN object_type = 'INDEX' THEN 1 END) <= 15;

-- 10. Melyek azok az objektum típusok, amelyek tényleges tárolást igényelnek, vagyis
-- tartoznak hozzájuk adatblokkok? [object_type]
--  (Az olyan objektumoknak, amik nem igényelnek tényleges tárolást, pl. nézet, szinonima,
--   csak a definíciója tárolódik az adatszótárban. A megoldáshoz a data_object_id oszlopot
--   vizsgáljuk meg.)
SELECT * FROM dba_objects;