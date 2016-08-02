{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE MultiParamTypeClasses #-}
--module Playground where

import Prelude hiding ((==), (/=))

class EqualityComparable a where
    (==) :: a -> a -> Bool
    (/=) :: a -> a -> Bool


same :: (EqualityComparable a) => a -> a -> Bool
same a b = a /= b

data Simpson = Bart | Lisa | Homer | Marge

instance EqualityComparable Simpson where
    (==) Bart Bart = True
    (==) Lisa Lisa = True
    (==) Homer Homer = True
    (==) Marge Marge = True
    (==) _ _ = False

main = if same Bart Bart
            then putStrLn "Equal"
            else putStrLn "Not equal"
