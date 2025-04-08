SELECT * FROM CIKK;
SELECT * FROM SZALLIT;
SELECT * FROM SZALLITO;
SELECT * FROM PROJEKT;

-- Adjuk meg azon cikkek kódját és nevét, amelyeket valamelyik pécsi ('Pecs') szállító szállít. [ckod, cnev]
SELECT DISTINCT ckod, cnev
FROM CIKK
WHERE ckod IN (
    SELECT ckod
    FROM SZALLIT NATURAL JOIN SZALLITO
    WHERE telephely = 'Pecs'
);

-- Adjuk meg, hogy hány ilyen cikk van. [darab]
SELECT COUNT(DISTINCT ckod)
FROM CIKK
WHERE ckod IN (
    SELECT ckod
    FROM SZALLIT NATURAL JOIN SZALLITO
    WHERE telephely = 'Pecs'
);

-- Adjuk meg azon cikkek kódját és nevét, amelyeket egyik pécsi szállító sem szállít. [ckod, cnev]
(SELECT DISTINCT ckod, cnev
FROM SZALLIT NATURAL JOIN CIKK)
MINUS
(SELECT DISTINCT ckod, cnev
FROM CIKK
WHERE ckod IN (
    SELECT ckod
    FROM SZALLIT NATURAL JOIN SZALLITO
    WHERE telephely = 'Pecs'
));

-- Adjuk meg, hogy hány ilyen cikk van. [darab]

-- Adjuk meg azon szállítók nevét, akiknek a státusza 10-nél nagyobb és budapesti projektbe szállítanak szék nevű cikket. ('Budapest', 'szek')  [sznev]

-- Adjuk meg azon projektek kódját, amelyekhez szállítanak kék cikket. ('kek')  [pkod]
SELECT pkod
FROM SZALLIT NATURAL JOIN CIKK
WHERE szin = 'kek';

-- Adjuk meg azon projektek kódját és nevét, amelyekhez szállítanak kék cikket. [pkod, pnev]

-- Adjuk meg azon projektek kódját és nevét, amelyekhez nem szállítanak kék cikket. [pkod, pnev]
(SELECT pkod
FROM SZALLIT NATURAL JOIN CIKK)
MINUS
(SELECT pkod
FROM SZALLIT NATURAL JOIN CIKK
WHERE szin = 'kek');

-- Adjuk meg azon cikkek kódját, amelyeket szállítanak valahova. [ckod]

-- Adjuk meg, hogy hány ilyen cikk van. [darab]

-- Adjuk meg azon cikkek kódját, amelyeket nem szállítanak sehova. [ckod]
SELECT DISTINCT ckod
FROM CIKK
WHERE ckod NOT IN (
    SELECT ckod
    FROM SZALLIT
);

-- Adjuk meg azon cikkek kódját és nevét, amelyeket sehova nem szállítanak.  [ckod, cnev]

-- Adjuk meg azon kék ('kek') cikkek kódját, amelyeket szállítanak valahova. [ckod] 

-- Adjuk meg azon piros színű cikkek kódját, amelyeket sehova nem szállítanak. [ckod]

-- Adjuk meg azon cikkek nevét, amelyeket minden projekthez szállítanak.  [cnev]

-- Melyik cikket hány különböző projekthez szállítják? [ckod, cnev, darab]

-- Melyik cikket szállítják a legtöbb projekthez? (Leolvassuk a rendezett listából) [ckod, cnev] Majd adjuk meg leolvasás nélkül felső-N elemzés segítségével. [ckod, cnev]

-- Adjuk meg azon cikkek nevét, amelyeket valamelyik projekthez nem szállítanak. [cnev]

-- Adjuk meg azon cikkek kódját és nevét, amelyeket kevesebb mint 6 projekthez szállítanak. [ckod, cnev]

-- Adjuk meg azon zöld ('zold') színű cikkek nevét, amelyeket minden projekthez szállítanak. [cnev]

-- Adjuk meg azon zöld ('zold') színű cikkek nevét, amelyet valamelyik projekthez nem szállítanak. [cnev] 

-- Adjuk meg azon projektek nevét, amelyekhez minden zöld ('zold') színű cikket szállítanak. [pnev]

-- Adjuk meg azon szállítók nevét és telephelyét, akik valamelyik cikket minden projekthez szállítják. [sznev, telephely]

-- Adjuk meg azon szállítók nevét és telephelyét, akik valamelyik cikket minden pécsi ('Pecs') projekthez  szállítják. [sznev, telephely]

-- Adjuk meg azon szállítók nevét és telephelyét, akik valamelyik kék ('kek') cikket minden projekthez szállítják. [sznev, telephely]

-- Adjuk meg azon szállítók nevét, akik minden cikket szállítanak minden projekthez. [sznev]

-- Adjuk meg azon szállítók nevét, akik minden kék cikket szállítanak minden projekthez. [sznev]
