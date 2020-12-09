import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        x,y = map(int,input().split())
        print((x+y) + (max(0,max(x,y)-1-min(x,y))))
prog()
