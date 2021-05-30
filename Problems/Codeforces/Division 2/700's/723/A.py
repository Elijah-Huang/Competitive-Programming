import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))

    a.sort()

    b = [0]*(2*n)

    for i in range(n):
        b[2*i] = a[i]

    for i in range(n):
        b[2*i+1] = a[2*n-1-i]

    print(*b)