import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        l,r = map(int,input().split())
        if r < 2*l:
            print("YES")
        else:
            print("NO")
prog()
