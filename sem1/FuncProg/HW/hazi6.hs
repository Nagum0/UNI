module Hazi6 where

-- 1. Szétválasztás választó elem mentén
splitOn :: Eq a => a -> [a] -> [[a]]
splitOn delimiter list = f list where
    f [] = [[]]
    f (x:xs)
        | x == delimiter = [] : rest
        | otherwise = (x : head rest) : tail rest where
            rest = f xs

-- 2. Üres sorok -- HOLNAP
emptyLines :: Num a => String -> [a]
emptyLines str = f (splitOn '\n' str) 1 where
    f [] _ = []
    f (s:rest) count
        | null s = count : f rest (count + 1)
        | otherwise = f rest (count + 1)

-- 3. CSV fájl
csv :: String -> [[String]]
csv [] = []
csv str = f (splitOn '\n' str) where
    f [] = []
    f (line:rest)
        | null line = [] : f rest
        | otherwise = (splitOn ',' line) : f rest