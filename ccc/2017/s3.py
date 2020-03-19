'''
import sys
n = int(sys.stdin.readline())
t = sys.stdin.readline().split()
pieces = [int(t[i]) for i in range(n)]
pieces.sort()

heights = set()
for i in range(n):
	for j in range(n):
		if i < j:
			heights.add(pieces[i]+pieces[j])

maxLength = 1
possible = 1
for height in list(heights):
	length = 1
	current = pieces.copy()
	
	for i in range(n):
		for j in range(i, n):
			if i < j and current[i] != -1 and current[j] != -1:
				if current[i] + current[j] == height:
					current[i] = -1
					current[j] = -1
					length += 1
	
	if length == maxLength:
		possible += 1
	elif length > maxLength:
		maxLength = length
		possible = 1

print(maxLength-1, possible)
'''
import sys
n = int(sys.stdin.readline())
pieces = [int(x) for x in sys.stdin.readline().split()]
freq = [0 for x in range(2001)]
count = [0 for x in range(4002)]

for i in pieces:
    freq[i] += 1


for i in range(1, 2001):
    if freq[i] > 0:
        for j in range(i, 2001):
            if freq[j] > 0:
                # i and j are the same
                if i == j:
                    count[i+j] += freq[i]//2
                # i and j are not the same
                else:
                    count[i+j] += min(freq[i], freq[j])

final = 0
fcount = 0

for q in count:
    if q > final:
        final = q
        fcount = 1

    elif q == final:
        fcount += 1

print(final, fcount)
