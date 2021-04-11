import sys

input = sys.stdin.buffer.readline

mod = 10**9 + 7

for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))

    mn = min(a)
    tot_and = a[0]
    for i in range(1,n):
        tot_and &= a[i]
    mn_count = 0
    for i in a:
        if i == mn:
            mn_count += 1

    if tot_and != mn or mn_count == 1:
        print(0)
    else:
        fact = [1]*n
        for i in range(2,n):
            fact[i] = (fact[i-1]*i)%mod

        print((mn_count*(mn_count-1)*fact[n-2])%mod)