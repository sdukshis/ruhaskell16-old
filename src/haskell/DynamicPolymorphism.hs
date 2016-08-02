class Named a where
    name :: a -> String


data Simpson = Bart | Lisa | Homer | Marge deriving Show

data Griffin = Peter | Lois | Meg | Chris | Stewie | Brian deriving Show

instance Named Simpson where
    name a = show a ++ " Simpson"

instance  Named Griffin where
    name a = show a ++ " Griffin"

greeting :: (Named a) => a -> String
greeting a = "Hello, " ++ name a

main = do
    putStrLn $ greeting Bart
    putStrLn $ greeting Peter
