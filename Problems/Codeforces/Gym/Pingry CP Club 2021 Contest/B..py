import sys
input = sys.stdin.readline
from collections import Counter

def prog():
    n = int(input())
    s = Counter(input().strip())
    tot = 0

    for i in s.values():
        tot += i*(i+1)//2

    print(tot)
prog()
