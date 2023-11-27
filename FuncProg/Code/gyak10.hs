module Gyak10 where

-- INSTANCE:

    -- Komplex szamok: (Sajat peldany irasa)
    data Complex = C Double Double 

    -- Peldanyositjuk a Complex-re a Show-t:
    instance Show Complex where
        show (C a b) = show a ++ " + " ++ show b ++ "i"

    instance Num Complex where
        C a b + C c d = C (a + c) (b + d)
        C a b - C c d = C (a - c) (b - d)
        C a b * C c d = C (a * c - b * d) (a * d + b * c)
        abs (C a b) = C (sqrt $ a^2 + b^2) 0
        signum (C a b) = let l = sqrt $ a^2 + b^2 in C (a / l) (b / l)
        fromInteger n = C (fromInteger n) 0

-- MAYBE:

    -- Csunya fuggvenyeink: (Parcialis fuggvenyeink)
    -- head :: [a] -> a
    -- div :: Integral a => a -> a -> a

    data MaybeInt = NoInt | JustInt Int deriving Show

    head' :: [Int] -> MaybeInt
    head' [] = NoInt
    head' (x:_) = JustInt x

    data MaybeBool = NoBool | JustBool Bool deriving Show

    head'' :: [Bool] -> MaybeBool
    head'' [] = NoBool
    head'' (x:_) = JustBool x

    data Maybe' a = Nothing' | Just' a

    instance Show a => Show (Maybe' a) where
        show Nothing' = "Nothing'" 
        show (Just' x) = "Just' " ++ show x 

    safeHead :: [a] -> Maybe' a
    safeHead [] = Nothing'
    safeHead (x:_) = Just' x

    safeDiv :: Integral a => a -> a -> Maybe' a
    safeDiv _ 0 = Nothing'
    safeDiv a b = Just' $ div a b

    fromMaybe :: Maybe' a -> a -> a
    fromMaybe Nothing' a = a 
    fromMaybe (Just' a) _ = a

    h :: Integral a => [a] -> a -> Maybe' a
    h x n = case safeHead x of
        Nothing' -> Nothing'
        Just' a -> safeDiv a n

    data Either' a b = Left' a | Right' b deriving Show

    safeHeadEither :: [a] -> Either' String a
    safeHeadEither [] = Left' "safeHead: empty list!"
    safeHeadEither (x:_) = Right' x

    safeDivEither :: Integral a => a -> a -> Either' String a
    safeDivEither _ 0 = Left' "safeDiv: divide by 0"
    safeDivEither a b = Right' $ div a b

    h' :: Integral a => [a] -> a -> Either' String a
    h' x n = case safeHeadEither x of
        Left' s -> Left' s
        Right' a -> safeDivEither a n

-------------------------------------------
-- import Data.Ratio

    data Ratio a = R a a

    instance Show a => Show (Ratio a) where
        show (R a b) = show a ++ " / " ++ show b

    instance Integral a => Num (Ratio a) where
        -- HW