import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
    
def prog():
    mod = 10**9 + 7
    n,m,k = map(int,input().split())
    grid = [[0]*(m + 1) for i in range(n + 1)]
    for i in range(k):
        a,b = map(int,input().split())
        grid[a][b] = -1
    if grid[1][1] == -1:
        print(0)
        return
    grid[1][1] = 1
    for i in range(1,n + 1):
        for j in range(1,m + 1):
            if grid[i][j] != -1:
                grid[i][j] = (grid[i][j] + max(0, grid[i-1][j]) + max(0,grid[i][j-1])) % mod

    print(max(0,grid[n][m]))
prog()
    
