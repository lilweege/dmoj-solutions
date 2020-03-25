p = input()
valid = len(p) == p.count("I") + p.count("O") + p.count("S") + p.count("H") + p.count("Z") + p.count("X") + p.count("N")
print("YES" if valid else "NO")