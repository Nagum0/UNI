isSingleton :: [a] -> Bool
isSingleton [a] = True
isSingleton _ = False

single :: [a] -> Bool
single (_:[]) = True
single _ = False

atLeast3 :: [a] -> Bool
atLeast3 (a:b:c:xs) = True
atLeast3 _ = False