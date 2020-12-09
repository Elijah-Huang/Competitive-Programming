"""
ID: elijahj1
TASK: skidesign
LANG: PYTHON3
"""
with open('skidesign.in') as fin:
    n = fin.readline()
    hills = [int(line.strip()) for line in fin.readlines()]
    hills.sort()
costs = []
smallest = hills[0]
largest = hills[-1]
if largest - smallest <= 17:
    costs.append(0)
else:
    new_min = smallest
    new_max = smallest + 17
    while new_max <= largest:
        cost = 0 
        for hill in hills:
            if hill < new_min:
                cost += (new_min - hill)**2
            if hill > new_max:
                cost += (hill - new_max)**2
        costs.append(cost)
        new_min += 1
        new_max += 1
minimum = min(costs)
with open('skidesign.out','w') as fout:
    fout.write(str(minimum) +'\n')
    
