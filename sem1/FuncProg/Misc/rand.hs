createList :: Int -> Int -> [Int]
createList start end = [x | x <- [start..end]]

replicate' :: Int -> a -> [a]
replicate' 0 _ = []
replicate' n x = x : replicate' (n - 1) x