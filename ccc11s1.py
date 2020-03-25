import sys
n = int(sys.stdin.readline())
lines = [sys.stdin.readline() for _ in range(n)]
numS = 0
numT = 0

for line in lines:
	for c in range(len(line)):
		if line[c].lower() == "s":
			numS += 1
		if line[c].lower() == "t":
			numT += 1

print("English" if numS < numT else "French")
