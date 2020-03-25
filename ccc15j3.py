word = input()
new = ""
vowels = [1,5,9,15,21]
for letter in word:
	new += letter
	ascii = ord(letter)-96
	if ascii not in vowels:
		off = 1
		while True:
			if ascii - off in vowels:
				new += chr(ascii-off+96)
				break
			elif ascii + off in vowels:
				new += chr(ascii+off+96)
				break
			off += 1
		
		if letter != "z":
			off = 1
			while True:
				if ascii + off not in vowels:
					new += chr(ascii+off+96)
					break
				elif off + ascii == 26:
					new += "z"
					break
				off += 1
		else:
			new += "z"

print(new)