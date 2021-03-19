import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    delta = [0] * (n+1)
    active = 0
    drenched = [0]*n

    for i in range(n):
        if a[i]:
            pos = i-a[i]+1
            if pos >= 0:
                delta[pos] += 1
            else:
                active += 1

            delta[i+1]  -= 1

    for i in range(n):
        active += delta[i]
        if active:
            drenched[i] = 1

    print(*drenched)