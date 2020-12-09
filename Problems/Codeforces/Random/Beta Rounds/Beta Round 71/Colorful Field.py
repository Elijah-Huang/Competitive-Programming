import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    n,m,k,t = map(int,input().split())
    grid = [[0]*m for i in range(n)]
    for i in range(k):
        a,b = map(int,input().split())
        a -= 1
        b -= 1
        grid[a][b] = 'Waste'
        
    place = ['Carrots','Kiwis','Grapes']
    curr = 0
    for i in range(n):
        for j in range(m):
            if grid[i][j] != 'Waste':
                grid[i][j] = place[curr]
                curr = (curr + 1) % 3
                
    for i in range(t):
        a,b = map(int,input().split())
        a -= 1
        b -= 1
        print(grid[a][b])
prog()
