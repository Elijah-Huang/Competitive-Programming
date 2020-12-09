'''
ID: elijahj1
TASK: stall4
LANG: PYTHON3
'''
from collections import deque
def prog():
    with open('stall4.in') as fin:
        n,m = map(int,fin.readline().split())
        adj_list = [set() for i in range(n+m+2)]
        weight = [[0 for i in range(n+m+2)] for j in range(n+m+2)]
        source = 0
        sink = n+m+1
        for cow in range(m+1,n+m+1):
            for stall in map(int,fin.readline()[2:].split()):
                adj_list[cow].add(stall)
                weight[cow][stall] += 1
            adj_list[source].add(cow)
            weight[source][cow] += 1
        for stall in range(1,m+1):
            adj_list[stall].add(sink)
            weight[stall][sink] += 1
            
    max_match = 0
    found  = True
    while found:
        found = False
        s = deque([source])
        visited = set([source])
        while s:
            if s[-1] == sink:
                found = True
                break
            else:
                had_neighbor = False
                for neighbor in adj_list[s[-1]]:
                    if neighbor not in visited:
                        visited.add(neighbor)
                        s.append(neighbor)
                        had_neighbor = True
                        break
                if not had_neighbor:
                    s.pop()         
        if found:
            s = list(s)
            max_match += 1
            for i in range(len(s)-1):
                weight[s[i]][s[i+1]] -=1
                if weight[s[i]][s[i+1]] == 0:
                    adj_list[s[i]].remove(s[i+1])
            for i in range(len(s)-1,0,-1):
                weight[s[i]][s[i-1]] +=1
                adj_list[s[i]].add(s[i-1])
    with open('stall4.out','w') as fout:
        fout.write(str(max_match) + '\n')
prog()            
