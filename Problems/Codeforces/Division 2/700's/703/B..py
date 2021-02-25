import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n = int(input())
    p = [list(map(int,input().split())) for i in range(n)]
    x = sorted([p[i][0] for i in range(n)])
    y = sorted([p[i][1] for i in range(n)])

    pos_x = 1 if n % 2 == 1 else x[n//2] - x[n//2-1]+1
    pos_y = 1 if n % 2 == 1 else y[n//2] - y[n//2-1]+1

    print(pos_x*pos_y)
