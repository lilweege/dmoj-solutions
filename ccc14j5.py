n = int(input())
seq1 = input().split()
seq2 = input().split()
good = n%2==0

if good:
	pairs = [[seq1[i], seq2[i]] for i in range(n)]
	
	for pair in pairs:
		if [pair[1], pair[0]] not in pairs or pair[0] == pair[1]:
			good = False
			break

print("good" if good else "bad")