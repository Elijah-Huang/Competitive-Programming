import sys
input = sys.stdin.readline

def prog():
    n = int(input())
    a = list(map(int,input().split()))

    tot = sum(a)
    ans = 0

    for i in a:
        ans += i*(tot-i)

    print(ans//2)

prog()
