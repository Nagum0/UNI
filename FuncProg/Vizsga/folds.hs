module Folds where

splitOn' :: Eq a => a -> [a] -> [[a]]
splitOn' del xs = foldr (\x acc -> if x == del then [] : acc else (x : head acc) : (tail acc)) [[]] xs

splitOn :: Eq a => a -> [a] -> [[a]]
splitOn del xs = foldr (\x acc -> case x == del of
    True -> [] : acc
    False -> (x : head acc) : tail acc) [[]] xs

format' :: Integral b => b -> String -> String
format' n str = foldr (\_ acc -> acc ++ " ") str [1..(n - (fromIntegral $ length str))]

takeWhile' :: (a -> Bool) -> [a] -> [a]
takeWhile' pred xs = foldr (\x acc -> case pred x of
    True -> x : acc
    False -> []) [] xs

dropWhile' :: (a -> Bool) -> [a] -> [a]
dropWhile' pred xs = foldr (\x acc -> case pred x of
    True -> tail acc
    False -> xs) [] xs

which :: ([Char], [Char], [Char]) -> Char -> Int
which (s1, s2, s3) c
    | c `elem` s1 = 1
    | c `elem` s2 = 2
    | c `elem` s3 = 3
    | otherwise = 0