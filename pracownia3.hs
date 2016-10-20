-- Dominik Szczepañski pracownia nr 3 
-- dla testowego przyk³adu generuje rozwi¹zanie w rozs¹dnym czasie w GHCi

import Monad
import System.Environment
import Data.List
import Data.Char

type Pair = (Int,Int)
type Pairs = (Pair,Pair)
type Graph = ([Pair], [Pairs])

-- funkcje pomocniczne

split sep = takeWhile (not . null) . unfoldr (Just . span (/= sep) . dropWhile (== sep))

cleanPairs [] = []
cleanPairs (x:xs) = if x == ' ' then cleanPairs xs else (x : cleanPairs xs)

flatPairs :: [Pairs] -> [Pair]
flatPairs [] = []
flatPairs (((x1,x2),(y1,y2)):xs) = (x1,x2) : (y1,y2) : flatPairs xs

flatPairs2 :: [[Pair]] -> [Pair]
flatPairs2 [] = []
flatPairs2 (x:xs) = union x $ flatPairs2 xs

parseInt x = read $ head $ split '.' x :: Int
parsePairs pairs = read $ head $ split '.' pairs :: [Pairs]


main = do
        [s] <- getArgs
        g   <-	 readFile s
	v   <- solution g
	print v


solution g = parse $ words $ cleanPairs g

parse([m,n,pairs]) = findsol (parseInt m) (parseInt n) (flatPairs $ parsePairs pairs)

findsol m n pairs = return (findsolution m n pairs pairs)

-- ca³y 'silnik' programu
findsolution m n pairs [] = return []
findsolution m n pairs (x:y:xs) = do
							z <- findsolution m n pairs xs
							let gr = (board m n, allMoves m n (filter (\v -> v /= x && v /= y) (union pairs (flatPairs2 z))  ))
							l <- Main.bfs gr x y
							return (l:z)

-- generuje mo¿liwe ruchy w postaci krawêdzi grafu
allMoves :: Int -> Int -> [Pair] -> [Pairs]
allMoves m n inpairs = [((x1,y1),(x2,y2)) | x1<-[1..m], y1<-[1..n], 
						x2<-[x1-1..x1+1], 
						y2<-[y1-1..y1+1], 
						not ((x2,y2) `elem` inpairs), 
						not (x2 == 0 || y2 == 0), 
						not (x2 == m + 1 || y2 == n + 1),
						not (x2 == x1 && y2 == y1), 
						not (x2 /= x1 && y2 /= y1) ]
						
-- generuje wierzcho³ki grafu
board :: Int -> Int -> [Pair]
board m n = [(x,y) | x <- [1..m], y <- [1..n]]

-- heurystyka odleg³oœci do celu
cmp (z1,z2) (x1,x2) (y1,y2) 
		| (abs (x1-z1) + abs(x2-z2)) < (abs (y1-z1) + abs(y2-z2)) = LT
		| (abs (x1-z1) + abs(x2-z2)) > (abs (y1-z1) + abs(y2-z2)) = GT
		| otherwise = EQ

-- pierwsza, najwa¿niejsza heurystyka - po iloœci mo¿liwych ruchów, wiêkszy priorytet maj¹ te wierzcho³ki o mniejszej swobodzie
cmpchoices gr (z1,z2) (x1,x2) (y1,y2)
		| (length (find_next (x1,x2) gr) < length (find_next (y1,y2) gr)) = LT
		| (length (find_next (x1,x2) gr) > length (find_next (y1,y2) gr)) = GT
		| otherwise = cmp (z1,z2) (x1,x2) (y1,y2)


sortbychoices :: Graph -> Pair -> [Pair] -> [Pair]
sortbychoices gr dest [] = []
sortbychoices gr dest list = sortBy (cmpchoices gr dest) list

find_next_by_choice :: Pair -> Graph -> Pair -> [Pair]
find_next_by_choice k gr dest = sortbychoices gr dest (map snd $ filter ((==k) . fst) (snd gr)) 
  
find_next :: Pair -> Graph -> [Pair]
find_next k gr = map snd $ filter ((==k) . fst) (snd gr)

-- przeszukiwanie wszerz grafu
bfs :: Graph -> Pair -> Pair -> [[Pair]]
bfs gr p0 p1 = bfs_aux gr p1 [ x : [p0] | x <- find_next p0 gr] 
     
bfs_aux _ _ [] = fail "no path"
bfs_aux gr p1 (path:queue)
        | p0 == p1 =  (return (reverse path)) `mplus` (bfs_aux gr p1 queue)
        | otherwise = bfs_aux gr p1 ( queue ++
                                       [ x : path | x <- find_next_by_choice p0 gr p1, not (x `elem` path)])
									   where p0 = head path