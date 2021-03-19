import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n,m = map(int,input().split())
    a = list(map(int,input().split()))

    tried =[0]*m
    counts = [0]*m
    for i in range(n):
        counts[a[i]%m] += 1

    mn = 0
    for i in range(m):
        a = counts[i]
        b = counts[(m-i)%m]

        if tried[i] or (a == b and a == 0):
            continue
        tried[i] = tried[(m-i)%m] = 1

        if i == (m-i)%m:
            mn += 1
        else:
            if a < b:
                a,b = b,a
            a = max(0, a - (b+1))
            mn += 1 + a

    print(mn)