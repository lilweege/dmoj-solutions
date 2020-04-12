def getMoves(y, x):
	moves = []
	if y > 0 and x > 1:
		if board[y - 1][x - 2] > board[y][x] + 1:
			board[y - 1][x - 2] = board[y][x] + 1
			moves.append((y - 1, x - 2))
	if y > 1 and x > 0:
		if board[y - 2][x - 1] > board[y][x] + 1:
			board[y - 2][x - 1] = board[y][x] + 1
			moves.append((y - 2, x - 1))
	if y > 0 and x < c - 2:
		if board[y - 1][x + 2] > board[y][x] + 1:
			board[y - 1][x + 2] = board[y][x] + 1
			moves.append((y - 1, x + 2))
	if y > 1 and x < c - 1:
		if board[y - 2][x + 1] > board[y][x] + 1:
			board[y - 2][x + 1] = board[y][x] + 1
			moves.append((y - 2, x + 1))
	if y < r - 1 and x > 1:
		if board[y + 1][x - 2] > board[y][x] + 1:
			board[y + 1][x - 2] = board[y][x] + 1
			moves.append((y + 1, x - 2))
	if y < r - 2 and x > 0:
		if board[y + 2][x - 1] > board[y][x] + 1:
			board[y + 2][x - 1] = board[y][x] + 1
			moves.append((y + 1, x - 1))
	if y < r - 1 and x < c - 2:
		if board[y + 1][x + 2] > board[y][x] + 1:
			board[y + 1][x + 2] = board[y][x] + 1
			moves.append((y + 1, x + 2))
	if y < r - 2 and x < c - 1:
		if board[y + 2][x + 1] > board[y][x] + 1:
			board[y + 2][x + 1] = board[y][x] + 1
			moves.append((y + 2, x + 1))

	return moves

n = int(input())
for _ in range(n):
	r = int(input())
	c = int(input())
	pr = r - int(input())
	pc = int(input()) - 1
	kr = r - int(input())
	kc = int(input()) - 1
	win = False
	stalemate = -1

	board = [[float('inf') for _ in range(c)] for _ in range(r)]
	board[kr][kc] = 0
	q = [(kr, kc)]
	while q:
		q.extend(getMoves(*q.pop(0)))

	for i in range(pr):
		if board[pr - i][pc] == i or (i - board[pr - i][pc]) % 2 == 0 and board[pr - i][pc] < i:
			win = i
			break
		elif board[pr - i - 1][pc] == i and stalemate == -1:
			stalemate = i
			break

	if win:
		print(f"Win in {win} knight move(s).")
	elif stalemate != -1:
		print(f"Stalemate in {stalemate} knight move(s).")
	else:
		print(f"Loss in {i} knight move(s).")
