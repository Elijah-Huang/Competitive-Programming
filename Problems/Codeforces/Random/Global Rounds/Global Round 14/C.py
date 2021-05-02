import sys
input = sys.stdin.buffer.readline
from heapq import heappush, heappop

for _ in range(int(input())):
    n,m,x = map(int,input().split())

    h = list(map(int,input().split()))

    heap = [[0,i] for i in range(1,m+1)]
    indices = [0]*n

    for i in range(n):
        mn = heappop(heap)
        mn[0] += h[i]
        indices[i] = mn[1]
        heappush(heap,mn)

    print("YES")
    print(*indices)
