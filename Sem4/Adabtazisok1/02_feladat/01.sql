SELECT *
FROM SZERET s1, SZERET s2;

-- 8.  Kik szeretnek legalább kétféle gyümölcsöt?
SELECT DISTINCT s1.nev
FROM SZERET s1, SZERET s2
WHERE s1.nev = s2.nev AND s1.gyumolcs != s2.gyumolcs;

-- 9.  Kik szeretnek legalább háromféle gyümölcsöt?
SELECT DISTINCT s1.nev
FROM SZERET s1, SZERET s2, SZERET s3
WHERE s1.nev = s2.nev 
AND s2.nev = s3.nev 
AND s1.gyumolcs != s2.gyumolcs
AND s2.gyumolcs != s3.gyumolcs
AND s1.gyumolcs != s3.gyumolcs;

-- 10. Kik szeretnek legfeljebb kétféle gyümölcsöt?
-- ??
SELECT DISTINCT s1.nev
FROM SZERET s1, SZERET s2, SZERET s3
WHERE s1.nev = s2.nev
AND s2.nev = s3.nev
AND (s1.gyumolcs = s2.gyumolcs OR s1.gyumolcs != s2.gyumolcs)
AND (s1.gyumolcs = s3.gyumolcs OR s2.gyumolcs = s3.gyumolcs OR (s1.gyumolcs != s3.gyumolcs AND s2.gyumolcs != s3.gyumolcs))
AND (s1.gyumolcs != s2.gyumolcs OR s1.gyumolcs = s2.gyumolcs)
AND (s1.gyumolcs != s3.gyumolcs OR s1.gyumolcs = s3.gyumolcs)
AND (s2.gyumolcs != s3.gyumolcs OR s2.gyumolcs = s3.gyumolcs);

-- 11. Kik szeretnek pontosan kétféle gyümölcsöt?
-- ??
