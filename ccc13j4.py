t = int(input())
c = int(input())
chores = [int(input()) for i in range(c)]

chores.sort()

ellapsed = 0
completed = 0
while ellapsed <= t:
	ellapsed += chores[completed]
	completed += 1

print(completed-1)