import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))

    s = sum(a)
    mx = s % n

    print(mx*(n-mx))