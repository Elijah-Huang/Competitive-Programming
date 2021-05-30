maxn = 10**5
mod = 10**9 + 7
fac = [0]*(maxn+1)
inv_fac = [0]*(maxn+1)

fac[0] = 1
for i in range(1,maxn+1):
    fac[i] = fac[i-1] * i % mod

inv_fac[maxn] = pow(fac[maxn],mod-2,mod)
for i in range(maxn-1,-1,-1):
    inv_fac[i] = inv_fac[i+1] * (i+1) % mod

def choose(n,k):
    if k > n:
        return 0
    return fac[n] * inv_fac[k] * inv_fac[n-k] % mod