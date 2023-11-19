module Hazi3 where

import Data.List (group)

type Room = String
type Air = Int
type Fire = Integer
type MagicLevel = Int

-- Első feladat (A mester)
find :: [Room] -> [Room]
find rooms = [room | room <- rooms, room == "2.620"]

-- Második feladat (Első próba)
add :: (Integral magic1, Integral magic2, Num magic3) => magic1 -> magic2 -> magic3
add x y = (fromIntegral x) + (fromIntegral y)

-- Harmadik feladat (Második próba)
{-  Ennek a fuggvenynek az erteke egy lista, amiben azok a szamok lesznek, amelyek kisebbek vagy egyelloek a
    szam negyzetgyokevel es a szam tenyezoi. Ha nincs ilyen szam akkor ures listat kapunk. -}
getFactorsUnderSqrt :: Int -> [Int]
getFactorsUnderSqrt n = [x | x <- [2..(floor(sqrt(fromIntegral n)))], n `mod` x == 0]

isPrime :: Int -> Bool
isPrime n = null(getFactorsUnderSqrt n) && n >= 2

primeMagic :: MagicLevel -> MagicLevel -> [MagicLevel]
primeMagic start end = [x | x <- [start..end], isPrime x]

-- Negyedik feladat (Harmadik próba)
compress :: Eq magic => [magic] -> [(magic, MagicLevel)]
compress magics = [(head i, length i) | i <- group magics]

-- Ötödik feladat (Negyedik próbatétel)
decompress :: [(magic, MagicLevel)] -> [magic]
decompress magics = [m | (m, ml) <- magics, _ <- [1..ml]] -- Itt a `_ <- [1..ml]` miatt a loop ml-ig fut at a tuplen.