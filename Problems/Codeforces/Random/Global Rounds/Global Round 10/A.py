from collections import Counter
import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        n = int(input())
        a = Counter(map(int,input().split()))
        if len(a) > 1:
            print(1)
        else:
            print(n)
prog()
