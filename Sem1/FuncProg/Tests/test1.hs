module Test1 where

    g :: Eq a => a -> a -> (a, a)
    g x y = (x, y)

    findNames :: [String] -> String -> String -> [String]
    findNames [] _ _ = []
    findNames strs name name2 = (filter ((==) name) strs) ++ (filter ((==) name2) strs)

    numOfStrings :: [String] -> [String] -> Int
    numOfStrings [] _ = 0
    numOfStrings _ [] = 0
    numOfStrings (str:strs) (key:rest)
        | str == key = 1 + (numOfStrings strs rest)
        | otherwise = numOfStrings strs rest