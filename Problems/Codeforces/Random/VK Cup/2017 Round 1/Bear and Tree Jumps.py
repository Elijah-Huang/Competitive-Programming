import sys
input = sys.stdin.buffer.readline
from collections import deque

n, k = map(int, input().split())
tot_dist = 0
vis = [0]*(n+1)
dist = [[[0]*2 for j in range(k)] for i in range(n+1)]
adj = [[]for i in range(n+1)]
for i in range(n-1):
    u,v = map(int,input().split())
    adj[u].append(v)
    adj[v].append(u)

s = deque([1])
while s:
    c = s[-1]

    if not vis[c]:
        vis[c] = 1
        for ne in adj[c]:
            if not vis[ne]:
                s.append(ne)
    else:
        # update dists via pairing paths at the current node
        tot =  [0]*k
        sum_dist = 0
        pairable = 0
        for ne in adj[c]:
            # direct jumps of exactly k
            tot_dist += pairable * sum([dist[ne][i][0] for i in range(k)]) + \
                        sum_dist * sum([dist[ne][i][1] for i in range(k)])
            # extra from remainder mod k
            for i in range(k):
                for j in range(k):
                    tot_dist += (i+j+2+k-1)//k*dist[ne][i][1]*tot[j]
            # update pairable nodes
            for i in range(k):
                tot[i]+= dist[ne][i][1]
                pairable += dist[ne][i][1]
                sum_dist += dist[ne][i][0]
        # update paths
        for ne in adj[c]:
            for i in range(k):
                for j in range(2):
                    dist[c][i][j] += dist[ne][(i+k-1)%k][j]
            dist[c][0][0] += dist[ne][k-1][1]
        dist[c][0][1] += 1
        # update dists from path directly to current node
        for i in range(k):
            tot_dist += dist[c][i][0] + (i+k-1)//k * dist[c][i][1]

        s.pop()

print(tot_dist)