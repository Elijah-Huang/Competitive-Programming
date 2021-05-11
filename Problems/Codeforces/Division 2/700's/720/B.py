import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))

    x = min(a)
    i = a.index(x)

    swapped = 0
    if i != 0:
        print(n)
        print(1,i+1,x,x+i)
        swapped = 1

    if not swapped:
        print(n-1)

    for i in range(2,n+1):
        print(1,i,x,x+i-1)