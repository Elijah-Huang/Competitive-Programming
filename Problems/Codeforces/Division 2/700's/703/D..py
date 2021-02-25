import sys
input = sys.stdin.buffer.readline
from collections import deque

def test(a, m):
    b = [1 if a[i] >= m else -1 for i in range(n)]
    # min_queue
    valid_prefixes = deque()
    mx_sum = 0

    psum = [0]*(n+1)
    for i in range(n):
        psum[i+1] = psum[i] + b[i]
        if i+1 >= k:
            while valid_prefixes and valid_prefixes[-1] > psum[i+1-k]:
                valid_prefixes.pop()
            valid_prefixes.append(psum[i+1-k])

            mx_sum = max(mx_sum, psum[i+1] - valid_prefixes[0])

    return mx_sum > 0


n,k = map(int,input().split())
a = list(map(int, input().split()))

l = 0; r = n
while l != r:
    m = (l+r+1)//2

    if test(a, m):
        l = m
    else:
        r = m-1

print(l)