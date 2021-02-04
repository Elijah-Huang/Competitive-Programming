from math import gcd
import sys
input = sys.stdin.buffer.readline

def prog():
    for _ in range(int(input())):
        n,k = map(int,input().split())
        a = list(map(int,input().split()))
        a.sort()
        
        d = 0
        for i in range(n-1):
            d = gcd(d,a[i+1]-a[i])

        print("YES" if (k - a[0])%d == 0 else "NO")
    
prog()
