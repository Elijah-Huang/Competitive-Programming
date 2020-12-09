import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
from collections import deque
def find_components(node,graph,n,m,visited):
    queue = deque([node])
    while queue:
        node = queue[-1]
        visited.add(node)
        neighbors = [(node[0]+1,node[1]),(node[0]-1,node[1]),\
                     (node[0],node[1]+1),(node[0],node[1]-1)]
        had_neighbors = False
        for neighbor in neighbors:
            i,j = neighbor
            if neighbor not in visited and 0<= i < n and 0<= j < m and graph[i][j] == '#':
                queue.append(neighbor)
                had_neighbors = True
                break
        if not had_neighbors:
            queue.pop()
def yo():         
    n,m = map(int,input().split())
    graph = [str(input().strip())[2:-1] for i in range(n)]
    e_row = 0
    e_column = 0
    for row in graph:
        if row == "."*m:
            e_row = 1
            break
    for j in range(m):
        same = True
        for i in range(n):
            if graph[i][j] != '.':
                same = False
                break
        if same:
            e_column = 1
            break
    if e_row^e_column == 1:
        print(-1)
        return
    for row in graph:
        start = m-1
        value = '#'
        for j in range(m):
            if row[j] == '#':
                start = j
                break
        change = False
        gap = False
        for j in range(start+1,m):
            if row[j] != value:
                change = True
            elif change:
                gap = True
        if gap:
            print(-1)
            break
    if not gap:
        for j in range(m):
            start = n-1
            value = '#'
            for i in range(n):
                if graph[i][j] == '#':
                    start = i
                    break
            change = False
            gap = False
            for i in range(start+1,n):
                if graph[i][j] != value:
                    change = True
                elif change:
                    gap = True
            if gap:
                print(-1)
                break
    if not gap:
        visited = set()
        num_components = 0
        for i in range(n):
            for j in range(m):
                if (i,j) not in visited and graph[i][j] == '#':
                    num_components += 1
                    find_components((i,j),graph,n,m,visited)
        print(num_components)
    
yo()

