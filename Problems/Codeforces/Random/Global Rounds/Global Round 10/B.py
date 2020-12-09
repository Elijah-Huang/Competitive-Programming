import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        n,k = map(int,input().split())
        a = list(map(int,input().split()))
        a2 = [0]*n
        mx = max(a)
        for i in range(n):
            a[i] = mx - a[i]
        mx = max(a)
        for i in range(n):
            a2[i] = mx - a[i]
        if k % 2 == 0:
            print(' '.join(map(str, a2)))
        else:
            print(' '.join(map(str, a)))
prog()
