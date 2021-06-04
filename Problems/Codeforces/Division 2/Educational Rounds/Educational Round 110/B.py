import sys
input = sys.stdin.buffer.readline
from math import gcd

for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))

    b = []
    div_2 = [i%2 == 0 for i in a]

    for i in range(n):
        if div_2[i]:
            b.append(a[i])

    for i in range(n):
        if div_2[i] == 0:
            b.append(a[i])

    mx = 0
    for i in range(n):
        for j in range(i+1,n):
            if gcd(b[i],b[j]<<1) > 1:
                mx += 1

    print(mx)