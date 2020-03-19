def toArabic(s):
    values = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
    digits = [values[i] for i in s]
    n = 0
    for i in range(len(digits)-1):
        val = digits[i]
        next = digits[i+1]
        if val >= next:
            n += val
        else:
            n -= val
    n += digits[-1]
    return n


def toRoman(n):
    if n > 1000:
        return "CONCORDIA CUM VERITATE"
    values = [  [1000, "M"],
                [900, "CM"],
                [500, "D"],
                [400, "CD"],
                [100, "C"],
                [90, "XC"],
                [50, "L"],
                [40, "XL"],
                [10, "X"],
                [9, "IX"],
                [5, "V"],
                [4, "IV"],
                [1, "I"]]
    s = ""
    i = 0
    while  n > 0:
        for _ in range(n//values[i][0]):
            n -= values[i][0]
            s += values[i][1]
        i += 1
    return s


l = int(input())
out = []
for x in range(l):
    s = input()
    new = s.replace("=", "")
    t = new.split("+")
    res = toRoman(toArabic(t[0]) + toArabic(t[1]))
    out.append(s + res)

for line in out:
    print(line)