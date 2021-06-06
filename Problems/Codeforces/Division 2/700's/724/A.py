import sys
input = sys.stdin.buffer.readline
from math import gcd

for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))

    if min(a) < 0:
        print("NO")
        continue

    g = 0
    for i in a:
        g = gcd(i,g)

    b = max(a)//g

    if b+(min(a)==0) <= 300:
        final = [i*g for i in range(1,b+1)]

        if min(a) == 0:
            final.append(0)

        print("YES")
        print(len(final))
        print(*final)
    else:
        print("NO")


