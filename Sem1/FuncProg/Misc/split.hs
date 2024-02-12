module Split where

getFront :: Int -> [a] -> [a]
getFront _ [] = []
getFront n _ 
    | n <= 0 = []
getFront n (x:xs) = x : getFront (n - 1) xs

getBack :: Int -> [a] -> [a]
getBack n xs 
    | n <= 0 = xs
getBack n [] = []
getBack n (x:xs) = getBack (n - 1) xs

split :: Int -> [a] -> ([a], [a])
split n xs = ((getFront n xs), (getBack n xs))

quickSort :: Integral a => [a] -> [a]
quickSort [] = []
quickSort (x:xs) = quickSort [y | y <- xs, y < x] ++ x : quickSort [y | y <- xs, y >= x]  

-- quickSort [6, 17, 8, 4, 9, 18]
--
--   quickSort [4] ++ 6 : quickSort [17,8,9,18]
--     quickSort [] ++ 4 : quickSort [] || quickSort [8,9] ++ 17 : quickSort [18]
--       [4] || quickSort [] ++ 8 : quickSort [9] || quickSort [] ++ 18 : quickSort []
--         [4] || quickSort [] ++ 9 : quickSort [] || [18]
--         [4] || [9] || [18]
--       [4] || [8,9] || [18]
--     [4] || [8,9,17,18]
--   [4,6,8,9,17,18]