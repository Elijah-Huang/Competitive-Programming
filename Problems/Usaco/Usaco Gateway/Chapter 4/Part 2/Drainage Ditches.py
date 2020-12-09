'''
ID: elijahj1
TASK: ditch
LANG: PYTHON3
'''
from collections import deque 
def prog():
    with open('ditch.in') as fin:
        n,m = map(int,fin.readline().split())
        adj_list = [set() for i in range(m+1)]
        weights = [[0 for i in range(m+1)] for i in range(m+1)]
        for line in fin.readlines():
            a,b,w = map(int,line.split())
            adj_list[a].add(b)
            weights[a][b] += w
    max_flow = 0
    found = True
    while found:
        path = deque([1])
        found = False
        visited = set([1])
        while path:
            if path[-1] == m:
                found = True
                break
            else:
                had_neighbor = False
                for neighbor in adj_list[path[-1]]:
                    if neighbor not in visited:
                        visited.add(neighbor)
                        path.append(neighbor)
                        had_neighbor = True
                        break
                if not had_neighbor:
                    path.pop()
                
        if found:
            path = list(path)
            min_weight = 10**7
            for i in range(len(path)-1):
                min_weight = min(min_weight, weights[path[i]][path[i+1]])
            max_flow += min_weight
            for i in range(len(path)-1):
                weights[path[i]][path[i+1]] -= min_weight
                if weights[path[i]][path[i+1]] == 0:
                    adj_list[path[i]].discard(path[i+1])
            for i in range(len(path)-1,0,-1):
                weights[path[i]][path[i-1]] += min_weight
                adj_list[path[i]].add(path[i-1])
    with open('ditch.out','w') as fout:
        fout.write(str(max_flow) + '\n')
prog()   
