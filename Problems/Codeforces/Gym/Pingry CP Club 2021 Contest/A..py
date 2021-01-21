import sys
input = sys.stdin.readline

def prog():
    n = int(input())
    a = list(map(int,input().split()))
    print(min(a[:n//2]) + max(a[n//2:]))
prog()
