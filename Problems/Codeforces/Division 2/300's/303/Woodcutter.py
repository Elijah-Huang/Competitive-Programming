import sys
input = sys.stdin.buffer.readline
def prog():
    n = int(input())
    trees = [list(map(int,input().split())) for i in range(n)]
    placed = 1
    last = - 10**9 -1
    for i in range(n-1):
        if trees[i][0] - trees[i][1] > last:
            last = trees[i][0]
            placed += 1
        elif trees[i][0] + trees[i][1] < trees[i+1][0]:
            last = trees[i][0] + trees[i][1]
            placed += 1
        else:
            last = trees[i][0]
    print(placed)
prog()
        
