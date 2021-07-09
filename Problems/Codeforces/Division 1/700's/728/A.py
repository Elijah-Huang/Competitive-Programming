import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n = int(input())
    d = list(map(int,input().split()))

    d.sort()

    mn = d[-1]
    tot = 0
    for i in range(n):
        mn += tot - i*d[i]

        tot += d[i]

    print(mn)