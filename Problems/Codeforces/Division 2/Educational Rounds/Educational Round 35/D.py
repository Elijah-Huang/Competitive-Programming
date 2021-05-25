import sys
input = sys.stdin.buffer.readline

n = int(input())
a = list(map(int,input().split()))

parity = 0
for i in range(n):
    for j in range(i+1,n):
        if a[j] < a[i]:
            parity ^= 1

m = int(input())
for i in range(m):
    l,r = map(int,input().split())

    dist = (r-l+1)
    pairs = (dist-1)*(dist)//2

    if pairs & 1:
        parity ^= 1

    if parity:
        print("odd")
    else:
        print("even")