import sys
input = sys.stdin.readline
def prog():
    n,h = map(int,input().split())
    for i in range(1,n):
        print(h/(n/i)**0.5)
prog()
