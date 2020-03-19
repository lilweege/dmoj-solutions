numTasks = 7
rules =[[1,7],
		[1,4],
		[2,1],
		[3,4],
		[3,5]]
while True:
	rule = [int(input()), int(input())]
	if rule == [0,0]:
		break
	rules.append(rule)

ans = ""
while True:
	canDo = list(range(1, numTasks+1))
	for c in ans:
		canDo.remove(int(c))
	for i in range(len(rules)):
		if rules[i][1] in canDo:
			canDo.remove(rules[i][1])
	
	if canDo:
		ans += str(canDo[0])
		for i in range(len(rules)):
			if rules[i][0] == canDo[0]:
				rules[i][0] = rules[i][1]
				rules[i][1] = 0
	else:
		possible = not len(ans) < numTasks
		break

print(" ".join(ans) if possible else "Cannot complete these tasks. Going to bed.")