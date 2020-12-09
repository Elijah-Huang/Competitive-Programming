def choose(n,k,factorial,ifactorial):
    return (factorial[n]*ifactorial[n-k]*ifactorial[k]) % 998244353
def prog():
    n,k = map(int,input().split())
    factorial = [1]
    for i in range(1,n+1):
        factorial.append((factorial[-1]*i) % 998244353)
    ifactorial = [1 for i in range(n+1)]
    curr = pow(factorial[n],998244353-2,998244353)
    for i in range(n,0,-1):
        ifactorial[i] = curr
        curr = (curr*i) % 998244353
    tot_stable = 0 
    for smallest in range(1,int(n/k)+1):
        tot_stable += choose(n//smallest -1, k-1,factorial,ifactorial)
    print(tot_stable % 998244353)
prog()
