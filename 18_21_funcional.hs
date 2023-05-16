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
	|(tamString x) < y = '>':(pushRight x (y - 1))
	|otherwise = x

--21
(&-) :: Int -> Int -> Int
(&-) x y = x - 2*y
infix 8 &-

--(a)
	--Para a função 10 &- 3 &- 2:

	--infixl retornou 0, pois ele vai fazer da esquerda para a direita:
	--	(10 &- 3) &- 2 = (10 - 2*3) &- 2 = 4 &- 2 = 4 - 2*2 = 0

	--infixr retornou 12, pois ele vai fazer da direita para a esquerda:
	--	10 &- (3 &- 2) = 10 &- (3-2*2) = 10 &- (-1) = 10 -2*(-1) = 10 + 2 = 12

	--infix retornou ERRO, pois como o operador não tem uma direção a seguir, fica ambíguo se
	--deve ser pela direita ou esquerda quando usado duas ou mais vezes sem a utilização de 		parênteses

--(b)

	--infix 6/8 retornou ERRO, pois como o operador não tem uma direção a seguir,
	--fica ambíguo se deve ser pela direita ou esquerda quando usado duas ou mais
	--vezes sem a utilização de parênteses, exemplo: 2 &- 3 &- 6 &- 9 (ambiguidade)
	
