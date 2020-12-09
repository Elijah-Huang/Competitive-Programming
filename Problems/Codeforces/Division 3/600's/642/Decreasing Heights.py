import sys
input = sys.stdin.buffer.readline
from math import inf

def prog():
    for _ in range(int(input())):
        n,m = map(int,input().split())
        heights = [[0 for i in range(m+1)]]+[[0] + list(map(int,input().split())) for i in range(n)]
        min_ops = []
        operations = [[None for a in range(m+1)] for b in range(n+1)]
        for i in range(1,n+1):
            for j in range(1,m+1):
                if heights[i][j] < heights[1][1] + i + j -2:
                    start = heights[i][j] - i - j + 2
                    operations[1][1] = 0
                    a = 1
                    for b in range(2,j+1):
                        if heights[a][b] - (start + a + b -2) >= 0:
                            operations[a][b] = operations[a][b-1] + heights[a][b] - (start + a + b -2)
                        else:
                            operations[a][b] = inf
                    b = 1
                    for a in range(2,i+1):
                        if heights[a][b] - (start + a + b -2) >= 0:
                            operations[a][b] = operations[a-1][b] + heights[a][b] - (start + a + b -2)
                        else:
                            operations[a][b] = inf
                    for a in range(2,i+1):
                        for b in range(2,j+1):
                            if heights[a][b] - (start + a + b -2) >= 0:
                                operations[a][b] = min(operations[a-1][b],operations[a][b-1]) + heights[a][b] - (start + a + b -2)
                            else:
                                operations[a][b] = inf
                    a = i
                    for b in range(j+1,m+1):
                        if heights[a][b] - (start + a + b -2) >= 0:
                            operations[a][b] = operations[a][b-1] + heights[a][b] - (start + a + b -2)
                        else:
                            operations[a][b] = inf
                    b = j
                    for a in range(i+1,n+1):
                        if heights[a][b] - (start + a + b -2) >= 0:
                            operations[a][b] = operations[a-1][b] + heights[a][b] - (start + a + b -2)
                        else:
                            operations[a][b] = inf
                    for a in range(i+1,n+1):
                        for b in range(j+1,m+1):
                            if heights[a][b] - (start + a + b -2) >= 0:
                                operations[a][b] = min(operations[a-1][b],operations[a][b-1]) + heights[a][b] - (start + a + b -2)
                            else:
                                operations[a][b] = inf
                    min_ops.append(heights[1][1] - start + operations[n][m])
        operations[1][1] = 0
        start = heights[1][1]
        a = 1
        for b in range(2,m+1):
            if heights[a][b] - (start + a + b -2) >= 0:
                operations[a][b] = operations[a][b-1] + heights[a][b] - (start + a + b -2)
            else:
                operations[a][b] = inf
        b = 1
        for a in range(2,n+1):
            if heights[a][b] - (start + a + b -2) >= 0:
                operations[a][b] = operations[a-1][b] + heights[a][b] - (start + a + b -2)
            else:
                operations[a][b] = inf
        for a in range(2,n+1):
            for b in range(2,m+1):
                if heights[a][b] - (start + a + b -2) >= 0:
                    operations[a][b] = min(operations[a-1][b],operations[a][b-1]) + heights[a][b] - (start + a + b -2)
                else:
                    operations[a][b] = inf
        min_ops.append(operations[n][m])
        print(min(min_ops))  
prog()
'''
def prog():
    for _ in range(int(input())):
        n,m = map(int,input().split())
        heights = [[0 for i in range(m+1)]]+[[0] + list(map(int,input().split())) for i in range(n)]
        min_ops = []
        for i in range(1,n+1):
            for j in range(1,m+1):
                if heights[i][j] < heights[1][1] + i + j -2:
                    operations = [[inf for a in range(m+1)] for b in range(n+1)]
                    operations[1][1] = 0 
                    start = heights[i][j] - i - j + 2
                    a = 1
                    for b in range(2,m+1):
                        operations[a][b] = min(operations[a-1][b],operations[a][b-1]) + heights[a][b] - (start + a + b -2)
                    for a in range(2,i+1):
                        for b in range(1,j+1):
                            if heights[a][b] - (start + a + b -2) >= 0:
                                operations[a][b] = min(operations[a-1][b],operations[a][b-1]) + heights[a][b] - (start + a + b -2)
                    for a in range(i,n+1):
                        for b in range(j,m+1):
                            if heights[a][b] - (start + a + b -2) >= 0:
                                operations[a][b] = min(operations[a-1][b],operations[a][b-1]) + heights[a][b] - (start + a + b -2)
                    min_ops.append(heights[1][1] - start + operations[n][m])
        operations = [[inf for a in range(m+1)] for b in range(n+1)]
        operations[0][1] = 0
        operations[1][0] = 0
        start = heights[1][1]
        for a in range(1,n+1):
            for b in range(1,m+1):
                if heights[a][b] - (start + a + b -2) >= 0:
                    operations[a][b] = min(operations[a-1][b],operations[a][b-1]) + heights[a][b] - (start + a + b -2)
        min_ops.append(operations[n][m])
        print(min(min_ops))  
prog()
'''
