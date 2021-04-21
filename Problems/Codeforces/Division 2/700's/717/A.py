import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n,k = map(int,input().split())
    a = list(map(int,input().split()))
    b = []

    add = 0
    for i in range(n):
        while k and a[i]:
            a[i] -= 1
            k -= 1
            add += 1

    a[-1] += add

    print(*a)