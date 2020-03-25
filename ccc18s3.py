def getPossibleMoves(x, y, s):
	moves = []
	if grid[x][y] == "S" or grid[x][y] == ".":
		if grid[x][y] == "." and dots[(x, y)] == -1:
			dots[(x, y)] = s
		if x > 0 and grid[x-1][y] != "W" and not visited[x-1][y]:
			moves.append((s+1, x-1, y))
		if x < n-1 and grid[x+1][y] != "W" and not visited[x+1][y]:
			moves.append((s+1, x+1, y))
		if y > 0 and grid[x][y-1] != "W" and not visited[x][y-1]:
			moves.append((s+1, x, y-1))
		if y < m-1 and grid[x][y+1] != "W" and not visited[x][y+1]:
			moves.append((s+1, x, y+1))
	
	elif grid[x][y] == "U" or grid[x][y] == "D" or grid[x][y] == "L" or grid[x][y] == "R":
		while grid[x][y] == "U" or grid[x][y] == "D" or grid[x][y] == "L" or grid[x][y] == "R":

			# out of bounds or infinite loop
			if x <= 0 or x >= n-1 or y <= 0 or y >= m-1 or (grid[x][y] == "D" and grid[x+1][y] == "U") or (grid[x][y] == "R" and grid[x][y+1] == "L"):
				break

			# here I realize that x and y are flipped
			# but I'm not going back to change it lol
			elif grid[x][y] == "U":
				x -= 1
			elif grid[x][y] == "D":
				x += 1
			elif grid[x][y] == "L":
				y -= 1
			elif grid[x][y] == "R":
				y += 1
		
		if grid[x][y] == ".":
			moves.append((s, x, y))
		
	return moves


import sys
import heapq
n, m = map(int, sys.stdin.readline().split())

visited = [[False for i in range(m)] for j in range(n)]
grid = [[None for i in range(m)] for j in range(n)]

dots = {}
cameras = []
for i in range(n):
	line = sys.stdin.readline()
	for j in range(m):
		grid[i][j] = line[j]
		if grid[i][j] == ".":
			dots[(i, j)] = -1
		elif grid[i][j] == "C":
			cameras.append((i, j))
		elif grid[i][j] == "S":
			start = (0, i, j)

for camera in cameras:
	i = camera[0]
	j = camera[1]
	for c in range(i, n):
		if grid[c][j] == "." or grid[c][j] == "S":
			grid[c][j] = "T"
		elif grid[c][j] == "W":
			break
	for c in range(i, -1, -1):
		if grid[c][j] == "." or grid[c][j] == "S":
			grid[c][j] = "T"
		elif grid[c][j] == "W":
			break
	for r in range(j, m):
		if grid[i][r] == "." or grid[i][r] == "S":
			grid[i][r] = "T"
		elif grid[i][r] == "W":
			break
	for r in range(j, -1, -1):
		if grid[i][r] == "." or grid[i][r] == "S":
			grid[i][r] = "T"
		elif grid[i][r] == "W":
			break

for i in range(n):
	for j in range(m):
		if grid[i][j] == "T":
			grid[i][j] = "W"


if grid[start[1]][start[2]] == "S":
	q = []
	heapq.heappush(q, start)
	while q:
		cur = heapq.heappop(q)
		if visited[cur[1]][cur[2]]: continue
		
		visited[cur[1]][cur[2]] = True

		moves = getPossibleMoves(cur[1], cur[2], cur[0])
		for move in moves:
			heapq.heappush(q, move)

for item in dots.items():
	print(item[1])
