module Gyak7 where

import Data.Char

add1 :: Num a => [a] -> [a]
add1 [] = []
add1 (x:xs) = x + 1 : add1 xs

gt0 :: (Num a, Ord a) => [a] -> [Bool]
gt0 [] = []
gt0 (x:xs) = (x > 0) : gt0 xs

toUpperAll :: String -> String
toUpperAll [] = []
toUpperAll (x:xs) = toUpper x : toUpperAll xs

--------------------------------------------------------------------------------------------------------
-- Nevtelen fuggvenyek (Lambda fuggveny)
-- (\a b -> 2 * a + b)

map' :: (a -> b) -> [a] -> [b]
map' _ [] = []
map' f (x:xs) = (f x) : map' f xs

-- a -> b -> c === a -> (b -> c)
-- Curry-zes elve: Minden fuggveny egy parameteres.
-- Tudom parcialisan alkalmazni:
--      Egy fuggvenynek nem adom at az osszes szukseges parameteret, hogy "eredmenyt adjon vissza".

-- Magasabb rendu fuggveny: Olyan fuggveny, amely fuggvenyt var parameterul.

filter' :: (a -> Bool) -> [a] -> [a]
filter' _ [] = []
filter' f (x:xs)
    | f x = x : filter' f xs
    | otherwise = filter' f xs

-- Lista generatorral
map'' :: (a -> b) -> [a] -> [b]
map'' f xs = [f y | y <- xs]

filter'' :: (a -> Bool) -> [a] -> [a]
filter'' f xs = [y | y <- xs, f y]