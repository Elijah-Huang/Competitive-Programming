def prog():
    n,k,d = map(int,input().split())
    mod = 10**9 + 7
    ways = [0 for i in range(n+1)]
    for i in range(1,min(k+1,n+1)):
        ways[i] = 1
    for i in range(1,n+1):
        for j in range(max(1,i-k),i):
            ways[i] += ways[j]
    ways_less_d = [0 for i in range(n+1)]
    k = d -1 
    for i in range(1,min(k+1,n+1)):
        ways_less_d[i] = 1
    for i in range(1,n+1):
        for j in range(max(1,i-k),i):
            ways_less_d[i] += ways_less_d[j]
    print((ways[n] - ways_less_d[n]) % mod)
prog()
