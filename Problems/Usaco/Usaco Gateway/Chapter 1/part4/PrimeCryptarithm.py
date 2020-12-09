"""
ID:elijahj1
TASK:crypt1
LANG:PYTHON3
"""
with open("crypt1.in") as fin:
    n = int(fin.readline())
    digits = set(list(map(int,fin.readline().split())))
solutions = 0 
for a in digits:
    for b in digits:
        for c in digits:
            for d in digits:
                for e in digits:
                    first = str((100*a + 10*b + c)*e)
                    if len(first) != 3:
                        continue 
                    second = str((100*a + 10*b + c)*d)
                    if len(second) != 3:
                        continue
                    count1 = 0
                    count2 = 0 
                    for digit in first:
                        if int(digit) in digits:
                            count1 += 1
                        else:
                            break
                    if count1 == len(first):
                        pass
                    else:
                        continue
                    for digit in second:
                        if int(digit) in digits:
                            count2 += 1
                        else:
                            break
                    if count2 == len(second):
                        pass
                    else:
                        continue
                    final = str((100*a + 10*b + c)*(10*d+e))
                    if len(final) != 4:
                        continue
                    count3 = 0 
                    for digit in final:
                        if int(digit) in digits:
                            count3 += 1
                        else:
                            break
                    if count3 == len(final):
                        solutions += 1
with open("crypt1.out", "w") as fout:
    fout.write(str(solutions) + '\n')
                    
                    
                        
                    
                    
