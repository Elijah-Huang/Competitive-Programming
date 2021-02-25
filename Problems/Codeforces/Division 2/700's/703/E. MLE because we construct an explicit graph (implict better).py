# pypy def gonna tle but here goes (I'll try dials if heap fails? max path = (n-1)*(2*maxw)^2 ~ 10^9)

import sys
input = sys.stdin.buffer.readline
from heapq import heappush, heappop

n,m = map(int,input().split())
adj = [[]for i in range(52*(n+1))]
mx_dist = 10**9
dist = [mx_dist]*(52*(n+1))
dist[51*1 + n] = 0

for i in range(m):
    u,v,w = map(int,input().split())
    adj[u].append([v,w])
    adj[v].append([u,w])

for i in range(1,n+1):
    for v,w in adj[i]:
        adj[51*v + n].append([i*51 + w + n, 0])
    for j in range(1,51):
        for v,w in adj[i]:
            adj[i*51+j + n].append([51*v + n, (j+w)**2])

h = [(0,51*1 + n)]
while h:
    d, c = heappop(h)

    if dist[c] == d:
        for ne,w in adj[c]:
            if dist[ne] > d+w:
                dist[ne] = d+w
                heappush(h, (d+w, ne))

for i in range(1,n+1):
    if dist[51*i + n] != mx_dist:
        print(dist[51*i + n])
    else:
        print(-1)





