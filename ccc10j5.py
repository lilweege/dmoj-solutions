import sys
t = sys.stdin.readline().split()
start = (int(t[0]), int(t[1]), 0)
t = sys.stdin.readline().split()
end = (int(t[0]), int(t[1]))

def getMoves(pos):
    moves = []
    if pos[0] > 2 and pos[1] < 8:
        moves.append((pos[0]-2, pos[1]+1, pos[2]+1))
    if pos[0] > 2 and pos[1] > 1:
        moves.append((pos[0]-2, pos[1]-1, pos[2]+1))
        
    if pos[0] > 1 and pos[1] < 7:
        moves.append((pos[0]-1, pos[1]+2, pos[2]+1))    
    if pos[0] > 1 and pos[1] > 2:
        moves.append((pos[0]-1, pos[1]-2, pos[2]+1))
        
    if pos[0] < 8 and pos[1] < 7:
        moves.append((pos[0]+1, pos[1]+2, pos[2]+1))    
    if pos[0] < 8 and pos[1] > 2:
        moves.append((pos[0]+1, pos[1]-2, pos[2]+1))
    
    if pos[0] < 7 and pos[1] < 8:
        moves.append((pos[0]+2, pos[1]+1, pos[2]+1))
    if pos[0] < 7 and pos[1] > 1:
        moves.append((pos[0]+2, pos[1]-1, pos[2]+1))
    return moves

visited = [[False for i in range(8)] for j in range(8)]
q = [start]
while q:
    cur = q.pop(0)
    if visited[cur[0]-1][cur[1]-1]:
        continue
    else:
        visited[cur[0]-1][cur[1]-1] = True
    q.extend(getMoves(cur))

    if end[0] == cur[0] and end[1] == cur[1]:
        print(cur[2])
        break