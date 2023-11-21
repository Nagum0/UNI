module CE where

    type Output = Integer -- The amount of output.
    type Limit = Integer -- The amount of CE a body can take.
    data CursedEnergy = CT | RCT | NaN deriving (Show, Eq)

    -- Check the type of the cursed energy.
    checkType :: Output -> CursedEnergy
    checkType 0 = NaN
    checkType x = if x < 0 then CT else RCT