import sys
input = sys.stdin.buffer.readline

n,m = map(int,input().split())
mod = m


fac = [0]*(n+1)
inv_fac = [0]*(n+1)

fac[0] = 1
for i in range(1,n+1):
    fac[i] = fac[i-1] * i % mod

inv_fac[n] = pow(fac[n],mod-2,mod)
for i in range(n-1,-1,-1):
    inv_fac[i] = inv_fac[i+1] * (i+1) % mod

def choose(n,k):
    return fac[n] * inv_fac[k] * inv_fac[n-k] % mod


pow2 = [0]*(n+1)
pow2[0] = 1
for i in range(1,n+1):
    pow2[i] = pow2[i-1] * 2 % mod


dp = [[0]*(n+1) for i in range(n+2)]

dp[0][0] = 1
for i in range(n):
    for j in range(0,i+1):
        for i2 in range(i+2,n+2):
            added = i2-i-1
            dp[i2][j + added] = (dp[i2][j + added] + dp[i][j]*choose(j+added,added)*pow2[added-1]) % mod

print(sum(dp[n+1]) % mod)