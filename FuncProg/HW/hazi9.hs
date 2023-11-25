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
    | otherwise = error "Helytelen adatok!"

-- 3. Idő megjelenítése; "it's show time!"
showTime :: Time -> String
showTime (T h m) = (show h) ++ ":" ++ (show m)

-- 4. Korábban, később
isEarlier :: Time -> Time -> Bool
isEarlier (T h1 m1) (T h2 m2) = (h1 < h2) || (h1 == h2 && m1 < m2)

-- 5. Két időpont között
isBetween :: Time -> Time -> Time -> Bool
isBetween (T h1 m1) (T h2 m2) (T h3 m3) = (h1 < h2 && h2 < h3 || h3 < h2 && h2 < h1) ||
                                          (h1 == h2 && h2 == h3 && m1 < m2 && m2 < m3 || m3 < m2 && m2 < m1)

-- 6. Amerikai idő típus
data Period = AM | PM deriving Eq
data USTime = USTime Period Int Int deriving Eq

-- 7. Amerikai idő létrehozása jól
ustime :: Period -> Int -> Int -> USTime
ustime p h m
    |    1 <= h && h <= 12
      && 0 <= m && m <= 59 = USTime p h m
    | otherwise = error "Helytelen adatok!"

-- 8. Amerikai idő megjelenítés
showUSTime :: USTime -> String
showUSTime (USTime AM h m) = "AM " ++ (show h) ++ ":" ++ (show m)
showUSTime (USTime PM h m) = "PM " ++ (show h) ++ ":" ++ (show m)

-- 9a. Értelmezhető idő

-- showTime (ustimeToTime (USTime AM 12 35))

ustimeToTime :: USTime -> Time
ustimeToTime (USTime AM 12 m) = t 0 m
ustimeToTime (USTime AM h m) = t h m
ustimeToTime (USTime PM 12 m) = t 12 m
ustimeToTime (USTime PM h m) = t (h + 12) m

-- 9b. Amerikainak is
timeToUSTime :: Time -> USTime
timeToUSTime (T h m)
    | h == 0 = USTime AM 12 m
    | h < 12 = USTime AM h m
    | h == 12 = USTime PM 12 m
    | otherwise = USTime PM (h - 12) m