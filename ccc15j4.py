m = int(input())

messages = []
friends = []
for l in range(m):
	t = input().split()
	messages.append([t[0], int(t[1])])
	if t[0] != "W" and int(t[1]) not in friends:
		friends.append(int(t[1]))

friends.sort()
waitTime = []
for friend in friends:
	waitTime.append([friend,0])

outgoing = []
for entry in messages:
	delay = entry[1]-1 if entry[0] == "W" else 1
	
	if entry[0] == "S":
		outgoing.remove(entry[1])
	if entry[0] == "R":
		outgoing.append(entry[1])
	for friend in outgoing:
		waitTime[friends.index(friend)][1] += delay
		
for friend in outgoing:
	waitTime[friends.index(friend)][1] = -1

for time in waitTime:
	print(time[0], time[1])