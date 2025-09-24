module Hazi4 where

type Title = String

-- Első feladat (Mókás könyvszámolás)
o_O_count :: Num count => Title -> count
o_O_count [] = 0
o_O_count ('o':xs) = 1 + o_O_count xs
o_O_count ('O':xs) = 1 + o_O_count xs
o_O_count (_:xs) = o_O_count xs

-- Második feladat (Több is van?)
longerThan :: Integral count => [item] -> count -> Bool
longerThan [] count = count < 0
longerThan (_:xs) count = count == 0 || count < 0 || longerThan xs (count - 1)

-- Harmadik feladat (Mágia összefűzés)
merge :: [magic] -> [magic] -> [magic]
merge [] ys = ys
merge xs [] = xs
merge (x:xs) (y:ys) = x : y : merge xs ys

-- Negyedik feladat (Mágia összehasonlítás)
starter :: Eq magic => [magic] -> [magic] -> Bool
starter [] _ = True
starter _ [] = False
starter (x:xs) (y:ys) = x == y && starter xs ys

-- Ötödik feladat (Mágia sokszorozás)
endings :: [magic] -> [[magic]]
endings [] = [[]]
endings xs = xs : endings (tail xs)