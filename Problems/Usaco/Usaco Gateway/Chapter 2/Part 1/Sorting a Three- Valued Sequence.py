"""
ID: elijahj1
TASK: sort3
LANG: PYTHON3
"""
def sorter(n,order):
    exchanges = 0
    current = [[0,0,0],[0,0,0],[0,0,0]]
    totals = [0,0,0]
    for num in order:
        if num == 1:
            totals[0] += 1
        if num == 2:
            totals[1] += 1
        if num == 3:
            totals[2] += 1
    elapsed = 0 
    for a in range(3):
        for i in range(elapsed,elapsed + totals[a]):
            if order[i] == 1:
                current[a][0] += 1
            if order[i] == 2:
                current[a][1] += 1
            if order[i] == 3:
                current[a][2] += 1
        elapsed += totals[a]
    for a in range(3):
        for b in range(3):
            if b != a:
                exchange = min(current[a][b],current[b][a])
                current[a][b] -= exchange
                current[b][a] -= exchange
                exchanges += exchange
    triples = current[0][1] + current[0][2]
    exchanges += triples*2
    return exchanges
        
with open("sort3.in") as fin:
    n = fin.readline().strip()
    order = [int(num.strip()) for num in fin.readlines()]
output = sorter(n,order)
with open('sort3.out', 'w') as fout:
    fout.write(str(output) + '\n')

    

