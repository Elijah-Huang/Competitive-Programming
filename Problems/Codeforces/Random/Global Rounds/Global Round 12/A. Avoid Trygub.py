import sys
input = sys.stdin.readline

def prog():
    for _ in range(int(input())):
        n = int(input())
        a = list(input().strip())
        a.sort()
        print(''.join(a))
prog()
