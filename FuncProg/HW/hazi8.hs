module Hazi8 where

import Data.List (inits, tails)

-- 1. Sok függvényalkalmazás sok listán
apsOnLists :: [a -> b] -> [[a]] -> [[b]]
apsOnLists fs = map (\(f, xs) -> map f xs) . zip fs

-- 2. Lucas-sorozat jobban és gyorsabban
lucas :: [Integer]
lucas = 2 : 1 : zipWith (+) lucas (tail lucas)

-- 3. Részlisták
sublists :: [a] -> [[a]]
sublists = ([] :) . (filter (not . null) . concatMap tails . inits)

-- 4. Adott tulajdonságúak törlése
deletionsBy :: (a -> Bool) -> [a] -> [[a]]
deletionsBy _ [] = []
deletionsBy f (x:xs)
    | f x = xs : [x : ys | ys <- deletionsBy f xs]
    | otherwise = [x : ys | ys <- deletionsBy f xs]

-- 5. foldr
map' :: (a -> b) -> [a] -> [b]
map' f = foldr (\x acc -> f x : acc) []

filter' :: (a -> Bool) -> [a] -> [a]
filter' f = foldr (\x acc -> g (f x) x ++ acc) [] where
    g True x = [x]
    g False _ = []

takeWhile' :: (a -> Bool) -> [a] -> [a]
takeWhile' f = foldr (\x acc -> g (f x) x acc) [] where
    g check elem rest
        | check = elem : rest
        | otherwise = []

dropWhile' :: (a -> Bool) -> [a] -> [a]
dropWhile' f xs = foldr g [] xs where
    g elem acc
        | f elem = tail acc
        | otherwise = xs

splitOn' :: (a -> Bool) -> [a] -> [[a]]
splitOn' delimiter = foldr f [[]] where
    f x (a:acc)
        | delimiter x = [] : a : acc
        | otherwise = (x : a) : acc