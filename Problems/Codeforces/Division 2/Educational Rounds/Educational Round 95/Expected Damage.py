from bisect import bisect_left
import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
    
def prog():
    mod = 998244353
    n,m = map(int,input().split())
    d = list(map(int,input().split()))
    
    d.sort()
    dsum = [0]
    for i in d:
        dsum.append(dsum[-1] + i)

    for i in range(m):
        a,b = map(int,input().split())
        loc = bisect_left(d,b)
        if (n-loc) < a:
            print(0)
            continue
        ans = 0
        ans += (dsum[n] - dsum[loc]) * (n-loc-a) * pow((n-loc),mod-2,mod)
        ans += (dsum[loc]) * (n-loc-a+1) * pow((n-loc+1),mod-2,mod)
        print((ans % mod + mod) % mod)
        
prog()
        
