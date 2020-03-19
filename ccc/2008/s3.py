def getPossibleMoves(pos):
    x = pos[0]
    y = pos[1]
    level = pos[2]
    symbol = grid[y][x]
    moves = []

    if x != 0 and symbol != "|" and grid[y][x-1] != "*":
        moves.append((x-1, y, level+1))
    if x != cols-1 and symbol != "|" and grid[y][x+1] != "*":
        moves.append((x+1, y, level+1))
    if y != 0 and symbol != "-" and grid[y-1][x] != "*":
        moves.append((x, y-1, level+1))
    if y != rows-1 and symbol != "-" and grid[y+1][x] != "*":
        moves.append((x, y+1, level+1))
    return moves

cases = int(input())
outputs = [-1 for _ in range(cases)]
for case in range(cases):
    rows = int(input())
    cols = int(input())

    visited = [[False for col in range(cols)] for row in range(rows)]
    grid = [input() for row in range(rows)]
    q = [(0,0,1)]

    while q:
        cur = q.pop(0)
        if not visited[cur[1]][cur[0]]:
            visited[cur[1]][cur[0]] = True
        else:
            continue
        
        q.extend(getPossibleMoves(cur))

        if cur[0] == cols-1 and cur[1] == rows-1:
            outputs[case] = cur[2]
            break

for output in outputs:
    print(output)