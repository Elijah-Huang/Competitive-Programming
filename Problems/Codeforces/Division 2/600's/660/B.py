import sys
from math import ceil
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(val + '\n')
def prog():
    for _ in range(int(input())):
        n = int(input())
        culled = ceil(n/4)
        print('9'*(n - culled) + '8'*culled)
prog()
