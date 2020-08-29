import sys
input = sys.stdin.readline


def main():


	n = int(input())
	a = [int(input()) for _ in range(n)]
	
	for x in range(2 ** n + 1):
		p = 0
		for i in range(n):
			p += a[i] if (x >> i & 1) else -a[i]
			p %= 360
		if p == 0:
			print("YES")
			return
	
	print("NO")
	
	# poss = [0]
	# for i in range(n):
		# breadth = []
		# while poss:
			# x = poss.pop(0)
			# breadth.append((x - a[i]) % 360)
			# breadth.append((x + a[i]) % 360)
		# poss = breadth
	
	# print("YES" if 0 in poss else "NO")
	

if __name__ == '__main__':
	main()