import sys
input = sys.stdin.buffer.readline
from bisect import bisect_left
def prog():
    n = int(input())
    array = list(map(int,input().split()))
    psum = [0]
    for i in range(n):
        psum.append(psum[-1] + array[i])
    occurences = {}
    for i in range(n+1):
        if psum[i] in occurences:
            occurences[psum[i]].append(i)
        else:
            occurences[psum[i]] = [i]
    for a in occurences.values():
        a.sort()
    left = 0
    total_good = 0
    for right in range(1,n+1):
        total = psum[right]
        closest = bisect_left(occurences[total],right) - 1
        if closest != -1:
            new_left = occurences[total][closest] + 1
            left = max(new_left,left)
        total_good += right - left
    print(total_good)
prog()
    
