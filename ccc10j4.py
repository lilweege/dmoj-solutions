outputs = []
while True:
    t = input().split()
    length = int(t[0])
    if length == 0:
        break

    sequence = []
    for i in range(length):
        sequence.append(int(t[i+1]))
    
    diffs = []
    for i in range(1, length):
        diffs.append(sequence[i]-sequence[i-1])
    
    if length == 1:
        outputs.append(0)
    else:
        for shortest in range(1, length):
            s = True
            cycle = diffs[:shortest]
        
            for i in range(1, length):
                currentCycle = diffs[(i-1)*shortest:i*shortest]
                if currentCycle == []:
                    break
                if len(currentCycle) != shortest:
                    if currentCycle != cycle[:len(currentCycle)]:
                        s = False
                        break
                else:
                    if currentCycle != cycle:
                        s = False
                        break

            if s:
                outputs.append(shortest)
                break

for output in outputs:
    print(output)