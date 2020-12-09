import sys
input = sys.stdin.buffer.readline
def prog():
    mod = 10**9 + 7
    dp = [0]*(2*10**6+1)
    dp[3] = 1
    for i in range(4,2*10**6 + 1):
        dp[i] = (dp[i-1] + 2*dp[i-2] + (i % 3 == 0)) % mod
    for _ in range(int(input())):
        n = int(input())
        sys.stdout.write(str(4*dp[n]%mod) + '\n')
prog()
