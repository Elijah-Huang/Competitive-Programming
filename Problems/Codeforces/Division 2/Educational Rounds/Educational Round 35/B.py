import sys
input = sys.stdin.buffer.readline

n,a,b = map(int,input().split())

for x in range(1000,-1,-1):
    if a//x + b//x >= n and a//x >= 1 and b//x >= 1:
        print(x)
        exit()
