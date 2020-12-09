import sys
input = sys.stdin.readline
def prog():
    a = input().strip()
    for i in range(len(a)):
        if a[i] == '0':
            print(a[:i] + a[i+1:])
            return
    print(a[:-1])
prog()
