import sys
input = sys.stdin.buffer.readline
from heapq import heappush, heappop
from math import inf

n,m = map(int,input().split())
adj = [[] for i in range(n+1)]
mx_dist = inf
dist = [mx_dist]*(4*(n+1))
dist[4] = 0

for i in range(m):
    u,v,w = map(int, input().split())
    adj[u].append((v,w))
    adj[v].append((u,w))

# dist | node | max taken | min taken
h = [(0,4)]
while h:
    d,c2 = heappop(h)
    c = c2//4
    mx = (c2-c*4)//2
    mn = (c2-c*4)%2

    if dist[c2] != inf:
        for v, w in adj[c]:
            node = 4*v + 2*mx + mn
            if dist[node] > d+w:
                dist[node] = d+w
                heappush(h, (d+w,node))
            node = 4*v + 2 + mn
            if mx == 0:
                if dist[node] > d:
                    dist[node] = d
                    heappush(h, (d,node))
            node = 4*v + 2*mx + 1
            if mn == 0:
                if dist[node] > d+2*w:
                    dist[node] = d+2*w
                    heappush(h, (d+2*w,node))
            node = 4*v + 2 + 1
            if mx == 0 and mn == 0:
                if dist[node] > d+w:
                    dist[node] = d+w
                    heappush(h, (d+w,node))

sys.stdout.write(' '.join([str(dist[4*i+3]) for i in range(2,n+1)]))