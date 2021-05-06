import sys
input = sys.stdin.buffer.readline
from collections import deque

dx = [0, 1, 0, -1]
dy = [-1,0,1,0]

n,m,w = map(int,input().split())

a = [list(map(int,input().split())) for i in range(n)]
mx_dist = 1e16

dist = [mx_dist]*2*n*m

starts = [[0,0],[n-1,m-1]]

for start in range(2):
    add = start*n*m
    source = add + starts[start][0]*m + starts[start][1]
    dist[source] = 0.0 # double faster # less mem than big int? o:
    q = deque([source])
    while q:
        curr = q.popleft()
        i,j = divmod(curr-add,m)

        for k in range(4):
            newi = i + dx[k]
            newj = j + dy[k]

            if 0 <= newi < n and 0 <= newj < m and a[newi][newj] != -1:
                newcurr = add + newi*m + newj
                if dist[newcurr] == mx_dist:
                    dist[newcurr] = dist[curr] + 1
                    q.append(newcurr)

mn_dist = min(dist[n*m-1] * w,
          (min([dist[i*m+j] * w + a[i][j] if a[i][j] > 0 else mx_dist for i in range(n) for j in range(m)])) +
          (min([dist[n*m+i*m+j] * w + a[i][j] if a[i][j] > 0 else mx_dist for i in range(n) for j in range(m)])))

print(-1 if mn_dist >= mx_dist else int(mn_dist))