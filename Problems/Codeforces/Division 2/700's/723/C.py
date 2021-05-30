import sys
input = sys.stdin.buffer.readline
from heapq import heappop, heappush

n = int(input())

a = list(map(int,input().split()))

drunk = 0
heap = []
psum = 0

for i in a:
    if i >= 0:
        drunk += 1
        psum += i
    else:
        if psum + i < 0:
            if heap and i > heap[0]:
                psum -= heappop(heap)
                heappush(heap, i)
                psum += i
        else:
            drunk += 1
            heappush(heap, i)
            psum += i

print(drunk)