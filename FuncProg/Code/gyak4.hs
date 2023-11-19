module Gyak4 where

-- ISMETLES

-- Vissza adja az osszes 'a' szot egy String-bol.
onlyAs :: String -> [String]
onlyAs str = ["a" | "a" <- words str]

-- Kiirja a 2 szo elso betujet.
initials :: String -> String
initials name = [x | (x:_) <- words name]

-------------------------------------------

-- REKURZIO

fact :: Integer -> Integer
fact 0 = 1
fact n = fact (n - 1) * n

sum' :: Num a => [a] -> a
sum' [] = 0
sum' (x:xs) = sum' xs + x

product' :: Num a => [a] -> a
product' [] = 1
product' (x:xs) = x * product' xs

elem' :: Eq a => a -> [a] -> Bool
elem' e [] = False
elem' e (x:xs) = e == x || elem' e xs

last' :: [a] -> a
last' [a] = a
last' (_:xs) = last' xs

init' :: [a] -> [a]
init' [_] = []
init' (x:xs) = x : init' xs

zip' :: [elso] -> [masodik] -> [(elso, masodik)]
zip' [] _ = []
zip' _ [] = []
zip' (x:xs) (y:ys) = (x, y) : zip' xs ys

nub' :: Eq a => [a] -> [a]
nub' [] = [] 
nub' (x:xs) = x : nub' [y | y <- xs, y /= x]

-- NEZD AT OTTHON
quickSort :: Ord a => [a] -> [a]
quickSort [] = []
quickSort (x:xs) = quickSort [y | y <- xs, y < x] ++ x : quickSort [y | y <- xs, y >= x]

-- DEFINICIO --
-- Rekurziv fuggveny definicio => Olyan fuggveny, amely onmaga definialasahoz sajat magat hasznalja fel.