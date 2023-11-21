module Test2 where

    import Data.Char (toUpper)

-- Problem 1: Doubling elements in a list:
-- Write a function that takes a list of integers and returns a new list where each element is doubled. -}

    doubleElems :: [Int] -> [Int]
    doubleElems [] = []
    doubleElems xs = map (\x -> x * 2) xs

-- Problem 2: Filtering odd numbers:
-- Create a function that filters out odd numbers from a list of integers.

    oddNums :: [Int] -> [Int]
    oddNums [] = []
    oddNums xs = filter (\x -> x `mod` 2 == 0) xs

-- Problem 3: Transforming strings:
-- Given a list of strings, convert each string to uppercase and return the modified list.

    toUpperCase :: [String] -> [String]
    toUpperCase [] = []
    toUpperCase strs = map (\str -> caps str) strs where
        caps [] = []
        caps str = map (\s -> toUpper s) str

-- Problem 4: Finding multiples of a number:
-- Write a function that takes a list of integers and a number and returns a 
-- list containing only the elements that are multiples of that number.

    findMultiples :: Integral a => [a] -> a -> [a]
    findMultiples [] _ = []
    findMultiples xs n = filter (\x -> x `mod` n == 0) xs

-- Problem 5: Manipulating a list of tuples:
-- Given a list of tuples where each tuple contains two integers, create a new list 
-- where each tuple is transformed by adding 10 to the first element and doubling the second element.

    manipTuples :: Num a => [(a, a)] -> [(a, a)]
    manipTuples [] = []
    manipTuples xs = map (\(x, y) -> (x + 10, y * 2)) xs

-- Problem 6: Manipulating lists of tuples:
-- Create a function that takes a list of tuples (String, Int) and returns a new list 
-- where the strings are concatenated with " is " and the integer doubled.

    randomAssFunction :: Num a => [(String, a)] -> [(String, a)]
    randomAssFunction [] = []
    randomAssFunction xs = map (\(str, n) -> (str ++ " is ", n * 2)) xs

    randomAssFunction2 :: (Num a, Show a) => [(String, a)] -> [String]
    randomAssFunction2 [] = []
    randomAssFunction2 xs = map (\(str, n) -> str ++ " " ++ (show n)) xs

-- Problem 7: Filtering nested lists:
-- Write a function that filters out all lists within a list of lists that contain only even numbers.

    xyz :: [[Int]] -> [[Int]]
    xyz [] = []
    xyz xss = filter (\xs -> isEven xs) xss where
        isEven [] = True
        isEven (y:ys)
            | y `mod` 2 == 0 = isEven ys
            | otherwise = False

-- Problem 8: Nested list transformation:
-- Given a list of lists of integers, return a new list where each element is a sum 
-- of the squares of the integers in the respective sublists.

    gerzson :: [[Int]] -> [Int]
    gerzson [] = []
    gerzson xss = map (\xs -> suM (sqrs xs)) xss where
        suM [] = 0
        suM (x:xs) = x + (suM xs)

        sqrs xs = map (\x -> x ^ 2) xs

-- Problem 9: Finding prime numbers:
-- Create a function that filters out all prime numbers from a list of integers.

    fotykos ::[Int] -> [Int]
    fotykos [] = []
    fotykos xs = filter (\x -> isPrime x) xs where
        isPrime n
            | n <= 1 = False
            | otherwise = all (\x -> n `mod` x /= 0) [2..floor (sqrt (fromIntegral n))]

-- Problem 10: Manipulating a list of strings:
-- Given a list of strings, remove all vowels (a, e, i, o, u) from each string and return the modified list.

    balogDorina :: [String] -> [String]
    balogDorina [] = []
    balogDorina strs = map (\str -> removeVowel str) strs where
        removeVowel [] = []
        removeVowel (s:str)
            | s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' = removeVowel str
            | otherwise = s : (removeVowel str)

