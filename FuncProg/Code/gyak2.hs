g :: Int -> Bool -> Int
g x y = (x * 3) + 2

-- Mintaillesztes
neg :: Bool -> Bool
neg True = False
neg False = True

(&&&) :: Bool -> Bool -> Bool
True &&& True = True
_ &&& _ = False -- Default case

(&&&&) :: Bool -> Bool -> Bool
False &&&& _ = False
True &&&& a = a

-- Rendezett par - Tuple
tup :: (Int, Bool)
tup = (1, False)

inc :: Int -> Char -> (Int, Char)
inc x c = (,) x c

inc' :: (Int, Int) -> (Int, Int)
inc' x = ((fst x + 1), (snd x + 1))

f :: (Int, Int) -> (Int, Int)
f (x, y) = (x + 1, y + 1)

isZero :: Integer -> Bool
isZero 0 = True
isZero _ = False

isOrigo :: (Integer, Integer) -> Bool
isOrigo (0, 0) = True
isOrigo _ = False