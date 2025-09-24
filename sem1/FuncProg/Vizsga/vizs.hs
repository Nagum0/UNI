module Vizs where

import Data.List (words, isPrefixOf)

weirdoPow :: Integral a => [a] -> [a]
weirdoPow [] = []
weirdoPow [x] = [x]
weirdoPow (x:y:rest) = x ^ y : weirdoPow (y:rest)

replacePunctuation :: String -> Char -> String
replacePunctuation str c = map (\s -> change s) str where
    change ',' = c
    change ';' = c
    change '?' = c
    change '.' = c
    change '!' = c
    change s' = s'

avgWordLength :: String -> Int
avgWordLength [] = 0
avgWordLength str = calcAvg $ map (\word -> length word) $ words str where
    calcAvg xs = floor $ (fromIntegral $ sum xs) / (fromIntegral $ length xs)

indecesOfNothings :: Integral b => [Maybe a] -> [b]
indecesOfNothings xs = getIndex xs 0 where
    getIndex [] _ = []
    getIndex (Nothing:rest) i = i : getIndex rest (i + 1)
    getIndex (_:rest) i = getIndex rest (i + 1)

juxtapose :: Eq a => [a] -> [a] -> Maybe [a]
juxtapose [] [] = Nothing
juxtapose xs [] = Just xs
juxtapose [] _ = Nothing
juxtapose xl@(x:xs) yl@(y:ys)
    | isPrefixOf xl yl = Nothing
    | x == y = juxtapose xs ys
    | otherwise = Just xl

type Age = Integer
data TreeType = Birch | Oak | Beech | Maple deriving (Show, Eq)
data Tree = Alive TreeType Age | Dead TreeType Age deriving (Show, Eq)

updateTreeAges :: [Tree] -> [Tree]
updateTreeAges trees = map (\t -> case t of
    (Alive tree n) -> (Alive tree (n + 1))
    (Dead tree n) -> (Dead tree n)) trees

strictFilter :: [a -> Bool] -> [a] -> [a]
strictFilter fs xs = filter (\x -> check x fs) xs where
    check x' fs' = foldr (\f acc -> case f x' of
        True -> acc
        False -> False) True fs'

localMin :: Ord a => [a]{-véges-} -> Maybe a
localMin [] = Nothing
localMin xs = foldr (\x acc -> find x acc) Nothing $ search xs where
    find n Nothing = Just n
    find n c@(Just y)
        | n > y = Just n
        | otherwise = c

    search [] = []
    search [_] = []
    search [x,y] = []
    search (x:y:z:rest)
        | x > y && y < z = y : search (z:rest)
        | otherwise = search (y:z:rest)