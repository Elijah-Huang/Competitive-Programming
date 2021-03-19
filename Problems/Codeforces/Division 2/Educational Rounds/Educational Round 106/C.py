import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))

    ans = 10**18
    mn0 = 10**9
    tot0 = 0
    mn1 = 10**9
    tot1 = 0
    for i in range(n):
        if i % 2 == 0:
            mn0 = min(mn0, a[i])
            tot0 += a[i]
        else:
            mn1 = min(mn1,a[i])
            tot1 += a[i]

        if i > 0:
            ans = min(ans, tot0 + (n - (i+2)//2)*mn0  + tot1 + (n - (i+1)//2)*mn1)

    print(ans)
