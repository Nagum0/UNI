module Lex where

import Data.List (words)

data Token = Command String | Value String deriving Show

lexer :: String -> [Token]
lexer [] = []
lexer str = map (\s -> getToken s) $ words str where
    getToken "echo" = Command "echo" 
    getToken s' = Value s'

eval :: [Token] -> IO()
eval ((Command cmd):(Value val):[]) = case cmd of "echo" -> print val
                                                  _ -> error "Unknown command"