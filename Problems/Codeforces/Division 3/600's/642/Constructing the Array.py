import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(val + '\n')

from heapq import heappush, heappop
for _ in range(int(input().strip())):
    n = int(input().strip())
    zeros = [[n-1,0,n-1]]
    array = [0 for i in range(n)]
    for i in range(1,n+1):
        length , l, r = heappop(zeros)
        index = (r+l)//2
        array[index] = i
        if r != l:
            if r == l + 1:
                heappush(zeros,[-1,r,r])
            else:
                heappush(zeros,[-(index-l),l,index-1])
                heappush(zeros, [-(r-index),index+1,r])
    print(" ".join(map(str,array)))
