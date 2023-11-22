module Hazi9 where

import Control.Exception
import System.IO.Unsafe

-- 1. Óra típus
data Time = T Int Int deriving Eq

-- 2. Okos konstruktor -- Hiba a modulokkal!!!
t :: Int -> Int -> Time
t hour min
    |    0 <= hour && hour <= 23
      && 0 <= min && min <= 59 = T hour min
    | otherwise = error "Nem helyes adatok!"

-- 3. Idő megjelenítése; "it's show time!"
showTime :: Time -> String
showTime (T h m) = (show h) ++ ":" ++ (show m)

-- 4. Korábban, később
isEarlier :: Time -> Time -> Bool
isEarlier (T h1 m1) (T h2 m2)
    | h1 < h2 = True
    | h1 == h2 && m1 < m2 = True
    | otherwise = False

-- 5. Két időpont között
isBetween :: Time -> Time -> Time -> Bool
isBetween (T h1 m1) (T h2 m2) (T h3 m3)
    | h1 < h2 && h2 < h3 || h3 < h2 && h2 < h1 = True
    | h1 == h2 && h2 == h3 && 
      m1 < m2 && m2 < m3 || m3 < m2 && m2 < m1 = True
    | otherwise = False

-- 6. Amerikai idő típus
