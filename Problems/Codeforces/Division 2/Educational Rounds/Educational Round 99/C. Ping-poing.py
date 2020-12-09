import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        x,y = map(int,input().split())
        print(x-1,y)
prog()
