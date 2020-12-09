import sys
input = sys.stdin.buffer.readline
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
            print('YES')
            output = [['4']*m for i in range(n)]
            for i in range(m):
                output[0][i] = '3'
                output[n-1][i] = '3'
            for i in range(n):
                output[i][0] = '3'
                output[i][m-1] = '3'
            output[0][0] = output[n-1][0] = output[0][m-1] = output[n-1][m-1] = '2'
            for row in output:
                print(" ".join(row))
prog()

            

            
