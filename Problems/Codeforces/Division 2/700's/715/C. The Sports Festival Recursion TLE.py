# Fails because overhead form recursion is too high
import sys
input = sys.stdin.buffer.readline

def solve(l,r):
    if dp[l][r] != -1:
        return dp[l][r]

    if l == r:
        dp[l][r] = 0
        return 0

    dp[l][r] = s[r] - s[l] + min(solve(l+1,r), solve(l,r-1))

    return dp[l][r]


n = int(input())

s = list(map(int,input().split()))
s.sort()

dp = [[-1]*n for i in range(n)]

solve(0,n-1)

print(dp[0][n-1])