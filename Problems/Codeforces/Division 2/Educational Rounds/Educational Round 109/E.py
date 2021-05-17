# O(n^2*m)
import sys
input = sys.stdin.buffer.readline

mod = 998244353

ans = 0

n,m = map(int,input().split())

fact = 1
for i in range(2,n+1):
    fact = fact * i  % mod
inv_fact = pow(fact,mod-2,mod)

dist = [list(map(int,input().split())) for i in range(n)]

# find expected value of each point (LOE)
for point in range(m):
    # if built at or after this time the point will not be conquered by that city
    time = [n+1 - dist[city][point] + 1 for city in range(n)]

    add = [0] * (n + 2)
    for i in time:
        add[i] += 1

    # of ways to place monuments so that they will not conquer the city
    dp = [[0]*(n+1) for i in range(n+2)] # dp[time][to place (at curr time)]

    dp[0][0] = 1

    for t in range(n+1):
        for to_place in range(n+1):
            if dp[t][to_place]:
                # don't place monument
                dp[t+1][to_place+add[t+1]] = (dp[t+1][to_place+add[t+1]] + dp[t][to_place]) % mod
                # place monument
                if to_place:
                    dp[t+1][to_place-1+add[t+1]] = (dp[t+1][to_place-1+add[t+1]] + to_place*dp[t][to_place]) % mod

    ans = (ans + (fact - dp[n+1][0])*inv_fact) % mod

print(ans)