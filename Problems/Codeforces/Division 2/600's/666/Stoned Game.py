import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(val + '\n')
def prog():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        mx = max(a)
        s = sum(a)
        if mx > s//2:
            print('T')
        else:
            if s % 2 == 0:
                print('HL')
            else:
                print('T')
prog()
