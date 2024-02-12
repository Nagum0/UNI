-- Curried functions
zipWith' :: (a -> b -> c) -> [a] -> [b] -> [c]
zipWith' _ [] _ = []
zipWith' _ _ [] = []
zipWith' func (x:xs) (y:ys) = func x y : zipWith' func xs ys

-- Maps & Filters
-- MAP
map' :: (a -> b) -> [a] -> [b]
map' _ [] = []
map' f (x:xs) = f x : map' f xs

-- `map` just with list comprehension
mapNums :: (Int -> Int) -> Int -> Int -> [Int]
mapNums f start end = [f x | x <- [start..end]]

-- FILTER
filter' :: (a -> Bool) -> [a] -> [a]
filter' _ [] = []
filter' f (x:xs)
    | f x == True = x : filter' f xs
    | otherwise = filter' f xs

quickSort :: (Ord a) => [a] -> [a]
quickSort [] = []
quickSort (x:xs) =
    let 
        smallerSorted = quickSort (filter' (< x) xs)
        biggerSorted = quickSort (filter' (>= x) xs)
    in
        smallerSorted ++ [x] ++ biggerSorted