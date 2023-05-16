--18	
charToNum::Char->Int
charToNum x
	|(ord x) <= 57 || (ord x) >= 48 = ord x - 48
	|otherwise = -1
	
--19
duplicate::String->Int->String
duplicate _ 0 = []
duplicate x y = x ++ (duplicate x (y - 1)) 

--20

tamString::String->Int
tamString [] = 0
tamString (_:b) = 1 + tamString b

pushRight::String->Int->String
pushRight x y
	|
	|y < tamString x = x
	|
 
 
