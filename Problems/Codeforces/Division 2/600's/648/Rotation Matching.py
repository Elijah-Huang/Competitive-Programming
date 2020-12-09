import sys
from collections import Counter
input = sys.stdin.buffer.readline
def prog():
    n = int(input())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    index_diff = [0 for i in range(n+1)]
    for i in range(n):
        index_diff[b[i]] = i
    for i in range(n):
        num = a[i]
        index_diff[num] = (index_diff[num] - i) % n
    totals = Counter(index_diff[1:])
    print(max(totals.values()))
prog()
