import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
sys.setrecursionlimit = 5000
def dfs(node,visited,matrix,n):
    visited.add(node)
    neighbors = []
    i,j = node
    #if (i,j+1) not in visited and (0 <= j+1 <= n-1) and matrix[i][j+1] == '1':
        #neighbors.append((i,j+1))
    if (i,j-1) not in visited and (0 <= j-1 <= n-1) and matrix[i][j-1] == '1':
        neighbors.append((i,j-1))
    #if (i+1,j) not in visited and (0 <= i+1 <= n-1) and matrix[i+1][j] == '1':
        #neighbors.append((i+1,j))
    if (i-1,j) not in visited and (0 <= i-1 <= n-1) and matrix[i-1][j] == '1':
        neighbors.append((i-1,j))
    for neighbor in neighbors:
        dfs(neighbor,visited,matrix,n)
    
def prog():
    for _ in range(int(input().strip())):
        n = int(input().strip())
        matrix = [input().strip() for i in range(n)]
        ones = 0 
        for row in matrix:
            for c in row:
                if c == '1':
                    ones += 1
        visited = set()
        for j in range(n):
            if matrix[n-1][j] == '1':
                start = (n-1,j)
                dfs(start,visited,matrix,n)
        for i in range(n-1):
            if matrix[i][n-1] == '1':
                start = (i,n-1)
                dfs(start,visited,matrix,n)
        if len(visited) == ones:
            print('YES')
        else:
            print('NO')
prog()
            
