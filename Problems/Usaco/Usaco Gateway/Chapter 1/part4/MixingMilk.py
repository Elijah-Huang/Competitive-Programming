"""
ID: elijahj1
TASK: milk
LANG: PYTHON3
"""
with open("milk.in") as fin:
    n, m = list(map(int,fin.readline().split()))
    unsorted_milk = []
    for line in fin.readlines():
        unsorted_milk.append(list(map(int,line.split())))
    unsorted_milk.sort()
    milk = unsorted_milk
cost = 0 
for farm in milk:
    if n > farm[1]:
        cost += farm[0] * farm[1]
        n -= farm[1]
    else:
        cost += farm[0]*n
        break
with open("milk.out", "w") as fout:
    fout.write(str(cost)+"\n")
    
    
    
