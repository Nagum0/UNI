module Gyak5 where

-- Szamozzuk meg a szavakat

numberWords :: Integral a => String -> [(a, String)]
numberWords str = zip [1..] (words str)

{- WHERE -}

numberWords' :: Num a => String -> [(a, String)]
numberWords' str = zip (fromN 1) (words str) 
    where
        fromN :: Num a => a -> [a]
        fromN n = n : fromN (n + 1)

{- LET/IN -}
numberWords'' :: Num a => String -> [(a, String)]
numberWords'' str =
    let
        fromN n = n : fromN (n + 1)
    in
        zip (fromN 1) (words str)

-- Toroljunk egy elemet az osszes lehetseges modon
-- deletions [1, 2, 3] = [[2, 3], [1, 3], [1, 2]]
deletions :: [a] -> [[a]]
deletions [] = []
deletions (x:xs) = xs : [x : ys | ys <- deletions xs]

{- GUARD-ok -}
fact :: Integer -> Integer
fact n 
    | n > 0 = n * fact (n - 1)
    | otherwise = 1

take' :: Integral a => a -> [b] -> [b]
take' n _ | n <= 0 = []
take' n [] = []
take' n (x:xs) = x : take' (n - 1) xs

drop' :: Integral a => a -> [b] -> [b]
drop' n xs | n <= 0 = xs 
drop' n [] = []
drop' n (x:xs) = drop' (n - 1) xs

splitAt' :: Integral a => a -> [b] -> ([b], [b])
splitAt' n xs | n <= 0 = ([], xs)
splitAt' n [] = ([], [])
splitAt' n (x:xs) = (x : ys, zs) where
    (ys, zs) = splitAt' (n - 1) xs