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
        grid = [input().strip() for i in range(n)]
        rows = []
        row_perms = 2**m
        for i in range(row_perms):
            rows.append('0'*(m - len(bin(i)[2:])) + bin(i)[2:])

        curr = []
        mn_change = 200
        if n == 2:
            for i in range(row_perms):
                for j in range(row_perms):
                    grid2 = [rows[i], rows[j]]
                    fail = False
                    for c in range(m - 1):
                        if fail:
                            break
                        for r in range(n-1):
                            count = 0
                            for c2 in range(c, c+2):
                                for r2 in range(r, r + 2):
                                    count += grid2[r2][c2] == '1'
                            if count % 2 == 0:
                                fail = True
                                break
                    if not fail:
                        diff = 0
                        for i2 in range(n):
                            for j2 in range(m):
                                diff += grid[i2][j2] != grid2[i2][j2] 
                        mn_change = min(mn_change, diff)

                            
        elif n == 3:
            for i in range(row_perms):
                for j in range(row_perms):
                    for k in range(row_perms):
                        grid2 = [rows[i], rows[j], rows[k]]
                        fail = False
                        for c in range(m - 1):
                            if fail:
                                break
                            for r in range(n-1):
                                count = 0
                                for c2 in range(c, c+2):
                                    for r2 in range(r, r + 2):
                                        count += grid2[r2][c2] == '1'
                                if count % 2 == 0:
                                    fail = True
                                    break
                        if not fail:
                            diff = 0
                            for i2 in range(n):
                                for j2 in range(m):
                                    diff += grid[i2][j2] != grid2[i2][j2] 
                            mn_change = min(mn_change, diff)
        elif n == 4:
            for i in range(row_perms):
                for j in range(row_perms):
                    for k in range(row_perms):
                        for q in range(row_perms):
                            grid2 = [rows[i], rows[j], rows[k], rows[q]]
                            fail = False
                            for c in range(m - 1):
                                if fail:
                                    break
                                for r in range(n-1):
                                    count = 0
                                    for c2 in range(c, c+2):
                                        for r2 in range(r, r + 2):
                                            count += grid2[r2][c2] == '1'
                                    if count % 2 == 0:
                                        fail = True
                                        break
                            if not fail:
                                diff = 0
                                for i2 in range(n):
                                    for j2 in range(m):
                                        diff += grid[i2][j2] != grid2[i2][j2] 
                                mn_change = min(mn_change, diff)

        if mn_change == 200:
            print(-1)
        else:
            print(mn_change)
prog()
                
        
        
