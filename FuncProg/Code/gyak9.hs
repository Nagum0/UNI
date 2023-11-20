module Gyak9 where

-- foldl

    reverse' :: [a] -> [a]
    reverse' = reverseAcc [] where
        reverseAcc acc [] = acc
        reverseAcc acc (x:xs) = reverseAcc (x : acc) xs
    
    -- Ez itt maga a `foldl` fuggveny!
    generalL :: (b -> a -> b) -> b -> [a] -> b
    generalL _ acc [] = acc
    generalL f acc (x:xs) = generalL f (f acc x) xs 

    reverse'' :: [a] -> [a]
    reverse'' = foldr (\x acc -> acc ++ [x]) [] 

    reverse''' :: [a] -> [a]
    reverse''' = foldl (\acc x -> x : acc) []

-- Tipusszinonimak:

    type Fire = Int
    type Air = Integer

    -- A tipusszinonima nem tud semmivel se tobbet, mint tipus ami megvan adva neki.
    -- type String = [Char]

    f :: Air -> Fire
    f 0 = 2
    f 1 = 0
    f x = fromIntegral x + 2

    type Predicate a = a -> Bool

    filter' :: Predicate a -> [a] -> [a]
    filter' _ [] = []
    filter' f (x:xs)
        | f x = x : filter' f xs
        | otherwise = filter' f xs

-- Sajat tipusok:

    data {- Kell egy nev, ami nagybetuvel kezdodik. -} Day = 
         {- Meg kell adni a tipusom ertekeit, konstruktorait. -}
         {- Konstruktorok nevei nagybetuvel kezdodenek. -}
        Mon | Tue | Wed | Thu | Fri | Sat | Sun
         {- Meg lehet kerni a forditot kulonbozo dolgokra. (pl.: Megjelenithetoseg) -}
        deriving (Show, Enum)

         {- 7 dologra lehet megkerni a forditot: 
            - Show
            - Read
            - Eq
            - Ord
            - Bounded (Megmondja az adatszerkezet min, max-jat.)
            - Enum
            - Ix ( (!!) :: Ix i => [a] -> i -> a )
         -}
        
    nextDay :: Day -> Day
    nextDay Sun = Mon
    nextDay d = succ d

    -- data Bool = True | False
    -- data (a,b) = (,) a b

    -- Color pelda:
    type Red = Int
    type Green = Int
    type Blue = Int
    data Color = RGB Red Green Blue deriving Show

    modifyColor :: Color -> Red -> Green -> Blue -> Color
    modifyColor color@(RGB r g b) r' g' b'
        |    0 <= red && red <= 255 
          && 0 <= green && green <= 255 
          && 0 <= blue && blue <= 255 = RGB red green blue
        | otherwise = color where
            red = r + r'
            green = g + g'
            blue = b + b'

    -- "Okos" konstruktorok:
    rgb :: Red -> Green -> Blue -> Color
    rgb r g b
        |    0 <= r && r <= 255 
          && 0 <= g && g <= 255 
          && 0 <= b && b <= 255 = RGB r g b
        | otherwise = error "Valamelyik szintartomanyon kivul van."

    -- Fruit pelda:
    data Fruit = Apple | Pear | Peach deriving Show
    data FruitBatch = FruitBatch Fruit Integer deriving Show

    sumFruit :: [FruitBatch] -> Integer
    sumFruit [] = 0
    sumFruit ((FruitBatch _ n):xs) = n + sumFruit xs

    addFruit :: FruitBatch -> (FruitBatch, FruitBatch, FruitBatch) -> (FruitBatch, FruitBatch, FruitBatch)
    addFruit (FruitBatch Apple n) (FruitBatch Apple m, p, pe) = (FruitBatch Apple (n + m), p, pe)
    addFruit (FruitBatch Pear n)  (a, FruitBatch Pear m, pe) = (a, FruitBatch Pear (n + m), pe)
    addFruit (FruitBatch Peach n) (a, p, FruitBatch Peach pe) = (a, p FruitBatch (n + m))

    sumDifferentFruit :: [FruitBatch] -> (FruitBatch, FruitBatch, FruitBatch)
    sumDifferentFruit [] = (FruitBatch Apple 0, FruitBatch Pear 0, FruitBatch Peach 0)
    sumDifferentFruit (x:xs) = addFruit x (sumDifferentFruit xs)