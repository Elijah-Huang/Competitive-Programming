import sys
input = sys.stdin.readline
def prog():
    n = int(input())
    s = input().strip()
    if len(s) > 26:
        print(-1)
    else:
        a = set(s)
        print(len(s)-len(a))
prog()
