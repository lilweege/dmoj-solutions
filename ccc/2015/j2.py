sequence = input()

happy = sequence.count(":-)")
sad = sequence.count(":-(")

diff = happy - sad

if happy == 0 and sad == 0:
	print("none")
elif diff == 0:
	print("unsure")
elif diff > 0:
	print("happy")
elif diff < 0:
	print("sad")