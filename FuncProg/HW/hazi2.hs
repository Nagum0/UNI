-- Első feladat
inc :: Int -> Int
inc x = x + 1

lesser_heal :: Int -> Int
lesser_heal x = inc(inc(inc x))

-- Második feladat
lookout :: Int -> Int -> Bool
lookout x y = (div y 10) < x

-- Harmadik feladat
volume :: Int -> Int -> Int
volume x y = x + (y * (mod x 12))

-- Típus magyarázó
type CurrentDistrict = Int
type NextDistrict = Int
type HealthDamage = Int
type ArmorDamage = Int
type Health = Int
type Armor = Int

-- Negyedik feladat
move :: (CurrentDistrict, NextDistrict) -> NextDistrict
move (x, y) = y

-- Ötödik feladat
arcaneMissiles :: (HealthDamage, ArmorDamage) -> (Health, Armor) -> (Health, Armor)
arcaneMissiles (x, y) (z, v) = (z - x, v - y)

-- Hatodik feladat
type Enhance = Int

arcaneMissilesMark1 :: Enhance -> (HealthDamage, ArmorDamage) -> (Health, Armor) -> (Health, Armor)
arcaneMissilesMark1 e (x, y) (z, v) = (z - e * x, v - e * y)

-- Hetedik feladat
arcaneBlast :: (HealthDamage , ArmorDamage) -> (HealthDamage , ArmorDamage) -> (Health , Armor) -> (Health , Armor)
arcaneBlast (x, y) (z, v) (h, a) = (h - (x * z + y * v), a - (x * z + y * v))