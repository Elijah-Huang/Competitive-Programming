import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        t = list(map(int,input().split()))
        t.sort()
        
        ans = 10**9
        dp = [[10**9]*(2*n + 1) for i in range(n+1)]
        dp[0] = [0]*(2*n+1)
        for i in range(n):
            for time in range(1,2*n + 1):
                dp[i + 1][time] = min(dp[i + 1][time-1], dp[i][time-1] + abs(time-t[i]))

        print(dp[n][2*n])
prog()
