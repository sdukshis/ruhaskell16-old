{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE MultiParamTypeClasses #-}
{-# LANGUAGE FunctionalDependencies #-}

class Callable f a b | f a -> b where
    call :: f -> a -> b

data Person = Homer | Bart deriving Show

instance Callable Person String String where
    call p s = show p ++ " " ++ s 

main = putStrLn (call Bart "world")

