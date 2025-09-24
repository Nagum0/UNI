-- GUARDS
bmiTell :: Double -> [Char]
bmiTell bmi
    | bmi <= 18.5 = "Skinny..."
    | bmi <= 25.0 = "Nice!"
    | bmi <= 30 = "Fat..."
    | otherwise = "WTF!?"

giveGrade :: Int -> Char
giveGrade grade
    | grade == 5 = 'A'
    | grade == 4 = 'B'
    | grade == 3 = 'C'
    | grade == 2 = 'D'
    | grade == 1 = 'E'

checkGrade :: Char -> [Char]
checkGrade grade
    | grade == 'A' = "You passed!"
    | otherwise = "You failed..."

bmiCalc :: Double -> Double -> Double
bmiCalc weight height = weight / (height ^ 2)

myCompare :: (Ord a) => a -> a -> Ordering
a `myCompare` b
    | a > b = GT
    | a == b = EQ
    | otherwise = LT

-- WHERE
bmiTell' :: Double -> Double -> [Char]
bmiTell' weight height
    | bmi <= 18.5 = "Skinny..."
    | bmi <= 25.0 = "Nice!"
    | bmi <= 30 = "Fat..."
    | otherwise = "WTF!?"
    where bmi = weight / height^2

initials :: [Char] -> [Char] -> [Char]
initials first last = [f] ++ "." ++ [l] ++ "."
    where (f:_) = first
          (l:_) = last

calcBmis :: [(Double, Double)] -> [Double]
calcBmis xs = [bmi w h | (w, h) <- xs]
    where bmi weight height = weight / height^2

hatvanyok :: [(Int, Int)] -> [Int]
hatvanyok xs = [num x n | (x, n) <- xs]
    where num x n = x^n

{- 
    You have a list of integers, and you want to create a new list that contains 
    only the even numbers from the original list, but each even number should be squared. 
    Additionally, you want to exclude any even number that is a multiple of 4 from the new list.
-}
calcNums :: [Int] -> [Int]
calcNums xs = [square x | x <- xs, even x, not(x `mod` 4 == 0)]
    where square x = x^2

-- LET
calcBmis' :: [(Double, Double)] -> [Double]
calcBmis' xs = [bmi | (w, h) <- xs, let bmi = w / h^2]

{- 
    Problem: Write a Haskell function triangleArea that takes two arguments, base and height, 
    and calculates the area of a triangle using the formula (base * height) / 2.
-}
triangleArea :: Int -> Int -> Int
triangleArea base height =
    let area = (base * height)
        two = 2
    in area `div` two

-- Case Expressions
checkAge :: Int -> [Char]
checkAge age = "You are " ++ case age of 17 -> "underaged."
                                         42 -> "an adult."
                                         90 -> "fucking old lmao! :)"

checkAge' :: Int -> [Char]
checkAge' age
    | age < 18 = "underaged."
    | age >= 18 = "an adult."

checkAge'' :: Int -> [Char]
checkAge'' age
    | age < 18 = 
        let msg = "underaged."
        in "You are " ++ msg
    | age >= 18=
        let msg = "an adult."
        in "You are " ++ msg
    | otherwise =
        let msg = "WTF!!?"
        in msgs