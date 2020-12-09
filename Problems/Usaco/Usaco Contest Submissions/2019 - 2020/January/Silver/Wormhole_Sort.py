import sys
sys.setrecursionlimit(10**5)

def dfs(adj_list,visited, curr_node):
    visited.add(curr_node)
    for neighbor in adj_list[curr_node]:
        if neighbor not in visited:
            dfs(adj_list,visited,neighbor)
            
def one_component(start,stop,faulty,n,wormholes):
    adj_list = [[] for i in range(n+1)]
    for i in range(start,stop+1):
        a,b,w = wormholes[i]
        adj_list[a].append(b)
        adj_list[b].append(a)
    for i in faulty:
        start = i
        break 
    visited = set()
    dfs(adj_list,visited,start)
    return visited >= faulty
    
def prog():
    with open('wormsort.in') as fin:
        n,m = map(int,fin.readline().split())
        locations = list(map(int,fin.readline().split()))
        wormholes = [list(map(int,line.split())) for line in fin.readlines()]
    faulty = set()
    for i in range(n):
        if locations[i] != i+1:
            faulty.add(i+1)
    if len(faulty) == 0:
        min_width = -1
    else:
        wormholes.sort(reverse= True, key = lambda x: x[2])
        worst_cases = []
        curr = wormholes[0][2]
        for i in range(m):
            new = wormholes[i][2]
            if new != curr:
                worst_cases.append(i-1)
                curr = new
        worst_cases.append(m-1)
        r = len(worst_cases)-1
        l = 0
        while r > l:
            m = int((r+l)/2)
            if one_component(0,worst_cases[m],faulty,n,wormholes):
                r = m-1
            else:
                l = m+1
        if one_component(0,worst_cases[l],faulty,n,wormholes):
            min_width = wormholes[worst_cases[l]][2]
        else:
            min_width = wormholes[worst_cases[l+1]][2]
    with open('wormsort.out','w') as fout:
        fout.write(str(min_width) + '\n')
prog()
