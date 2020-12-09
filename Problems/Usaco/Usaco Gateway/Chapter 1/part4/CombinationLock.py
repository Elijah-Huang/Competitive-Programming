"""
ID: elijahj1
TASK: combo
LANG: PYTHON3
"""
with open("combo.in") as fin:
    n = int(fin.readline())
    combo1 = list(map(int,fin.readline().split()))
    combo2 = list(map(int,fin.readline().split()))
intersection = 1
if n < 6:
    total = n**3
else:
    for i in range(3):
        if combo1[i] > combo2[i]:
            max = combo1[i]
            min = combo2[i]
        else:
            max = combo2[i]
            min = combo1[i]
        intersection1 = (5 - (max-min))
        if intersection1 >= 0:
            pass
        else:
            intersection1 = 0
        intersection2 = (5 - (min+n - max))
        if intersection2 >= 0:
            pass
        else:
            intersection2 = 0
        intersection *= (intersection1 + intersection2)
        if intersection == 0:
            break
    total = 250 - intersection
with open("combo.out","w") as fout:
    fout.write(str(total) + '\n')

    
