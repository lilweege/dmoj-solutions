numCases = 5
for case in range(numCases):
	w = int(input())
	sentence = input().split(" ")

	lineLen = 0
	for word in sentence:
		if lineLen + len(word) <= w:
			lineLen += len(word) + 1
			print(word, end=" ")
		else:
			print("")
			if len(word) > w:
				brokenWord = word
				i = 0
				while len(brokenWord) > w:
					print(brokenWord[i:w])
					i += w
					brokenWord = brokenWord[w:]
				print(brokenWord, end=" ")
				lineLen = len(brokenWord) + 1
			else:
				print(word, end=" ")
				lineLen = len(word) + 1
	print("\n=====")
