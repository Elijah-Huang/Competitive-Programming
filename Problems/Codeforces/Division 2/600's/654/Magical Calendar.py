import sys
input= sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        n,r = map(int,input().split())
        if n > r:
            print(r*(r+1)//2)
        else:
            print(n*(n-1)//2 +1)
prog()
