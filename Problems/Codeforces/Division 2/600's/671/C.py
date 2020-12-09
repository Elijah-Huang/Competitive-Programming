import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        n,x = map(int,input().split())
        a = list(map(int,input().split()))
        fail = False
        had_one = False
        for i in range(n):
            if a[i] != x:
                fail = True
                break
        for i in range(n):
            if a[i] == x:
                had_one = True
        if not fail:
            print(0)
        else:
            s = sum(a)
            if s == x*n or had_one:
                print(1)
            else:
                print(2)
prog()
