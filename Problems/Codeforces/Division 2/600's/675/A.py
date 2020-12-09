import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        a = list(map(int,input().split()))
        print(sum(a) - 1)
prog()
