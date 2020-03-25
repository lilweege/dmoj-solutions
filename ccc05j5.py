def monkeyWord(s):
	while "ANA" in s or "BAS" in s:
		s = s.replace("ANA","A")
		s = s.replace("BAS","A")	
	return s == 'A'

while True:
	word = input()
	if word == 'X':
		break
	
	print("YES" if monkeyWord(word) else "NO")
