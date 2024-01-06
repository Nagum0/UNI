module Lakas where

import Data.List (elemIndex)

type AdatForma = [(Integer, Integer)]

parseFile :: String -> AdatForma 
parseFile str = foldr (\line acc -> (read $ head $ words line, read $ last $ words line) : acc) [] $ lines str  

legdragabbLakas :: AdatForma -> Int
legdragabbLakas adatok = f $ elemIndex (maximum xs) xs where
    xs = map (\(_,y) -> y) adatok
    f = (\(Just n) -> n + 1) 

nagyOlcso :: AdatForma -> Int
nagyOlcso xs = foldr (\(t,a) acc -> case t > 100 && a < 40 of
    True -> acc + 1
    False -> acc) 0 xs

kulonbTeruletek :: AdatForma -> Int
kulonbTeruletek xs = f $ foldr (\t acc@(n,ts) -> case t `elem` ts of
    True -> acc
    False -> ((n + 1),t : ts)) (0, []) $ map (\(x,_) -> x) xs where
    f (n', _) = n' 

dragaLakasok :: AdatForma -> (Int, [Int])
dragaLakasok adatok = foldr (\ar acc -> if ar > 100 then f ar acc else acc) (0, []) xs where
    f x (n, is) = ((n + 1), (f' $ elemIndex x xs) : is) where
        f' = (\(Just n) -> n + 1) 

    xs = map (\(_,y) -> y) adatok 

main :: IO()
main = do
    putStrLn "File:"
    fileName <- getLine
    contents <- readFile fileName
    let adatok = parseFile contents
    -- a)
    let a = legdragabbLakas adatok
    -- b)
    let b = nagyOlcso adatok
    -- c)
    let c = kulonbTeruletek adatok
    -- d)
    let d = dragaLakasok adatok
    putStrLn $ show a
    putStrLn $ show b
    putStrLn $ show c
    putStrLn $ show d