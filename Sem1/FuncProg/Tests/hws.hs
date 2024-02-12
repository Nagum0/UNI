module HWS where

-- 1.HW -------------------------------------------------------------

    -- 1. Kifejezések charExpr1, charExpr2, charExpr3
    intExpr1 :: Int
    intExpr1 = 1

    intExpr2 :: Int
    intExpr2 = 2

    intExpr3 :: Int
    intExpr3 = 3

    charExpr1 :: Char
    charExpr1 = 'c'

    charExpr2 :: Char
    charExpr2 = 'a'

    charExpr3 :: Char
    charExpr3 = 'r'

    -- 2. +1, *3
    inc :: Int -> Int
    inc x = x + 1

    triple :: Int -> Int
    triple x = x * 3

    -- 3. Tizenhárom
    thirteen1 :: Int
    thirteen1 = inc $ inc $ inc $ inc $ inc $ inc $ inc $ inc $ inc $ inc $ inc $ inc $ inc 0

    thirteen2 :: Int
    thirteen2 = inc $ inc $ inc $ inc $ triple $ triple $ inc 0

    -- 3. Osztási maradék
    cmpRem5Rem7 :: Int -> Bool
    cmpRem5Rem7 x = if (x `mod` 5) > (x `mod` 7) then True else False

    cmpRem5Rem7' :: Int -> Bool
    cmpRem5Rem7' x = (x `mod` 5) > (x `mod` 7)

    -- 4. Típusszignatúra
    foo :: Int -> Bool -> Bool
    foo x b = (x > 2) == b

    bar :: Bool -> Int -> Bool
    bar b x = foo x b

-- 2.HW -------------------------------------------------------------

    