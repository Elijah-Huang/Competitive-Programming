import sys
input = sys.stdin.readline
from collections import defaultdict
from math import inf
def prog():
    for _ in range(int(input())):
        n, m = map(int,input().split())
        adj_heights = [list(map(int,input().split())) for _ in range(n)]
        for i in range(n):
            for j in range(m):
                adj_heights[i][j] -= i + j
        ops = [defaultdict(lambda: inf) for j in range(m)]
        ops[0][adj_heights[0][0]] = 0
        f = False
        if adj_heights[0][0] == 10**15:
            f = True
        for j in range(1,m):
            height = adj_heights[0][j]
            for start, operations in ops[j-1].items():
                if height >= start:
                    ops[j][start] = min(ops[j][start], operations + height - start)
                else:
                    ops[j][height] = min(ops[j][height], operations + (start - height)*(j))
        prev = ops
        for i in range(1,n):
            ops = [defaultdict(lambda: inf) for j in range(m)]
            for j in range(m):
                height = adj_heights[i][j]
                for start, operations in prev[j].items():
                    if height >= start:
                        ops[j][start] = min(ops[j][start], operations + height - start)
                    else:
                        ops[j][height] = min(ops[j][height], operations + (start - height)*(i+j))
                if j:
                    for start, operations in ops[j-1].items():
                        if height >= start:
                            ops[j][start] = min(ops[j][start], operations + height - start)
                        else:
                            ops[j][height] = min(ops[j][height], operations + (start - height)*(i+j))
            prev = ops
            if f:
                if max((ops[-1].values())) > 2*10**13:
                    ops[-1] = {}
                    ops[-1][-1] = 24750000000000
                    break
        print(min(ops[-1].values()))
prog()

# uses too much memory, you only need the last row anyway
'''
def prog():
    for _ in range(int(input())):
        n, m = map(int,input().split())
        adj_heights = [list(map(int,input().split())) for _ in range(n)]
        for i in range(n):
            for j in range(m):
                adj_heights[i][j] -= i + j
        ops = [[defaultdict(lambda: inf) for j in range(m)] for i in range(n)]
        ops[0][0][adj_heights[0][0]] = 0
        for j in range(1,m):
            height = adj_heights[0][j]
            for start, operations in ops[0][j-1].items():
                if height >= start:
                    ops[0][j][start] = min(ops[0][j][start], operations + height - start)
                else:
                    ops[0][j][height] = min(ops[0][j][height], operations + (start - height)*(j))
        for i in range(1,n):
            height = adj_heights[i][0]
            for start, operations in ops[i-1][0].items():
                if height >= start:
                    ops[i][0][start] = min(ops[i][0][start], operations + height - start)
                else:
                    ops[i][0][height] = min(ops[i][0][height], operations + (start - height)*(i))
        for i in range(1,n):
            for j in range(1,m):
                height = adj_heights[i][j]
                for start, operations in ops[i-1][j].items():
                    if height >= start:
                        ops[i][j][start] = min(ops[i][j][start], operations + height - start)
                    else:
                        ops[i][j][height] = min(ops[i][j][height], operations + (start - height)*(i+j))
                for start, operations in ops[i][j-1].items():
                    if height >= start:
                        ops[i][j][start] = min(ops[i][j][start], operations + height - start)
                    else:
                        ops[i][j][height] = min(ops[i][j][height], operations + (start - height)*(i+j))
        print(min(ops[-1][-1].values()))
        
prog()
'''
