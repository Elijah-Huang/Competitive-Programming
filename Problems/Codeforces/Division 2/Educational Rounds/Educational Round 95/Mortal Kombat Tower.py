import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        if n == 1:
            print(sum(a))
            continue
        dp = [[10**6]*2 for i in range(n)]
        dp[0][0] = (a[0] == 1)
        dp[1][0] = (a[0] == 1) + (a[1] == 1)
        for i in range(n-1):
            for j in range(2):
                skips = 0
                p2 = (j + 1)%2
                for kills in range(1,3):
                    if i + kills >= n:
                        break
                    skips += a[i + kills]*(p2 == 0)
                    dp[i + kills][p2] = min(dp[i + kills][p2], skips + dp[i][j])
        print(min(dp[n-1][0], dp[n-1][1]))
prog()

