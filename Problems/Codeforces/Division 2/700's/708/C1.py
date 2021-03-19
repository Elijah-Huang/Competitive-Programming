import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n,k = map(int,input().split())

    b = 1
    while n % 2 == 0:
        n //= 2
        b *= 2

    if n == 1:
        b //= 4
        print(2*b,b,b)
    else:
        print(b*1,n//2 * b,n//2 * b)