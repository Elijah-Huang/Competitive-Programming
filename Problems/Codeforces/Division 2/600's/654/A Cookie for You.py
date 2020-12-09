import sys
input= sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(val + '\n')
def prog():
    for _ in range(int(input())):
        a,b,n,m = map(int,input().split())
        if n+m > a+b:
            print('No')
        else:
            if min(a,b) < m:
                print('No')
            else:
                print('Yes')
prog()
