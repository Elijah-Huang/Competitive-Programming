import sys
input = sys.stdin.buffer.readline
from collections import deque
def prog():
    n = int(input())
    adj_list = [[] for i in range(n+1)]
    for i in range(n-1):
        a,b = map(int,input().split())
        adj_list[a].append(b)
        adj_list[b].append(a)
    leaves = set()
    for i in range(1,n+1):
        if len(adj_list[i]) == 1:
            leaves.add(i)
    for i in leaves:
        root = i
        break
    q = deque([root])
    dists = [0 for i in range(n+1)]
    visited = set()
    while q:
        curr = q.popleft()
        for neighbor in adj_list[curr]:
            if neighbor not in visited:
                dists[neighbor] = dists[curr] + 1
                q.append(neighbor)
                visited.add(neighbor)
    odd = False
    for leave in leaves:
        if dists[leave] % 2 == 1:
            odd = True
            break
    if odd:
        minimum = 3
    else:
        minimum = 1
    distinct_leaves = 0
    for i in range(1,n+1):
        for neighbor in adj_list[i]:
            if neighbor in leaves:
                distinct_leaves += 1
                break
    print(minimum, n-1 - len(leaves) + distinct_leaves)
prog()
        
