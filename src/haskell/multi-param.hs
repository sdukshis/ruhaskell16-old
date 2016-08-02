{-# LANGUAGE MultiParamTypeClasses #-}
{-# LANGUAGE FlexibleInstances #-}

import Prelude hiding ((==), (/=))
import qualified Prelude as P

class EqualityComparable a b where
    (==) :: a -> b -> Bool
    (==) :: b -> a -> Bool
    (/=) :: a -> b -> Bool

data Simpson = Bart | Homer | Lisa | Marge deriving Show

instance EqualityComparable Simpson String where
    (==) p s = show p P.== s
    (/=) p s = show p P./= s

instance EqualityComparable String Simpson where
    (==) p s = s == p
    (/=) p s = s /= p


main = if "Lisa" == Bart
        then putStrLn "Bart"
        else putStrLn "not Bart"
