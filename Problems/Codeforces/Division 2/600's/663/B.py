import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        n,m = map(int,input().split())
        grid = [input().strip() for i in range(n)]
        change = 0
        for j in range(m):
            if grid[n-1][j] == 'D':
                change += 1
        for i in range(n):
            if grid[i][m-1] == 'R':
                change += 1
        print(change)
prog()
