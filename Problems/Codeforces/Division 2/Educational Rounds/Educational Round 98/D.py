import sys
input = sys.stdin.readline
def prog():
    mod = 998244353
    n = int(input())
    
    pow2 = [1]*(n+1)
    for i in range(1,n+1):
        pow2[i] = (2*pow2[i-1])%mod
        
    numerator = 0
    for gap in range(1,(n-2)//2 + 1):
        numerator = (numerator + (gap + 1 + (n % 2 == 1))*pow2[n-(gap+2)])% mod

    print((numerator*(pow(pow(2,n,mod),mod-2,mod)))%mod)
    
prog()
