"""
ID: elijahj1
TASK: money
LANG: PYTHON3
"""
def ways(v,n):
    amounts = [0 for i in range(n+1)]
    amounts[0] = 1
    for value in denominations:
        if value > n:
            continue
        for i in range(value):
            base = amounts[i]
            for j in range(value+i,n+1,value):
                amounts[j] += base
                base = amounts[j]
    return amounts[n]
                
with open('money.in') as fin:
    v, n = map(int,fin.readline().split())
    denominations = list(map(int,fin.read().split()))
output = ways(v,n)
with open('money.out','w') as fout:
    fout.write(str(output) + '\n')
