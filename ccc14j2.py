num = input()
seq = input()
diff = seq.count("A") - seq.count("B")

if diff == 0:
	print("Tie")
elif diff > 0:
	print("A")
elif diff < 0:
	print("B")