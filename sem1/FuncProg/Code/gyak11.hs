module Gyak11 where

-- Induktiv (rekurziv) tipusok!!!

-- Irunk sajat listat:
---------------------------------------------------------------------------------------------------
    data List a = Nil | Cons a (List a)

    instance Show a => Show (List a) where
        show Nil = "[]"
        show (Cons x xs) = '[' : show x ++ showHepler xs where
            showHepler Nil = "]"
            showHepler (Cons y ys) = ',' : show y ++ showHepler ys

    map' :: (a -> b) -> List a -> List b
    map' _ Nil = Nil
    map' f (Cons x xs) = f x `Cons` map' f xs

    instance Foldable List where
        foldr _ acc Nil = acc   
        foldr f acc (x `Cons` xs) = f x $ foldr f acc xs

-- 2 kulonbozo tipust tarolo lista:
---------------------------------------------------------------------------------------------------
    data AlernatingList a b = ANil | ACons a (AlernatingList b a)

    instance (Show a, Show b) => Show (AlernatingList a b) where
        show ANil = "[]"
        show (ACons x xs) = '[' : show x ++ showHepler xs where
            showHepler ANil = "]"
            showHepler (ACons y ANil) = ',' : show y ++ "]"
            showHepler (ACons y (ACons z ys)) = ',' : show y ++ ',' : show z ++ showHepler ys

    take' :: Integral a => a -> AlernatingList b c -> AlernatingList b c
    take' n _
        | n <= 0 = ANil
    take' _ ANil = ANil
    take' n (ACons x xs) = x `ACons` take' (n - 1) xs

    drop' :: Integral a => a -> AlernatingList b c -> Either (AlernatingList b c) (AlernatingList c b)
    drop' n xs
        | n <= 0 = Left xs
    drop' _ ANil = Left ANil
    drop' _ (ACons _ xs) = Right ANil
    drop' n (ACons x l@(ACons y xs))
        | n == 1 = Right l
        | otherwise = drop' (n - 2) xs

-- Interpreter
---------------------------------------------------------------------------------------------------
    data Expr = BoolLit Bool 
              | IntLit Integer 
              | Add Expr Expr 
              | Equ Expr Expr 
    
    -- (2 + 3)
    -- Add (IntLit 2) (IntLit 3)

    evalExpr :: Expr -> Maybe (Either Bool Integer)
    evalExpr (BoolLit b) = Just $ Left b
    evalExpr (IntLit n) = Just $ Right n
    evalExpr (Add n k) = case (evalExpr n, evalExpr k) of
        (Just (Right a), Just (Right b)) -> Just $ Right $ a + b
        _ -> Nothing 
    evalExpr (Equ n k) = case (evalExpr n, evalExpr k) of
        (Just (Right a), Just (Right b)) -> Just $ Left $ a == b
        (Just (Left a), Just (Left b)) -> Just $ Left $ a == b
        _ -> Nothing