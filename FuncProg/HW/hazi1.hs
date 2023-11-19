module Hazi1 where

-- 1.Kifejezesek
intExpr1 :: Int
intExpr1 = 1

intExpr2 :: Int
intExpr2 = 2

intExpr3 :: Int
intExpr3 = 3

charExpr1 :: Char
charExpr1 = 'c'

charExpr2 :: Char
charExpr2 = 'v'

charExpr3 :: Char
charExpr3 = 'b'

boolExpr1 :: Bool
boolExpr1 = True

boolExpr2 :: Bool
boolExpr2 = False

boolExpr3 :: Bool
boolExpr3 = 1 == 1

-- 2.+1, *3
inc :: Int -> Int
inc x = x + 1

triple :: Int -> Int
triple x = x * 3

-- 3.Tizenhárom
thirteen1 :: Int
thirteen1 = (triple (inc 0)) * (triple (inc 0)) + (inc 0) + (inc 0) + (inc 0) + (inc 0)

thirteen2 :: Int
thirteen2 = (triple (inc 0)) * (triple (inc 0)) + (inc 0) + (triple (inc 0))

thirteen3 :: Int
thirteen3 = (inc (inc (inc (inc 0)))) * (inc (inc (inc (inc 0)))) - (triple (inc 0))

-- 3.Osztási maradék
cmpRem5Rem7 :: Int -> Bool
cmpRem5Rem7 x = (mod x 5) > (mod x 7)

-- 4.Típusszignatúra
foo :: Int -> Bool -> Bool
foo x bool = x == 1 && bool == True

bar :: Bool -> Int -> Bool
bar bool x = (foo x bool)