import sys
input = sys.stdin.buffer.readline

mod = 998244353

n = int(input())

dp = [0]*(n+1)
dp_tot = [0]*(n+1)

all_same = [0]*(n+1)

for l in range(1,n+1):
    for lm in range(l,n+1,l):
        all_same[lm] += 1

for i in range(1,n+1):
    dp[i] = all_same[i] + dp_tot[i-1]

    dp_tot[i] = (dp[i] + dp_tot[i-1]) % mod

print(dp[n] % mod)


