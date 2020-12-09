from math import inf
import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    n,m = map(int,input().split())
    if n >= 4 and m >= 4:
        print(-1)
    elif n == 1 or m == 1:
        print(0)
    else:
        grid = [list(input().strip()) for i in range(n)]
        if m < n:
            grid2 = [[0]*n for i in range(m)]
            for i in range(n):
                for j in range(m):
                    grid2[j][i] = grid[i][j]
            m,n = n,m
            grid = grid2

        num_masks = 2**n
        masks = []
        for i in range(num_masks):
            masks.append(bin(i)[:1:-1] + '0'*(n - len(bin(i)[:1:-1])))
            
        if n == 2:
            works = {0:(1,2), 1:(0,3), 2:(0,3), 3:(1,2)}
        elif n == 3:
            works = {0:(5,2), 1:(3,4), 2:(0,7), 3:(1,6),
                     4:(1,6), 5:(0,7), 6:(3,4), 7:(5,2)}
        
        dp = [[inf]*num_masks for _ in range(m)]    
        for i in range(num_masks):
            dp[0][i] = 0
            for j in range(n):
                dp[0][i] += grid[j][0] != masks[i][j]

        for i in range(1,m):
            for mask in range(num_masks):
                diff = 0
                for j in range(n):
                    diff += grid[j][i] != masks[mask][j]
                for prev_mask in works[mask]:
                    dp[i][mask] = min(dp[i][mask], dp[i-1][prev_mask] + diff)

        mn_change = inf
        for mask in range(num_masks):
            mn_change = min(mn_change, dp[m-1][mask])
        print(mn_change)

prog()
                
        
        
