import sys
input = sys.stdin.readline
sys.setrecursionlimit = 10**4

def dfs(visited,curr,maze,n,m):
    visited.add(curr)
    i,j = curr
    neighbors = [(i-1,j),(i+1,j),(i,j-1),(i,j+1)]
    for i1, j1 in neighbors:
        new = (i1,j1)
        if 0 <= i1 < n and 0 <= j1 < m and maze[i1][j1] != '#' and new not in visited:
            dfs(visited,new,maze,n,m)
                
def prog():
    for _ in range(int(input())):
        n,m = map(int,input().split())
        maze = [list(input().strip()) for i in range(n)]
        good = []
        bad = []
        for i in range(n):
            for j in range(m):
                if maze[i][j] == 'B':
                    bad.append((i,j))
                elif maze[i][j] == 'G':
                    good.append((i,j))
        if maze[n-1][m-1] != 'B' and len(good) == 0:
            print('Yes')
        elif maze[n-1][m-1] == '#' or maze[n-1][m-1] == 'B':
            print('No')
        else:
            failed = False
            for i,j in bad:
                blocks = [(i-1,j),(i+1,j),(i,j-1),(i,j+1)]
                for i1, j1 in blocks:
                    if 0 <= i1 < n and 0 <= j1 < m:
                        if maze[i1][j1] == 'G':
                            failed = True
                            break
                        elif maze[i1][j1] != 'B':
                            maze[i1][j1] = '#'
                if failed:
                    break
            if failed:
                print('No')
            else:
                '''
                for i,j in good:
                    blocks = [(i-1,j),(i+1,j),(i,j-1),(i,j+1)]
                    blocked_off = True
                    for i1, j1 in blocks:
                        if 0 <= i1 < n and 0 <= j1 < m:
                            if maze[i1][j1] != '#':
                                blocked_off = False
                                break
                    if blocked_off:
                        break
                if blocked_off:
                    print('No')
                '''
                visited = set()
                dfs(visited,good[0],maze,n,m)
                failed = False
                for a in good:
                    if a not in visited:
                        failed = True
                        break
                if (n-1,m-1) not in visited:
                    failed = True
                if failed:
                    print('No')
                else:
                    print('Yes')
prog()
            
    
