import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n,m,k = map(int,input().split())

    dp = [[10**9]*(m+1) for i in range(n+1)]

    dp[1][1] = 0
    for i in range(1,n+1):
        for j in range(1,m+1):
            if i == j and j == 1:
                continue
            dp[i][j] = min(dp[i-1][j] + j, dp[i][j-1] + i)

    mn = dp[n][m]

    dp = [[-10 ** 9] * (m + 1) for i in range(n + 1)]

    dp[1][1] = 0
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if i == j and j == 1:
                continue
            dp[i][j] = max(dp[i - 1][j] + j, dp[i][j - 1] + i)

    mx = dp[n][m]

    if mn <= k <= mx:
        print("YES")
    else:
        print("NO")
