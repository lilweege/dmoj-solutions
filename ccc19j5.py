def getStep(r, p, w):
	return {"r": r,
			"p": p,
			"w": w}

'''
# take inputs
r1 = input().split()
r2 = input().split()
r3 = input().split()
rules = [{"in": r1[0], "out": r1[1]},
		 {"in": r2[0], "out": r2[1]},
		 {"in": r3[0], "out": r3[1]}]
t = input().split()
s = int(t[0]) # number of steps
i = t[1] # initial sequence
f = t[2] # final sequence
'''


# sample inputs
rules = [{"in": "AA", "out": "AB"},
		 {"in": "AB", "out": "BB"},
		 {"in": "B", "out": "AA"}]
s = 4
i = "AB"
f = "AAAB"

cur = i
steps = []

while cur != f:
	for rule in rules:
		valid = cur.count(rule["in"])
	break

'''
for step in steps:
	print(str(step["r"]) + " " + str(step["p"]) + " " + step["w"])
'''