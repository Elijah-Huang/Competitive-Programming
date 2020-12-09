import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')

for _ in range(int(input().strip())):
    n,m = map(int,input().split())
    if n == 1:
        print(0)
    elif n == 2:
        print(m)
    else:
        print(2*m)
