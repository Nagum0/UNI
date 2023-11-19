inc :: Int -> Int
inc x = x + 1

doubleMe :: Int -> Int
doubleMe x = x + x

doubleSmallNumber :: Int -> Int
doubleSmallNumber x = if x < 100 then x * 2 else x

doubleSmallNumber' :: Int -> Int
doubleSmallNumber' x = (if x > 100 then x else x*2) + 1

astolfo = "Astolfo"

-- Lists
boomBangs xs = [if x < 10 then "BOOM" else "BANG" | x <- xs, odd x]

foo :: Int -> Bool -> Bool
foo x bool = (x == 1) == bool

tri = [ (a, b, c) | a <- [1..10], b <- [1..10], c <- [1..10], a^2 + b^2 == c^2, a+b+c == 24 ]