module Hazi5 where

import Data.Char (toUpper, isDigit)
import Data.List (group)

-- 1. Karakter-átalakítás
toUpperThird :: String -> String
toUpperThird (s:t:r:rest) = s : t : toUpper r : rest
toUpperThird str = str

-- 2. Rendezett-e
isSorted :: Ord a => [a] -> Bool
isSorted (x:y:xs) = x <= y && isSorted (y:xs)
isSorted _ = True

-- 3. Indexelés "javítása"
(!!!) :: Integral b => [a] -> b -> a
(!!!) xs i
    | i < 0 = find (reverse xs) (-i) 1
    | otherwise = find xs i 0 where
        find (s:rest) j limit
            | j == limit = s
            | otherwise = find rest (j - 1) limit

-- 4. Kiegészítés
format :: Integral b => b -> String -> String
format n [] 
    | n <= 0 = []
    | otherwise = ' ' : format (n - 1) []
format n (s:str) = s : format (n - 1) str
        
-- 5. Viharos vidék
mightyGale :: (Num a, Ord b, Num b, Integral c) => [(String, a, b, c)] -> String
mightyGale [] = ""
mightyGale ((name, _, wind, _):xs)
    | wind > 110 = name
    | otherwise = mightyGale xs

-- 6. Titkok tudója
cipher :: String -> String
cipher (s:t:r:rest)
    | isDigit r = [s, t]
    | otherwise = cipher (t:r:rest)
cipher _ = ""

-- 7. Dupla elemek
doubleElements :: [a] -> [a]
doubleElements [] = []
doubleElements (x:xs) = x : x : doubleElements xs

-- 8. Sok szóköz
deleteDuplicateSpaces :: String -> String
deleteDuplicateSpaces str = unwords (words str)

-- 9. Lucas-sorozat
lucas :: (Integral a, Num b) => a -> b
lucas 0 = 2
lucas 1 = 1
lucas n
    | n < 0 = 0
    | otherwise = lucas (n - 1) + lucas (n - 2)