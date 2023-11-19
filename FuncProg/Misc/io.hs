inc :: Int -> Int
inc x = x + 1

main :: IO ()
main = do
    putStrLn "n: "
    x <- getLine
    case reads x of
        [(n, "")] -> putStrLn $ show (inc n)
        _         -> putStrLn "Invalid input!"

