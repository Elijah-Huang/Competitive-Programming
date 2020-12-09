import sys
input = sys.stdin.buffer.readline
from collections import deque
def prog():
    n,x = map(int,input().split())
    adj = [[] for i in range(n + 1)]
    for i in range(n-1):
        u,v = map(int,input().split())
        adj[u].append(v)
        adj[v].append(u)
    
    dist = [0]*(n+1)
    parent = [0]*(n+1)
    visited = [0]*(n+1)
    dist2 = [0]*(n+1)
    visited2 = [0]*(n+1)
    s = deque([1])
    
    while s:
        curr = s[-1]
        if not visited[curr]:
            visited[curr] = 1
            for neighbor in adj[curr]:
                if not visited[neighbor]:
                    parent[neighbor] = curr
                    s.append(neighbor)
                    dist[neighbor] = dist[curr] + 1
        else:
            s.pop()

    curr = x
    moved_up = 0
    while moved_up + 1 < dist[parent[curr]]:
        curr = parent[curr]
        moved_up += 1
        
    s = deque([curr])
    while s:
        curr = s[-1]
        if not visited2[curr]:
            visited2[curr] = 1
            for neighbor in adj[curr]:
                if parent[curr] != neighbor:
                    s.append(neighbor)
                    dist2[neighbor] = dist2[curr] + 1
        else:
            s.pop()

    best_loc = 0
    best_dist = -1
    for i in range(n + 1):
        if visited2[i] and dist2[i] > best_dist:
            best_dist = dist2[i]
            best_loc = i
            
    print(2*dist[best_loc])

prog()
