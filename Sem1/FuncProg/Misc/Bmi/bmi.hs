bmiTell :: Double -> [Char]
bmiTell bmi
    | bmi <= 18.5 = "Skinny!"
    | bmi <= 25.0 = "Normal..."
    | bmi <= 30.0 = "Fat!"
    | otherwise = "WTF!?"

bmiCalc :: Double -> Double -> Double
bmiCalc height weight = weight / height^2