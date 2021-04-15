import sys
input = sys.stdin.buffer.readline
from collections import Counter

for _ in range(int(input())):
    n = int(input())
    a = Counter(map(int,input().split()))
    print(a[1] + a[3])
