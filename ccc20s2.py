'''
Luigi Quattrociocchi
Waterloo CCC 2020 J5/S2: Escape room
BFS Solution 11/15 points
'''

# using math sqrt for (fast factor)
import math
# fast input
import sys
m = int(sys.stdin.readline())
n = int(sys.stdin.readline())

# method for finding factors and then coordinates
# although more efficient methods exist (look into Sieve of Eratosthenes)
def findCoords(v):
	# initialize list of coordinate (factor pairs)
	f = []
	# check all numbers less than sqrt of value
	# any number beyond that will already be known
	for i in range(1, int(math.sqrt(v))+1):
		# is it a factor?
		if v%i == 0:
			# the reciprocal of i will be the corresponding factor
			j = int(v/i)

			# both factors are added at once
			# since multiplation is commutative

			# are factor pairs within bounds of grid
			if j <= m and i <= n:
				f.append((j, i))
			if i <= m and j <= n:
				f.append((i, j))

	# return array of coordinates
	return f


# initialize grid with input values
# grid is row by col (y, x)
grid = [[int(elm) for elm in sys.stdin.readline().split()] for _ in range(m)]

# boolean array, has current cell been visited
visited = [[False for _ in range(n)] for _ in range(m)]

# initially, we don't know if it's possible to escape
# since we are trying to prove that it is possible, we say False
# if no valid path is found this boolean will not be changed
possible = False

# since grid is in terms of rows and cols,
# tuples will be in terms (y, x).
# start at position (1, 1) as specified
start = (1, 1)

# as stated by the question,
# the end or final position will be (m, n)
end = (m, n)

# queue will only contain the root note to begin
# other ways of doing queues in python exist
# for example: from collections import deque
q = [start]

# while length of queue > 0
# AKA "while q (exists)"
while q:
	# pop will remove the first value from queue (since BFS is FiFo)
	# current cell becomes the popped value
	cur = q.pop(0)
	y, x = cur[0]-1, cur[1]-1

	# has the current cell been visited yet?
	if visited[y][x]:
		# if so, skip the check for this cell
		continue

	# mark current cell as visited
	visited[y][x] = True

	# if current cell is the final spot
	if cur == end:
		# path is possible
		possible = True
		# break out of loop
		break

	# call method on current value, find all possible moves
	# add all possible moves (coords to jump to) to queue
	q.extend(findCoords(grid[y][x]))

# output final answer
print("yes" if possible else "no")
