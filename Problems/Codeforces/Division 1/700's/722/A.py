import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n = int(input())

    a = [0] + [list(map(int,input().split())) for i in range(n)]

    adj = [[] for i in range(n+1)]

    for i in range(n-1):
        u,v = map(int,input().split())

        adj[u].append(v)
        adj[v].append(u)

    dp = [[0.0]*2 for i in range(n+1)]

    s = [1]
    vis = [0]*(n+1)
    done = [0]*(n+1)
    while s:
        c = s[-1]

        if not vis[c]:
            vis[c] = 1

            for ne in adj[c]:
                if not vis[ne]:
                    s.append(ne)
        else:
            for ne in adj[c]:
                if done[ne]:
                    dp[c][1] += max(dp[ne][0] + abs(a[c][1]-a[ne][0]), dp[ne][1] + abs(a[c][1]-a[ne][1]))
                    dp[c][0] += max(dp[ne][0] + abs(a[c][0]-a[ne][0]), dp[ne][1] + abs(a[c][0]-a[ne][1]))

            done[c] = 1
            s.pop()

    print(int(max(dp[1])))