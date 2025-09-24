module RPN where

-- 1. Lengyel (Postfix) forma jelölése
---------------------------------------------------------------------------------------------------
data Postfix = Constant Integer  (Maybe Postfix) 
             | Function (Integer -> Integer -> Integer) (Maybe Postfix)

-- 2. Lengyel forma kiértékelése
---------------------------------------------------------------------------------------------------
evaluatePostfix :: Postfix -> Maybe Integer
evaluatePostfix (Constant n Nothing) = Just n
evaluatePostfix (Function _ Nothing) = Nothing
evaluatePostfix (Function _ (Just rest)) = Nothing
evaluatePostfix (Constant n (Just rest)) = acc (n:[]) rest where
    acc [x] (Function _ _) = Nothing
    acc [x] (Constant _ Nothing) = Nothing
    acc [x] (Constant n (Just rest)) = acc (n:[x]) rest
    acc (x:y:ys) (Constant _ Nothing) = Nothing
    acc (x:y:ys) (Constant n (Just rest)) = acc (n:x:y:ys) rest
    acc (x:y:ys) (Function f (Just rest)) = acc ((y `f` x):ys) rest
    acc [x,y] (Function f Nothing) = Just $ y `f` x
    acc (x:y:ys) (Function _ _) = Nothing