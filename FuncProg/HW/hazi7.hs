module Hazi7 where

import Data.List (group, genericReplicate, genericLength)

-- 1. Szétbontás adott tulajdonság mentén
splitOn :: (a -> Bool) -> [a] -> [[a]]
splitOn _ [] = [[]]
splitOn delimiter list = f list where
    f [] = [[]]
    f (x:xs)
        | delimiter x = [] : rest
        | otherwise = (x : head rest) : tail rest where
            rest = f xs

-- 2. Üres listák
countEmptyLists :: Num a => [[[b]]] -> [a]
countEmptyLists lists = map (\list -> count (filter null list)) lists where
    count [] = 0
    count ([]:xs) = 1 + (count xs)

-- 3. Térkép

-- A zipWith miatt nem lesz vegtelen a lista, mert csak addig csinal tuple-kat amig kinem fogy az elso lista elemekbol.
mapping :: [(Char, Char)]
mapping = zipWith (\x y -> (x, y)) (['0'..'9'] ++ ['A'..'Z'] ++ ['a'..'z']) (drop 3 (cycle (['0'..'9'] ++ ['A'..'Z'] ++ ['a'..'z'])))

-- 4. Titkosítás
encodeCaesar :: String -> String
encodeCaesar str = concatMap f str where
    find c = filter ((\(x, _) -> x == c))

    f c
        | null r = "?"
        | otherwise = [snd (head r)] where
            r = find c mapping

-- 5. Visszafejtés
decodeCaesar :: String -> String
decodeCaesar str = concatMap f str where
    find c = filter (\(_, y) -> c == y)

    f c
        | null r = "?"
        | otherwise = [fst (head r)] where
            r = find c mapping

-- 6. Tömörítés, visszaállítás

-- A group xs osszegyujti sublistakba az egymast koveto egyforma elemeket.
-- A map vegig megy ezeken a sublistakon es a lambda function benne pedig pair-ket general ahol az elso elem a sublista head-je a masodik meg a hossza.
compress :: (Eq a, Num b) => [a] -> [(a,b)]
compress [] = []
compress xs = map (\x -> (head x, genericLength x)) (group xs)

-- Itt a concatMap ossze is fuzi az elemeket.
-- A lambdaban pedig replicate-el rakom ossze a ismetlodo elemeket.
decompress :: Integral b => [(a,b)] -> [a]
decompress [] = []
decompress xs = concatMap (\(x, y) -> genericReplicate y x) xs