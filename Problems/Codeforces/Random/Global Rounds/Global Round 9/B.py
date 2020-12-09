import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(val + '\n')
def prog():
    for _ in range(int(input())):
        n,m = map(int,input().split())
        matrix = [list(map(int,input().split())) for i in range(n)]
        fail = False
        if matrix[0][0] == 3 or matrix[n-1][0] == 3 or matrix[0][m-1] == 3 or\
                                                 matrix[n-1][m-1] == 3:
            fail = True
        for i in range(m):
            if fail:
                break
            if matrix[0][i] == 4 or matrix[n-1][i] == 4:
                fail = True
                break
        for i in range(n):
            if fail:
                break
            if matrix[i][0] == 4 or matrix[i][m-1] == 4:
                fail = True
                break
        for i in range(n):
            if fail:
                break
            for j in range(m):
                if matrix[i][j] > 4:
                    fail = True
                    break
        if fail:
            print('NO')
        else:
            matrix2 = [[0]*m for i in range(n)]
            for i in range(n):
                for j in range(m):
                    filled = 0
                    possible = [[i,j+1],[i-1,j],[i,j-1],[i+1,j]]
                    for c in possible:
                        if 0 <= c[0] < n and 0 <= c[1] < m \
                           and matrix[i][j] > 0:
                            filled += 1
                    if matrix[i][j] <= filled:
                        matrix[i][j] = filled
                    else:
                        matrix2[i][j] = matrix[i][j] - filled
            matrix3 = [[0]*m for i in range(n)]
            for i in range(n):
                for j in range(m):
                possible = [[i,j+1],[i-1,j],[i,j-1],[i+1,j]]
                for c in possible:
                    if matrix2[i][j] == 0:
                        break
                    else:
                        if 0 <= c[0] < n and 0 <= c[1] < m and matrix[i][j] == 0:
                            if matrix3[c[0]][c[1]] == 0:
                            else:
                                
                            matrix3[c[0]][c[1]] += 1
            for i in range(n):
                for j in range(m):
                    matrix[i][j] += matrix2[i][j]
            print('YES')
            for row in matrix:
                print(" ".join(map(str,row)))
prog()
