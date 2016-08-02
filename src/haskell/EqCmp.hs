{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE MultiParamTypeClasses #-}

import Prelude hiding ((==), (/=))

class EqualityComparable a b where
    (==) :: a -> b -> Bool
    --(==) :: b -> a -> Bool
    (/=) :: a -> b -> Bool
    --(/=) :: b -> a -> Bool

data Simpson = Bart | Homer | Lisa | Marge  deriving Show

instance EqualityComparable Simpson String where
    (==) p s = (show p) == s


main = if Bart == "Bart"
            then putStrLn "Equal"
            else putStrLn "Not equal"

