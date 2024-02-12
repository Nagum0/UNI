module EA4 where

-- Rekurzio
fact :: Integer -> Integer
fact n = 

factH :: Integer -> Integer -> Integer
factH n m
    | n == m =  
    | n >  m = m * factH n (m + 1)
    | n <  m = 