from collections import deque
import sys
input = sys.stdin.buffer.readline

n,m,k = map(int,input().split())
colors = list(map(int,input().split()))
adj = [[] for i in range(n)]
for i in range(m):
    u,v = map(int,input().split())
    u -= 1
    v -= 1
    adj[u].append(v)
    adj[v].append(u)

total_change = 0
visited = [0]*n
for i in range(n):
    if not visited[i]:
        curr_comp = []
        s = deque([i])
        while s:
            curr = s[-1]
            if not visited[curr]:
                for neighbor in adj[curr]:
                    s.append(neighbor)
                visited[curr] = 1
                curr_comp.append(curr)
            else:
                s.pop()
        total = len(curr_comp)
        most = {}
        for a in curr_comp:
            if colors[a] in most:
                most[colors[a]] += 1
            else:
                most[colors[a]] = 1
        total_change += total - max(most.values())
        
print(total_change)

                
