board = list(range(101))
board[99] = 77
board[90] = 48
board[67] = 86
board[54] = 19
board[40] = 64
board[9] = 34

pos = 1
b = False
n = int(input())
while n != 0:
	if pos + n <= 100:
		pos += n
		pos = board[pos]
	print("You are now on square", pos)
	if pos == 100:
		b = True
		break
	n = int(input())

print("You Win!" if b else "You Quit!")
