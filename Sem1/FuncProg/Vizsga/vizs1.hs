module Vizs1 where

import Data.List

points :: Integral a => [(String, a, a)] -> [(String, a)]
points xs = calcPoints [] (reverse $ filteredList xs) where
    filteredList xs = takeWhile (\(name, t, h) -> h < 100 && (floor $ (fromIntegral t) / 2) + h < 100) xs

    calcPoints acc [] = acc
    calcPoints acc ((name, t, h):rest) = calcPoints ((name, 100 - (floor $ (fromIntegral t) / 2) - h) : acc) rest

doesContain :: String -> String -> Bool
doesContain [] [] = True
doesContain s1 s2 = search s1 s2 where
    search [] [] = True
    search [] _ = True
    search _ [] = False
    search (s:rest1) (t:rest2)
        | s == t = search rest1 rest2
        | otherwise = search (s:rest1) rest2

firstValid :: [a -> Bool] -> a -> Maybe Int
firstValid fs n = f 0 fs n where
    f _ [] _ = Nothing
    f count (g:rest) n
        | g n = Just count
        | otherwise = f (count + 1) rest n

combineListsIf :: (a -> b -> Bool) -> (a -> b -> c) -> [a] -> [b] -> [c]
combineListsIf _ _ xs [] = []
combineListsIf p f (x:xs) (y:ys)
    | p x y = f x y : combineListsIf p f xs ys
    | otherwise = combineListsIf p f xs ys

splitOn :: String -> Char -> [String]
splitOn [] _ = []
splitOn str c = split [] str c where
    split acc [] _ = [acc]
    split acc (s:rest) c' 
        | s == c' = acc : split [] rest c'
        | otherwise = split (acc ++ [s]) rest c'

splitByLine :: String -> [[String]]
splitByLine [] = []
splitByLine str = map (\s -> splitOn s ';') $ splitOn str '\n'

data Line = Tram Integer [String] | Bus Integer [String] deriving (Eq, Show)

whichBusStop :: String -> [Line] -> [Integer]
whichBusStop _ [] = []
whichBusStop stop ((Tram n stops):rest)
    | stop `elem` stops = n : whichBusStop stop rest
    | otherwise = whichBusStop stop rest
whichBusStop stop ((Bus n stops):rest)
    | stop `elem` stops = n : whichBusStop stop rest
    | otherwise = whichBusStop stop rest

isReservable :: Int -> String -> Bool
isReservable 0 [] = True
isReservable _ [] = False
isReservable n (s:seats) = if isPrefixOf space (s:seats) then True else isReservable n seats where
    space = ['x' | _ <- [1..n]]