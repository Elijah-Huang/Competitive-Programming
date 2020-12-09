import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    n = int(input())
    grid = [[0]*n for i in range(n)]
    curr = 1
    for i in range(1,n):
        for j in range(i+1):
            if j % 2 == 0:
                grid[i-j][j] = curr
            else:
                grid[i-j][j] = (curr << 1)
        curr <<= 2
    for j in range(n-1,0):
        for i in range(n-1,n-1-j-1):
            if i % 2 == 0:
                grid[i][n - j + (n-1-i)]
            else:
                grid[i][n - j + (n-1-i)]
        curr <<= 2
                
            
        

