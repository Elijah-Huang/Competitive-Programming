from math import ceil
import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        x,y,k = map(int,input().split())
        tot = (k*(y + 1) -1 + x - 2)//(x-1) + k
        print(tot)
prog()
