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
evaluatePostfix (Constant n (Just (Constant k (Just (Function f Nothing))))) = Just $ f n k

traversePostfix :: Postfix -> [Integer]
traversePostfix (Constant x Nothing) = [x]
traversePostfix (Constant x (Just rest)) = x : traversePostfix rest
traversePostfix (Function f Nothing) = []
traversePostfix (Function f (Just rest)) = traversePostfix rest