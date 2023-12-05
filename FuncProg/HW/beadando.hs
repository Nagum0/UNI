module Beadando where

showState a = show a
showMage a = show a
eqMage a b =  a == b
showUnit a = show a
showOneVOne a = show a

type Name = String
type Health = Integer
type Spell = (Integer -> Integer)
type Army = [Unit]
type EnemyArmy = Army
type Amount = Integer

-- Első feladat (Felkészülés)
---------------------------------------------------------------------------------------------------

-- STATE
data State a = Alive a | Dead deriving Eq

instance Show a => Show (State a) where
    show (Alive a) = show a
    show Dead = "Dead"

-- ENTITY
data Entity = Golem Health | HaskellElemental Health deriving (Eq, Show)

-- MAGE
data Mage = Master Name Health Spell

papi = let 
    tunderpor enemyHP
        | enemyHP < 8 = 0
        | even enemyHP = div (enemyHP * 3) 4
        | otherwise = enemyHP - 3
    in Master "Papi" 126 tunderpor

java = Master "Java" 100 (\x -> x - (mod x 9))

traktor = Master "Traktor" 20 (\x -> div (x + 10) ((mod x 4) + 1))

jani = Master "Jani" 100 (\x -> x - div x 4)

skver = Master "Skver" 100 (\x -> div (x+4) 2)

instance Show Mage where
    show (Master n h s)
        | h < 5 = "Wounded " ++ n
        | otherwise = n

instance Eq Mage where
    Master n1 h1 s1 == Master n2 h2 s2 = n1 == n2 && h1 == h2
    Master n1 h1 s1 /= Master n2 h2 s2 = n1 /= n2 && h1 /= h2

-- UNIT
data Unit = M (State Mage) | E (State Entity) deriving Eq

instance Show Unit where
    show (M sm) = show sm
    show (E se) = show se

-- Második feladat (Elesettek)
---------------------------------------------------------------------------------------------------

formationFix :: Army -> Army
formationFix [] = []
formationFix army = (filter (\x -> checkState x) army) ++ (filter (\x -> not (checkState x)) army) where
    checkState (M (Alive _)) = True
    checkState (M (Dead)) = False
    checkState (E (Alive _)) = True
    checkState (E (Dead)) = False

-- Harmadik feladat (Vége?)
---------------------------------------------------------------------------------------------------

over :: Army -> Bool
over [] = True
over army = all (\x -> isDead x) army where
    isDead (M (Alive _)) = False
    isDead (M (Dead)) = True
    isDead (E (Alive _)) = False
    isDead (E (Dead)) = True

potionMaster = 
  let plx x
        | x > 85  = x - plx (div x 2)
        | x == 60 = 31
        | x >= 51 = 1 + mod x 30
        | otherwise = x - 7 
  in Master "PotionMaster" 170 plx

-- Negyedik feladat (Ütközet)
---------------------------------------------------------------------------------------------------

{-
rest = drop (min (length enemies) (length army)) (toDrop enemies army) where
        toDrop enemies army
            | length enemies > length army = enemies
            | otherwise = army
-}

fight :: EnemyArmy -> Army -> Army
fight [] army = army
fight enemies [] = []
fight enemies army = f enemies army where
    f [] a = a
    f e [] = []
    f ((E (Alive (HaskellElemental _))):e_rest) ((E (Alive (Golem hp))):a_rest) = (E $ Alive $ Golem (hp - 3)) : f e_rest a_rest
    f ((E (Alive (Golem _))):e_rest) ((E (Alive (Golem hp))):a_rest) = (E $ Alive $ Golem (hp - 1)) : f e_rest a_rest
    f (m@(M (Alive (Master _ _ spell))):e_rest) a = map (\unit -> mageAttack spell unit) a where
        mageAttack spell (E (Alive (Golem hp))) = (E $ Alive $ Golem (spell hp))

-- Current otlet ugye az hogy ebben az esetben:
-- [E (Alive (Golem 67)),E (Alive (Golem 11)),E (Alive (Golem 8)),E (Alive (Golem 11)),E (Alive (Golem 11))]
-- Az tortenik hogy vegig megy a listan a mageAttack, de meg van egy HaskellElementalunk aki megtamadja a 
-- 3-dik golemet es az mar ignoralva van.
-- Otlet probald a mapet beleagyazni a `fight`-fuggvenybe megint.
-- A magusok azt tamadjak meg akik veluk allnak es mindenkit elottuk.