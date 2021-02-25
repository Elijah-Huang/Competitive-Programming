import sys
input = sys.stdin.buffer.readline
from heapq import heappush, heappop

n,m = map(int,input().split())
adj = [[] for i in range(n+1)]
mx_dist = 10**9
dist = [mx_dist]*(51*(n+1))
dist[51*1] = 0

for i in range(m):
    u,v,w = map(int,input().split())
    adj[u].append((v,w))
    adj[v].append((u,w))

h = [(0,51*1)]
while h:
    d, c = heappop(h)

    if dist[c] == d:
        c, last_w = divmod(c, 51)
        for ne,w in adj[c]:
            if last_w:
                new_d = d + (w + last_w) ** 2
                if dist[51 * ne] > new_d:
                    dist[51 * ne] = new_d
                    heappush(h, (new_d, 51 * ne))
            else:
                if dist[51 * ne + w] > d:
                    dist[51 * ne + w] = d
                    heappush(h, (d, 51 * ne + w))

sys.stdout.write(' '.join([str(dist[51*i]) if dist[51*i] != mx_dist else '-1' for i in range(1, n+1)]))