import sys
input = sys.stdin.buffer.readline
from math import ceil
def prog():
    n,a,b,k = map(int,input().split())
    healths = list(map(int,input().split()))
    skips = []
    for health in healths:
        left = health % (a+b)
        if left == 0:
            left = a+b
        left -= a
        skips.append(ceil(left/a))
    skips.sort()
    points = 0
    skips_left = k
    for skip in skips:
        k -= skip
        if k >= 0:
            points += 1
        else:
            break
    print(points)
prog()
