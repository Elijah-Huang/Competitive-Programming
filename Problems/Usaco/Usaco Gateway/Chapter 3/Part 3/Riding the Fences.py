'''
ID: elijahj1
TASK: fence
LANG: PYTHON3
'''
from collections import deque
def prog():
    with open('fence.in') as fin:
        f = int(fin.readline().strip())
        adj_list = {}
        for line in fin.readlines():
            a,b = map(int,line.split())
            adj_list[a]= adj_list.get(a,[]) + [b]
            adj_list[b]= adj_list.get(b,[]) + [a]
    odds = []
    for i in adj_list:
        if (len(adj_list[i]) % 2) == 1:
            odds.append(i)
    if len(odds) == 0:
        start = min(adj_list)
    else:
        start = min(odds)
    loc = start
    stack = deque([None])
    circuit = []
    while stack:
        if len(adj_list[loc]):
            stack.append(loc)
            prev = loc
            loc = min(adj_list[prev])
            adj_list[prev].remove(loc)
            adj_list[loc].remove(prev)
        else:
            circuit.append(loc)
            loc = stack.pop()
    circuit.reverse()
    output = "\n".join(map(str,circuit)) + '\n'
    with open('fence.out','w') as fout:
        fout.write(output)
prog()
