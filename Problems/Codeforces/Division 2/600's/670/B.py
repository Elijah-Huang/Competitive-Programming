import sys
input= sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        dp = [[[0]*2 for i in range(6)] for i in range(n + 1)]
        dp[0][0][0] = 1
        for i in range(1,n+1):
            for j in range(6):
                dp[i][j][0] = dp[i-1][j][0]
                dp[i][j][1] = dp[i-1][j][1]
                if j:
                    if a[i-1] < 0:
                        dp[i][j][0] = max(dp[i][j][0], -dp[i-1][j-1][1]*a[i-1])
                        dp[i][j][1] = max(dp[i][j][1], -dp[i-1][j-1][0]*a[i-1])
                    else:
                        dp[i][j][1] = max(dp[i][j][1], dp[i-1][j-1][1]*a[i-1])
                        dp[i][j][0] = max(dp[i][j][0], dp[i-1][j-1][0]*a[i-1])

        
        dp2 = [[[10**18]*2 for i in range(6)] for i in range(n + 1)]
        dp2[0][0][0] = 1
        for i in range(1,n+1):
            for j in range(6):
                dp2[i][j][0] = dp2[i-1][j][0]
                dp2[i][j][1] = dp2[i-1][j][1]
                if j:
                    if a[i-1] < 0:
                        dp2[i][j][0] = min(dp2[i][j][0], -dp2[i-1][j-1][1]*a[i-1])
                        dp2[i][j][1] = min(dp2[i][j][1], -dp2[i-1][j-1][0]*a[i-1])
                    else:
                        dp2[i][j][1] = min(dp2[i][j][1], dp2[i-1][j-1][1]*a[i-1])
                        dp2[i][j][0] = min(dp2[i][j][0], dp2[i-1][j-1][0]*a[i-1])
        in_a = (0 in a)
        if in_a:
            print(dp[n][5][0])
        else:
            if dp[n][5][0] == 0:
                print(-dp2[n][5][1])
            else:
                print(dp[n][5][0])
prog()

