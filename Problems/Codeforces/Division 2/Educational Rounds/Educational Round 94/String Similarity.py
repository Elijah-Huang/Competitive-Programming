import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(val + '\n')
def prog():
    for _ in range(int(input())):
        n = int(input())
        s = input().strip()
        print(s[n-1]*n)
prog()
