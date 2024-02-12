module FastLucas where

import Data.Ratio ((%), numerator, denominator)

-- 1. Saját típus
data Lucas = L Rational Rational deriving Eq

-- 2. Példányok a típusra
instance Show Lucas where
    show (L a b) = show a ++ " + " ++ show b ++ " * gyok 5"

instance Num Lucas where
    (L a b) + (L c d) = L (a + c) (b + d)
    (L a b) - (L c d) = L (a - c) (b - d)
    (L a1 b1) * (L a2 b2) = L (a1 * a2 + b1 * b2 * 5) (a1 * b2 + b1 * a2)
    
    abs (L a b)
        | (a + b * (toRational $ sqrt 5)) > 0 = L a b
        | otherwise = L ((-1) * a) ((-1) * b)

    signum (L a b) = L (signum $ a + b * (toRational $ sqrt 5)) 0
    fromInteger n = L ((fromInteger n) % 1) 0

-- 3. Aranymetszés / golden ratio
phi :: Lucas
phi = L (1 % 2) (1 % 2)

-- 4. Lucas-sorozat n. eleme
lucas :: (Integral a, Num b) => a -> b
lucas n = fromInteger $ numerator $ f (phi^n + (1 - phi)^n) where
    f :: Lucas -> Rational
    f (L x _) = x

-- 5. Lucas-sorozat felhasználása
isNotPrime :: Integral a => a -> Bool
isNotPrime n = (lucas n - 1) `mod` n /= 0