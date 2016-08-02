class Stringable a where
    toString :: a -> String

data Person = Person {firstname :: String, lastname :: String}

instance Stringable Person where
    toString p = take 1 (firstname p) ++ ". " ++ lastname p

bold :: (Stringable a) => a -> String
bold a = "<b>" ++ toString a ++ "</b>"

main = putStrLn $ bold $ Person "John" "Smith"
