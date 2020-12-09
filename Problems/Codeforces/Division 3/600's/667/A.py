import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        a,b = map(int,input().split())
        if a == b:
            print(0)
        else:
            if a < b:
                a,b = b,a
            print((a - b + 9) // 10)
prog()
