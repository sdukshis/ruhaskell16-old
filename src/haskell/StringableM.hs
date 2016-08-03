module StringableM where

-- Type class
class Stringable a where
    foo :: a -> String
    toString :: a -> String

data Person = Person {firstname :: String, lastname :: String}

-- Instance
instance Stringable Person where
    foo p = "Hello"
    toString p = take 1 (firstname p) ++ ". " ++ lastname p
 
-- Algorithm
bold :: (Stringable a) => a -> String
bold a = "<b>" ++ toString a ++ "</b>"