-- Problem 11: Sublist sums:
-- Write a function that takes a list of integers and returns a list of tuples. 
-- Each tuple should contain a sublist and the sum of its elements.

    -- Easier version:
    balogMineta' :: [[Int]] -> [([Int], Int)]
    balogMineta' [] = []
    balogMineta' xss = map (\xs -> getSum xs) xss where
        getSum [] = ([], 0)
        getSum xs = (xs, suM xs) where
            suM [] = 0
            suM (x:xs) = x + (suM xs)

    -- Harder version:
    boberKurva :: [Int] -> [([Int], Int)]
    boberKurva [] = []
    boberKurva xs = balogMineta (permutations xs) where
        balogMineta :: [[Int]] -> [([Int], Int)]
        balogMineta [] = []
        balogMineta xss = map (\xs -> getSum xs) xss where
            getSum [] = ([], 0)
            getSum xs = (xs, suM xs) where
                suM [] = 0
                suM (x:xs) = x + (suM xs)

        permutations :: [a] -> [[a]]
        permutations [] = [[]]
        permutations (x:xs) = [zs | ys <- permutations xs, zs <- insertions x ys] where
            insertions :: a -> [a] -> [[a]]
            insertions a [] = [[a]]
            insertions a list@(x:xs) = (a : list) : [x : ys | ys <- insertions a xs]

-- Problem 12: Sum of List:

    sumList :: [Int] -> Int
    sumList = foldr (+) 0

-- Problem 13: Product of List:

    product' :: Num a => [a] -> a
    product' = foldr (*) 1

-- Problem 14: Length of List:

    length' :: [a] -> Int
    length' = foldr (\_ acc -> 1 + acc) 0

-- Problem 15: Reverse a List:

    reverseList :: [a] -> [a]
    reverseList = foldr (\x acc -> acc ++ [x]) []

-- Problem 16: Filter using foldr:

    filterList :: (a -> Bool) -> [a] -> [a]
    filterList f = foldr (\x acc -> if f x then [x] ++ acc else acc) []

    filterList' :: (a -> Bool) -> [a] -> [a]
    filterList' f = foldr (\x acc -> check (f x) x acc) [] where
        check condition x acc
            | condition = [x] ++ acc
            | otherwise = acc

-- Problem 17: Check if all elements satisfy a predicate:

    allSatisfy :: (a -> Bool) -> [a] -> Bool
    allSatisfy f = foldr (\x acc -> if not (f x) then False else acc) True

    allSatisfy' :: (a -> Bool) -> [a] -> Bool
    allSatisfy' f = foldr (\x acc -> satisfy (f x) acc) True where
        satisfy condition acc
            | condition = acc
            | otherwise = False

-- Problem 18: Existence check using foldr:
-- Define a function that checks if at least one element in the list satisfies a given predicate

    anySatisfy :: (a -> Bool) -> [a] -> Bool
    anySatisfy f = foldr (\x acc -> if (f x) then True else acc) False

    anySatisfy' :: (a -> Bool) -> [a] -> Bool
    anySatisfy' f = foldr (\x acc -> satisfy (f x) acc) False where
        satisfy condition acc
            | condition = True
            | otherwise = acc

-- Problem 19: Append two lists using foldr:

    appendLists :: [a] -> [a] -> [a]
    appendLists xs ys = foldr (:) ys xs

-- Problem 20: Remove duplicates from a list using foldr:

    removeDuplicates :: Eq a => [a] -> [a]
    removeDuplicates = foldr (\x acc -> if x `elem` acc then acc else x : acc) []

    removeDuplicates' :: Eq a => [a] -> [a]
    removeDuplicates' = foldr (\x acc -> isElem x acc) [] where
        isElem x acc
            | x `elem` acc = acc
            | otherwise = x : acc

-- Problem 21: Count occurrences of an element:

    countOccurrences :: Eq a => a -> [a] -> Int
    countOccurrences e = foldr (\x acc -> if x == e then acc + 1 else acc) 0

-- Problem 22: Make list of specific element:

    makeList :: Eq a => a -> Int -> [a]
    makeList a n = [a | x <- [1..n]]

-- Problem 23: Flatten a list of lists:

    flattenLists :: [[a]] -> [a]
    flattenLists = foldr (\xs acc -> xs ++ acc) []

-- Problem 24: Pythagorean Triples:
-- Write a function that generates all Pythagorean triples (a, b, c) where a, b, and c are integers and a^2 + b^2 = c^2.

    pythagoreanTriples :: Int -> [(Int, Int, Int)]
    pythagoreanTriples n = [(a, b, c) | a <- [1..n], b <- [1..n], c <- [1..n], (sqr c) == (sqr a) + (sqr b)] where
        sqr x = x * x

-- Problem 25: Duplicate Elements:

    duplicateElements :: [a] -> [a]
    duplicateElements [] = []
    duplicateElements (x:xs) = x : x : duplicateElements xs