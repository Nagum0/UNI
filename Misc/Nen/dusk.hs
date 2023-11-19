module BlackBox where

attackPunch :: (Num a, Show a) => (String, a, a) -> String
attackPunch ("", _, _) = error "No name!"
attackPunch (name, health, power) = name ++ " was punched! Health: " ++ show (health - power)

main :: IO ()
main = do
    putStrLn (attackPunch ("Chrollo", 100, 20))