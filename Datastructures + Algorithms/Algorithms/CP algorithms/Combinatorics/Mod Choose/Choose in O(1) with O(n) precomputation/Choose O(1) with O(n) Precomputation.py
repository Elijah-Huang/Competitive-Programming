mod = 10**9 + 7
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