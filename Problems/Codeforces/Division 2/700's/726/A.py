import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))

    tot = sum(a)

    if tot == n:
        print(0)
    elif tot < n:
        print(1)
    else:
        print(tot-n)