# O(n*2^n) (however quite a few states are not visited)
# most important optimization is not transitioning from unvisited states
#   (only ~ 1% of states are visited) (transition is O(n))
# other optimizations are using floats, bitwise operators, and precomputing dists/ reducing ops
xs,ys = map(float,input().split())

n = int(input())

dist = [[0]*(n+1) for i in range(n+1)]
dist2 = [[0]*(n) for i in range(n)]

objects = [list(map(float,input().split())) for i in range(n)] + [[xs,ys]] # objects[n] is handbag

for i in range(n+1):
    for j in range(n+1):
        dist[i][j] = (objects[i][0] - objects[j][0])**2 + (objects[i][1] - objects[j][1])**2

for i in range(n):
    for j in range(n):
        dist2[i][j] = dist[n][i] + dist[i][j] + dist[j][n]

dp = [1e6]*(1<<n)
vis = set([0]) #alot of states are not visited after optimization
dp[0] = 0

for i in range((1<<n)-1):
    if i in vis:
        # reduce O(n^2) transition to O(n) via assuming 1 of the objects taken must be the
        # first object not yet taken in order
        for j in range(n):
            if i&(1<<j) == 0:
                # get 1 new object
                newi = i + (1 << j)
                dp[newi] = min(dp[newi], dp[i] + 2*dist[n][j])
                vis.add(newi)

                for k in range(j+1,n):
                    # get 2 new objects at a time
                    if i&(1<<k) == 0:
                        newi |= 1<<k
                        dp[newi] = min(dp[newi], dp[i] + dist2[j][k])
                        vis.add(newi)
                        newi ^= 1<<k

                break

# retrieve path
curr = (1<<n) - 1
path = [0]
while curr:
    for i in range(n):
        if curr & (1<<i):
            # 1 object taken
            if dp[curr] == dp[curr - (1<<i)] + 2*dist[n][i]:
                path.extend([i+1,0])
                curr ^= (1<<i)

            # 2 objects taken
            for j in range(i+1,n):
                if curr & (1<<j):
                    if dp[curr] == dp[curr - (1<<i) - (1<<j)] + dist2[i][j]:
                        path.extend([j+1,i+1,0])
                        curr ^= (1<<i) + (1<<j)

print(int(dp[(1<<n)-1]))
print(*path[::-1])