from math import gcd
import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))

    if n < 3:
        print(0)
    else:
        # all c % m
        diff = [a[i] - a[i-1] for i in range(1,n)]
        # all 0 % m so gcd is largest value of m unless = 0 then any value of m works
        diff2 = [diff[i]-diff[i-1] for i in range(1,n-1)]

        m = 0
        for i in diff2:
            m = gcd(m,i)

        # edge case
        if m == 0:
            print(0)
            continue

        c = (m+diff[0]%m)%m

        # now that we found m and c generate the seq
        gen_a = [a[0]%m] # if a[0] < m nothing happens otherwise it fails a == gen_a later
        for i in range(n-1):
            gen_a.append((gen_a[-1] + c)%m)

        if gen_a == a:
            print(m,c)
        else:
            print(-1)