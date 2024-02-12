name :: String
name = "Astolfo"

info :: (String, Bool)
info = ("Felix Argyle", False)

info' :: String -> Bool -> (String, Bool)
info' str bool = (str, bool)

factorial :: Integer -> Integer
factorial n = product [1..n]

pi' :: Double
pi' = 3.14

circ :: Double -> Double
circ r = 2 * pi' * r

find :: Int -> [Int] -> String
find x xs = if (elem x xs) then "The element was found." else "The element wasn't found."

find' :: Int -> [Int] -> String
find' x xs = if (elem x xs) then ("Element: [" ++ (show x) ++ "] was found.") else ("Element: [" ++ (show x) ++ "] wasn't found.")

test :: String -> (Int, Char)
test str = (read str :: (Int, Char))