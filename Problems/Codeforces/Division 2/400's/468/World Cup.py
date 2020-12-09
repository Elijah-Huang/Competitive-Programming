import sys
from math import log
input = sys.stdin.readline
def prog():
    n,a,b = map(int,input().split())
    a -= 1
    b -= 1
    match = 0
    while a != b:
        a //= 2
        b //= 2
        match += 1
    if 1 << match == n:
        print('Final!')
    else:
        print(match)
prog()
