import sys
input = sys.stdin.readline

def prog():
    for _ in range(int(input())):
        n,m = map(int,input().split())
        c = [input().strip() for i in range(n)]
        dp = [[0]*(m+2) for i in range(n+1)]
        tot = 0
        
        for i in range(n-1,-1,-1):
            for j in range(m):
                if c[i][j] == '*':
                    dp[i][j+1] = 1 + min(dp[i+1][j],dp[i+1][j+1],dp[i+1][j+2])
                    
                tot += dp[i][j+1]

        print(tot)
prog()

        
                
