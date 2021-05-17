import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n,p,k = map(int,input().split())

    a = list(map(int,input().split())) + [0]
    a.sort()

    dp = [-1]*(n+1)
    dp[0] = p

    for i in range(n):
        if dp[i] >= a[i+1]:
            dp[i+1] = max(dp[i+1], dp[i] - a[i+1])
        if i + k <= n and dp[i] >= a[i+k]:
            dp[i+k] = max(dp[i+k], dp[i] - a[i+k])

    mx = 0
    for i in range(n,-1,-1):
        if dp[i] != -1:
            mx = i
            break

    print(mx)
