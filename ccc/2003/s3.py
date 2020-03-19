import sys
visited = "V"
tiles = int(sys.stdin.readline())
r = int(sys.stdin.readline()) # rows: Y
c = int(sys.stdin.readline()) # cols: X

grid = [(" ".join(sys.stdin.readline())).split() for j in range(r)]
rooms = []

def showMat(mat):
    for row in mat:
        for elm in row:
            print(elm, end=" ")
        print("")
    print("")

def getPossibleMoves(x, y):
    moves = []
    if x != 0 and grid[x-1][y] == ".":
        moves.append((x-1, y))
    if x != r-1 and grid[x+1][y] == ".":
        moves.append((x+1, y))
    if y != 0 and grid[x][y-1] == ".":
        moves.append((x, y-1))
    if y != c-1 and grid[x][y+1] == ".":
        moves.append((x, y+1))
    return moves

def createRoom(start):
	q = [start]
	room = []
	while q:
		cur = q.pop(0)		
		x = cur[0]
		y = cur[1]
		if grid[x][y] == visited:
			continue
		else:
			grid[x][y] = visited
			room.append((x, y))
		q.extend(getPossibleMoves(x, y))
	return room

for i in range(r):
	for j in range(c):
		if grid[i][j] == ".":
			rooms.append(createRoom((i, j)))

rooms.sort(key=lambda x: len(x), reverse=True)

numRooms = 0
sum = 0
while numRooms < len(rooms):
	x = len(rooms[numRooms])
	if sum + x <= tiles:
		sum += x
		numRooms += 1
	else:
		break
	
print(f"{numRooms} room{'' if numRooms == 1 else 's'}, {tiles-sum} square metre(s) left over")