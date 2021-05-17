import sys
input = sys.stdin.buffer.readline
from math import gcd

for _ in range(int(input())):
    k = int(input())
    a = gcd(k,100)
    print(100//a)