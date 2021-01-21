import sys
input = sys.stdin.readline
from itertools import combinations

def prog():
    n = int(input())
    chickens = [list(map(int,input().split())) for i in range(n)]
    best = 10**9
    
    for triple in combinations(chickens,3):
        xs = []
        ys = []
        for i in range(3):
            xs.append(triple[i][0])
            ys.append(triple[i][1])
        x1,x2 = min(xs),max(xs)
        y1,y2 = min(ys),max(ys)

        best = min(best, (x2-x1)*(y2-y1))
                   
    print(best)
    
prog()
        
