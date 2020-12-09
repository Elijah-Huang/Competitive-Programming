import sys
input = sys.stdin.readline
from math import sqrt
from collections import Counter
def factor_pairs(k):
    pairs = []
    for i in range(1,int(sqrt(k)) + 1):
        if k % i == 0:
            pairs.append([i,k//i])
    length = len(pairs)
    if int(sqrt(k)) != sqrt(k):
        pairs.append(pairs[-1][::-1])
    for i in range(length-2,-1,-1):
        pairs.append(pairs[i][::-1])
    return pairs
def prog():
    n,m,k = map(int,input().split())
    a = "".join(input().split())
    b = "".join(input().split())
    pairs = factor_pairs(k)
    w_vals = Counter(map(len,a.split('0')))
    l_vals = Counter(map(len,b.split('0')))
    subrectangles = 0
    for width in w_vals:
        for length in l_vals:
            for x,y in pairs:
                if x > width:
                    break
                elif y <= length:
                    subrectangles += w_vals[width]*l_vals[length]*(width-x+1)*(length-y+1)
    print(subrectangles)
prog()
