import sys
input = sys.stdin.buffer.readline
from heapq import heappush, heappop

def min_val(amt, parts):
    base = amt//parts
    extra = amt % parts
    return extra*(base + 1)**2 + (parts-extra)*(base)**2

def prog():
    n,k = map(int,input().split())
    a = list(map(int,input().split()))

    heap = []
    total_time = 0
    for length in a:
        total_time += length**2
        heappush(heap, [min_val(length, 2) - length**2, [length,2]])

    for i in range(k-n):
        curr = heappop(heap)
        total_time += curr[0]
        heappush(heap, [min_val(curr[1][0], curr[1][1] + 1) - min_val(curr[1][0],curr[1][1]), [curr[1][0],curr[1][1] +1]])
        
    print(total_time)
    
prog()
