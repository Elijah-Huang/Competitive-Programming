import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
for _ in range(int(input())):
    n,m  = map(int,input().split())
    print((n*m+1)//2)
