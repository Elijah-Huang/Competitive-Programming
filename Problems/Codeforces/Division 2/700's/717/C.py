import sys
input = sys.stdin.buffer.readline
from math import gcd

n = int(input())
a = list(map(int,input().split()))

make = [0]*(n*2000+1)
make2 = [0]*(n*2000+1)
make[0] = 1
for i in a:
    for j in range(n*2000+1-i):
        make2[j+i] |= make[j]
        
    for j in range(n * 2000 + 1):
        make[j] |= make2[j]

tot = sum(a)
if tot % 2 == 0 and make[tot//2] == 1:
    g = 0
    for i in a:
        g = gcd(g,i)

    remove = 0
    for i in range(n):
        if a[i]//g % 2 == 1:
            remove = i+1

    print(1)
    print(remove)
else:
    print(0)