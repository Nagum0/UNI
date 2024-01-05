module V1 where

import Data.List (isPrefixOf)

-- Ryuk almai:
type Apple = (Bool, Int)
type Tree = [Apple]
type Garden = [Tree]

ryuksApples :: Garden -> Int
ryuksApples [] = 0
ryuksApples garden = foldr (\tree acc -> (foldr (\app acc' -> collect app acc') 0 tree) + acc) 0 garden where
    collect (state, height) acc'
        | not state = acc'
        | state && height <= 3 = 1 + acc'
        | otherwise = acc'

-- Verseny:
points :: Integral a => [(String, a, a)] -> [(String, a)]
points xs = foldr (\player acc -> calcPoints player acc) [] xs where
    calcPoints (_, _, 100) acc' = acc'
    calcPoints (name, time, minus) acc'
        | 100 - minusPoints <= 0 = acc'
        | otherwise = (name, 100 - minusPoints) : acc' where
            minusPoints = (floor $ fromIntegral time / 2) + minus

-- Szoveg a szovegben:
doesContain :: String -> String -> Bool
doesContain str1 str2 = str1 == search str1 str2 where
    search _ [] = []
    search [] _ = []
    search (s1:rest1) (s2:rest2)
        | s1 == s2 = s1 : search rest1 rest2
        | otherwise = search (s1:rest1) rest2

-- Barbie:
barbie :: [String] -> String
barbie skirts = getSkirt skirts 1 where
    getSkirt [] _ = "farmer" 
    getSkirt ["rozsaszin"] _ = "rozsaszin"    
    getSkirt [x] i
        | i `mod` 2 == 0 && x /= "fekete" = x
        | otherwise = "farmer"
    getSkirt ("rozsaszin":_) _ = "rozsaszin"
    getSkirt (skirt:rest) i
        | i `mod` 2 == 0 && skirt /= "fekete" = skirt
        | otherwise = getSkirt rest (i + 1)

-- Elso teljesulo predikatum:
firstValid :: [a -> Bool] -> a -> Maybe Int
firstValid ps val = count ps (Just 0) where
    count [] _ = Nothing
    count (p:rest) (Just i)
        | p val = Just $ i
        | otherwise = count rest (Just $ i + 1)

-- Alkalmazott szures:
combineListsIf :: (a -> b -> Bool) -> (a -> b -> c) -> [a] -> [b] -> [c]
combineListsIf cond f xs ys = foldr (\(x,y) acc -> case cond x y of True -> f x y : acc
                                                                    False -> acc) [] $ zip xs ys

-- Tomegkozlekedes:
data Line = Tram Integer [String] | Bus Integer [String] deriving (Eq, Show)

whichBusStop :: String -> [Line] -> [Integer]
whichBusStop stop lines = foldr (\line acc -> case line of
                                                   Tram n stops -> acc
                                                   Bus n stops  -> case stop `elem` stops of
                                                                                    True -> n : acc
                                                                                    False -> acc) [] lines

-- Szinhazi helyfoglalas:
isReservable :: Int -> String -> Bool
isReservable 0 "" = True
isReservable _ "" = False
isReservable n seats@(seat:rest) = case (isPrefixOf space seats) of
                                                         True -> True
                                                         False -> isReservable n rest
    where
        space = ['x' | _ <- [1..n]] 