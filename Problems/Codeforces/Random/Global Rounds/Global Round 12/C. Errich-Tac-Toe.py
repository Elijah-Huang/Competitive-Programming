import sys
input = sys.stdin.readline

def prog():
    for _ in range(int(input())):
        n = int(input())
        k = 0
        grid = [list(input().strip()) for i in range(n)]
        locs = [[[],[]] for i in range(3)]

        for i in range(n):
            for j in range(n):
                if grid[i][j] == 'O':
                    locs[(i+j)%3][0].append([i,j])
                    k+=1
                elif grid[i][j] == 'X':
                    locs[(i+j)%3][1].append([i,j])
                    k+=1

        found = False
        for i in range(3):
            for j in range(3):
                if i == j:
                    continue
                if len(locs[i][0]) + len(locs[j][1]) <= k//3:
                    for loc in locs[i][0]:
                        grid[loc[0]][loc[1]] = 'X'
                    for loc in locs[j][1]:
                        grid[loc[0]][loc[1]] = 'O'
                    found = True
                    break
            if found:
                break

        for row in grid:
            print(''.join(row))

prog()
                    
