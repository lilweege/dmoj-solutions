'''
n = int(input())

names = []
values = []
for line in range(n):
	t = input().split()
	names.append(t[0])
	values.append(2 * int(t[1]) + 3 * int(t[2]) + int(t[3]))

bests = [values[0], 0]
winners = [names[0], None]
for i in range(n):

	if i == 1:
		continue

	if values[i] > bests[0] or (values[i] == bests[0] and names[i] == sorted([winners[0], names[i]])[0]):
			winners[1] = winners[0]
			bests[1] = bests[0]
			winners[0] = names[i]
			bests[0] = values[i]

	elif values[i] > bests[1] or (values[i] == bests[1] and names[i] == sorted([winners[1], names[i]])[0]):
			winners[1] = names[i]
			best[1] = values[i]


if winners[0] != None:
	print(winners[0])
if winners[1] != None:
	print(winners[1])
'''


n = int(input())

names = []
values = []
for line in range(n):
	t = input().split()
	names.append(t[0])
	values.append(2 * int(t[1]) + 3 * int(t[2]) + int(t[3]))

bests = [0, 0]
winners = ["", ""]
for i in range(n):
	if winners[0] == None:
		winners[0] = names[i]
		bests[0] = values[i]
		continue
	
	if values[i] == bests[0]:
		if names[i] == sorted([winners[0], names[i]])[0]:
			winners[1] = winners[0]
			bests[1] = bests[0]
			winners[0] = names[i]
			bests[0] = values[i]
		else:
			winners[1] = names[i]
			bests[1] = values[i]
			
	elif values[i] == bests[1]:
		if names[i] == sorted([winners[1], names[i]])[0]:
			winners[1] = names[i]
			bests[1] = values[i]
	
	elif values[i] > bests[0]:
			winners[1] = winners[0]
			bests[1] = bests[0]
			winners[0] = names[i]
			bests[0] = values[i]
	elif values[i] > bests[1]:
			winners[1] = names[i]
			bests[1] = values[i]

if winners[0] != None:
	print(winners[0])
if winners[1] != None:
	print(winners[1])
