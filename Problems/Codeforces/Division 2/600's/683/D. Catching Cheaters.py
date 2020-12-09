import sys
input = sys.stdin.readline

def prog():
    n,m = map(int,input().split())
    a = input().strip()
    b = input().strip()
    dp = [[0]*(m+1) for i in range(n+1)]
    lst = -10**6
    start = [[lst]*(m+1) for i in range(n+1)]
    mx = 0
    
    for i in range(1,n+1):
        for j in range(1,m+1):
            if a[i-1] == b[j-1]:
                if 4*(dp[i-1][j-1]+1) - (i+j-start[i-1][j-1]) < 0:
                    dp[i][j] = 1
                    start[i][j] = i + j - 2
                else:
                    dp[i][j] = dp[i-1][j-1]+1
                    start[i][j] = start[i-1][j-1]
            else:
                first = 4*(dp[i-1][j]) - (i+j-start[i-1][j])
                second = 4*(dp[i][j-1]) - (i+j-start[i][j-1])
                if first > second:
                    if first < 0:
                        dp[i][j] = lst
                        start[i][j] = i + j - 2
                    else:
                        dp[i][j] = dp[i-1][j]
                        start[i][j] = start[i-1][j]
                else:
                    if second < 0:
                        dp[i][j] = lst
                        start[i][j] = i + j - 2
                    else:
                        dp[i][j] = dp[i][j-1]
                        start[i][j] = start[i][j-1]

            mx = max(mx, 4*(dp[i][j]) - (i + j - start[i][j]))
            
    print(mx)
        
prog()
        
