from math import gcd
def lcm(a,b):
    return a*b//gcd(a,b)
import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def quic():
    for _ in range(int(input().strip())):
        a,b,q = map(int,input().split())
        period = lcm(a,b)
        maxx = max(a,b)
        for _ in range(q):
            l,r = map(int,input().split())
            total = r - l + 1
            total_bad = 0 
            bottom = (l // period) + 1
            top = r // period
            x = l % period
            y = r % period
            if top < bottom:
                total_bad += max(0,min(maxx,y+1) - x)
                total -= total_bad
                print(total)
            else:
                total_bad += (top - bottom) * maxx
                total_bad += min(maxx,y+1)
                total_bad += max(0,maxx - x)
                total -= total_bad
                print(total)
quic()
                
        
        
