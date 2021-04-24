import sys
input = sys.stdin.buffer.readline

n = int(input())

p = list(map(int,input().split()))

board = [[0]*i for i in range(1,n+1)]

for i in range(n):
    y = i; x = i
    for j in range(p[i]):
        board[y][x] = p[i]

        if x == 0 or board[y][x-1]:
            y += 1
        else:
            x -= 1


for row in board:
    print(*row)
