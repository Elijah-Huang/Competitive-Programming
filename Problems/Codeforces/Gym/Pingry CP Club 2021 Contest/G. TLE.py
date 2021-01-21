import sys
input = sys.stdin.readline

def prog():
    n,k = map(int,input().split())
    p = sorted([list(map(int,input().split())) for i in range(n)])
    dp = [[-10**11]*(k+1) for i in range(n)]
    ans = 0
    
    for i in range(n):
        dp[i][1] = 0
        
    for i in range(n):
        for j in range(1,k):
            for i2 in range(i+1,n):
                dp[i2][j+1] = max(dp[i2][j+1], dp[i][j] + abs(p[i][0]-p[i2][0]) + abs(p[i][1]-p[i2][1]))
            
    for i in range(n):
        for j in range(1,k+1):
            ans = max(ans,dp[i][j])

    print(ans)

prog()
