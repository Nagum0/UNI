maximum' :: (Ord a) => [a] -> a
maximum' [] = error "List is empty."
maximum' [a] = a
maximum' (x:xs) = max x (maximum' xs)

fact :: Integer -> Integer
fact 1 = 1
fact n 
    | n <= 0 = 1
    | otherwise = n * f
    where f = fact (n - 1)

replicate' :: (Num i, Ord i) => i -> a -> [a]  
replicate' x y
    | x <= 0 = []
    | otherwise = y:replicate' (x - 1) y

take' :: (Num i, Ord i) => i -> [a] -> [a]
take' n _ 
    | n <= 0 = []
take' _ [] = []
take' n (x:xs) = x:take' (n - 1) xs

elem' :: (Eq a) => a -> [a] -> Bool
elem' a [] = False
elem' a (x:xs) 
    | a == x = True
    | otherwise = elem' a xs

suM :: (Num a) => [a] -> a
suM [] = error "Can't return the sum of an empty list."
suM [a] = a
suM (x:xs) = x + (suM xs)

fib :: Integer -> Integer
fib 0 = 1
fib 1 = 1
fib n = fib (n - 1) + fib (n - 2)