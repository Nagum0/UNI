module Gyak6 where

-- insertions 1 [2,3] => [[1,2,3],[2,1,3],[2,3,1]]
insertions :: a -> [a] -> [[a]]
insertions a [] = [[a]]
insertions a list@(x:xs) = (a:list) : [x : ys | ys <- insertions a xs]

-- permutations [1,2,3] => [[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,2,1], [3,1,2]]
permutations :: [a] -> [[a]]
permutations [] = [[]]
permutations (x:xs) = [zs | ys <- permutations xs, zs <- insertions x ys]

-- FOGALMAK:
-- Parametrikusan polimorf fuggveny => Olyan fuggveny, amely mukodese nem fugg a parameter tipusatol.
--     pl.: (:), head, tail, (!!), init, last, insertions, permutations 
-- Ad-hoc polimorf fuggveny => Olyan fuggveny, amely mukodese fugg a parameter tipusatol.
--     pl.: (+) :: Num a => a -> a -> a,
--          (==) :: Eq a => a -> a -> Bool,
--          (-), nub, elem, (/)

-- ESZREVETELEK:
-- Haskell-ben ez, hogy nez ki?
-- Parametrikusan polimorf => A fuggveny tipusaban nincs tipusmegkotes.
-- Ad-hoc polimorf => A fuggveny tipusaban van tipusmegkotes.

reverse' :: [a] -> [a]
reverse' [] = []
reverse' (x:xs) = reverse' xs ++ [x]

reverse'' :: [a] -> [a]
reverse'' xs = reverseAcc [] xs where
    reverseAcc :: [a] -> [a] -> [a]
    reverseAcc acc [] = acc
    reverseAcc acc (x:xs) = reverseAcc (x:acc) xs

{- 
    reverseAcc [] [1,2,3] =
    reverseAcc (1:[]) [2,3] =
    reverseAcc (2:(1:[])) [3] =
    reverseAcc (3:(2:(1:[]))) [] =
    (3:(2:(1:[]))) = 
    [3,2,1]

    Eszrevetelek:
    - Vegtelen listara nem mukodik!!!
    - Ha "atpakolom" a listaelemeket masik listaba, akkor "magikusan" forditott sorrendben lesznek.
-}

fact :: Integral a => a -> a
fact n = factAcc 1 n where
    factAcc :: Integral a => a -> a -> a
    factAcc acc n
        | n <= 0 = acc
        | otherwise = factAcc (acc * n) (n - 1)