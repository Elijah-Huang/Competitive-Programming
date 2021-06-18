import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n = int(input())
    h = list(map(int,input().split()))

    h.sort()

    idx = 0
    mn = 1e10
    for i in range(n-1):
        if h[i+1]-h[i] < mn:
            mn = h[i+1] - h[i]
            idx = i

    print(h[idx],*h[idx+2:],*h[:idx],h[idx+1])