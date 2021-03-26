import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n,m,x = map(int,input().split())
    c,r = x//n + 1, x%n
    if r == 0:
        c -= 1
        r = n

    print((r-1)*m + c)



