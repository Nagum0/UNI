module HWS where

-- |-- 5. Házi Feladat --|
---------------------------------------------------------------------------------------------------
import Data.Char (toUpper, isDigit)
import Data.List (words, unwords, group, genericLength, genericReplicate)

toUpperThird :: String -> String
toUpperThird [] = []
toUpperThird (s:t:r:rest) = s : t : (toUpper r) : rest
toUpperThird str = str

isSorted :: Ord a => [a] -> Bool
isSorted [] = True
isSorted [x] = True
isSorted (x:y:rest)
    | x > y = False
    | otherwise = isSorted rest

(!!!) :: Integral b => [a] -> b -> a
(!!!) xs i
    | i < 0 = get (reverse xs) (-i) 0
    | otherwise = get xs i 0 where
        get (y:ys) j l
            | j == l = y
            | otherwise = get ys (j - 1) l

format :: Integral b => b -> String -> String
format n []
    | n <= 0 = []
    | otherwise = ' ' : format (n - 1) []
format n (s:rest) = s : format (n - 1) rest

mightyGale :: (Num a, Ord b, Num b, Integral c) => [(String, a, b, c)] -> String
mightyGale = foldr (\(name, _, speed, _) acc -> if speed > 110 then name else acc) []
 
cipher :: String -> String
cipher [] = []
cipher (s:t:r:rest)
    | isDigit r = (s:[t])
    | otherwise = cipher (t:r:rest)
cipher str = []

doubleElements :: [a] -> [a]
doubleElements xs = foldr (\x acc -> x : x : acc) [] xs

deleteDuplicateSpaces :: String -> String
deleteDuplicateSpaces = unwords . words

lucas :: (Integral a, Num b) => a -> b
lucas 0 = 2
lucas 1 = 1
lucas n
    | n < 0 = 0
    | otherwise = lucas (n - 1) + lucas (n - 2)

-- |-- 6. házi feladat: Szövegfelbontás --|
---------------------------------------------------------------------------------------------------
splitOn :: Eq a => a -> [a] -> [[a]]
splitOn _ [] = []
splitOn delimiter list = split list where
    split [] = [[]]
    split (x:xs)
        | x == delimiter = [] : rest
        | otherwise = (x : head rest) : tail rest where
            rest = split xs

emptyLines :: Num a => String -> [a]
emptyLines [] = [1]
emptyLines str = count (splitOn '\n' str) 0 where
    count [] _ = []
    count (xs:xss) n
        | null xs = (n + 1) : count xss (n + 1)
        | otherwise = count xss (n + 1)

csv :: String -> [[String]]
csv [] = []
csv str = map (\s -> splitOn ',' s) $ splitOn '\n' str

-- |-- 7. házi feladat: térkép --|
---------------------------------------------------------------------------------------------------
splitOn'' :: (a -> Bool) -> [a] -> [[a]]
splitOn'' _ [] = []
splitOn'' predicate list = split list where
    split [] = [[]]
    split (x:xs)
        | predicate x = [] : rest
        | otherwise = (x : head rest) : tail rest where
            rest = split xs

countEmptyLists :: Num a => [[[b]]] -> [a]
countEmptyLists [] = []
countEmptyLists lists = map (\xss -> count $ filter null xss) lists where
    count [] = 0
    count ([]:xs) = 1 + count xs

mapping :: [(Char, Char)]
mapping = zipWith (\x y -> (x, y)) m $ drop 3 $ cycle m where
    m = ['0'..'9'] ++ ['A'..'Z'] ++ ['a'..'z']

encodeCaesar :: String -> String
encodeCaesar [] = []
encodeCaesar str = map (\c -> push c) str where
    push c = case filter (\(x, y) -> c == x) mapping of [] -> '?'
                                                        [(x,y)] -> y

decodeCaesar :: String -> String
decodeCaesar [] = []
decodeCaesar str = map (\c -> unpush c) str where
    unpush c = case filter (\(x, y) -> c == y) mapping of [] -> '?'
                                                          [(x,y)] -> x

compress :: (Eq a, Num b) => [a] -> [(a,b)]
compress [] = []
compress xs = map (\x -> (head x, genericLength x)) $ group xs

decompress :: Integral b => [(a,b)] -> [a]
decompress [] = []
decompress xs = concatMap (\(x,len) -> genericReplicate len x) xs


-- |-- 7. házi feladat: térkép --|
---------------------------------------------------------------------------------------------------
apsOnLists :: [a -> b] -> [[a]] -> [[b]]
apsOnLists [] _ = []
apsOnLists _ [] = []
apsOnLists fs xss = map (\(f, xs) -> map f xs) $ zip fs xss

lucas' :: [Integer]
lucas' = 2 : 1 : zipWith (+) lucas' (tail lucas')

map' :: (a -> b) -> [a] -> [b]
map' f xs = foldr (\x acc -> f x : acc) [] xs

filter' :: (a -> Bool) -> [a] -> [a]
filter' f xs = foldr (\x acc -> case f x of True -> x : acc
                                            False -> acc ) [] xs

takeWhile' :: (a -> Bool) -> [a] -> [a]
takeWhile' f xs = foldr (\x acc -> add (f x) x acc) [] xs where
    add cond x' rest
        | cond = x' : rest
        | otherwise = []

dropWhile' :: (a -> Bool) -> [a] -> [a]
dropWhile' f xs = foldr d [] xs where
    d e acc
        | f e = tail acc
        | otherwise = xs

splitOn' :: (a -> Bool) -> [a] -> [[a]]
splitOn' f xs = foldr (\x acc -> split x acc) [[]] xs where
    split x' acc'
        | f x' = [] : acc'
        | otherwise = (x' : a) : as where
            (a:as) = acc'