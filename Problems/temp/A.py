import sys
input = sys.stdin.buffer.readline

mod = 998244353

n,k = map(int,input().split())

dp = [[[0]*2 for j in range(n+1)] for i in range(n+1)] # [pos][mx][curr color]

dp[0][1][1] = dp[0][1][1] = 0
