import sys
from math import ceil
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    n,k = map(int,input().split())
    a = list(map(int,input().split()))
    used = 0
    for i in range(len(a)):
        if a[i] == 0:
            continue
        used += ceil(a[i]/k)
        if a[i] % k > 0:
            leftover = k - a[i] % k
        else:
            leftover = 0
        if i < len(a) -1:
            a[i+1] = max(0, a[i+1] - leftover)
    print(used)
prog()
