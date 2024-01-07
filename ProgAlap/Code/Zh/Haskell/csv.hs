module CSV where

-- CSV: Column names; Row data
data CSV = CSV [String] [[String]] deriving Show

parseCSV :: String -> CSV
parseCSV str = CSV (head xs) (tail xs) where
    xs = map (\line -> split line) $ lines str where
        split str' = foldr (\c acc -> if c == ',' then [] : acc else (c : head acc) : tail acc) [[]] str'   

getCSVColumns :: CSV -> [[String]]
getCSVColumns (CSV header rows) = zipWith (\i _ -> map (!! i) rows) [0..] header       

main :: IO()
main = do
    putStrLn "File:"
    userInput <- getLine
    contents <- readFile userInput 
    let csv = parseCSV contents
    putStrLn $ show csv 