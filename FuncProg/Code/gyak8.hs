module Gyak8 where

-- $ operator
($$) :: (a -> b) -> a -> b
f $$ x = f x
infixr 0 $$

-- map (+1) $$ filter even [1..10]
-- :t = map (+1) :: Num a => [a] -> [a]

-- map (+1) $$ filter even $$ map (+1) [0..10]

-- :t = map (+1) :: Num a => [a] -> [a]
f :: Num a => [a] -> [a]
f = map (+1)

-- Definialjunk egy olyan fuggvenyt, amely egy lista minden fuggvenyere alkalmazza az 1-es erteket.
g :: Num a => [a -> b] -> [b]
g xs = (map ($ 1)) xs

-- \eta redukcio amikor elhagyogatom a parametereket
g' :: Num a => [a -> b] -> [b]
g' = map ($ 1)

-- Fuggveny kompozicio: (f o g) (x) = f (g (x)) -> Haskellben (.) operator
(...) :: (b -> c) -> (a -> b) -> (a -> c)
f ... g = \x -> f $ g x

-- Tobb magasabb rendu fuggveny:
takeWhile' :: (a -> Bool) -> [a] -> [a]
takeWhile' _ [] = []
takeWhile' f (x:xs)
    | f x = x : takeWhile' f xs
    | otherwise = []

dropWhile' :: (a -> Bool) -> [a] -> [a]
dropWhile' _ [] = []
dropWhile' f l@(x:xs)
    | f x = dropWhile' f xs
    | otherwise = l

-- Ott vagja felbe a listat, ahol a feltetel eloszor nem igaz.
span' :: (a -> Bool) -> [a] -> ([a], [a])
span' _ [] = ([], [])
span' f l@(x:xs)
    | f x = (x: ys, zs)
    | otherwise = ([], l) where
        (ys, zs) = span' f xs

break' :: (a -> Bool) -> [a] -> ([a], [a])
break' = span' . (not .)

iterate'' :: (a -> a) -> a -> [a]
iterate'' f a = a : iterate'' f (f a)

repeat' :: a -> [a]
repeat' = iterate'' id

numsMadeOfOnes :: [Integer]
numsMadeOfOnes = iterate ((+1) . (*10)) 1

numsMadeOfThreesandOnes :: [Integer]
numsMadeOfThreesandOnes = iterate ((+21) . (*10)) 1

-- Azert nem adjuk at as `str`-t, mert a vegen ugyis odairnank.s
dropSpaces :: String -> String
dropSpaces = dropWhile (== ' ')

trim :: String -> String
trim = reverse . dropSpaces . reverse . dropSpaces

{- trim' :: String -> String
trim' str = reverse (dropSpaces (reverse (dropSpaces str))) -}

mapMap :: (a -> b) -> [[a]] -> [[b]]
mapMap = map . map

-- Zeki Bene -> ZB
firstLetters :: String -> String
firstLetters = unwords . map (take 1) . words

monogram :: String -> String
monogram = unwords . map ((:".")) . head . words

-- Ezeket tudjuk altalanositani !!!

sum' :: Num a => [a] -> a
sum' [] = 0
sum' (x:xs) = x + sum' xs

product' :: Num a => [a] -> a
product' [] = 1
product' (x:xs) = x * product' xs

length' :: Num a => [b] -> a
length' [] = 0
length' (_:xs) = 1 + length' xs

elem' :: Eq a => a -> [a] -> Bool
elem' _ [] = False
elem' e (x:xs) = e == x || elem' e xs

and' :: [Bool] -> Bool
and' [] = True
and' (x:xs) = x && and' xs

-- foldr
generalR :: (a -> b -> b) -> b -> [a] -> b
generalR _ acc [] = acc
generalR f acc (x:xs) = f x $ generalR f acc xs

product'' :: Num a => [a] -> a
product'' = generalR (\x acc -> x * acc) 1

length'' :: Num a => [b] -> a
length'' = foldr (\_ acc -> 1 + acc) 0