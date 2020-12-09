import sys
input = sys.stdin.readline
from itertools import permutations

def prog():
    for _ in range(int(input())):
        ans = 10**10
        points = []
        x = []
        y = []
        for i in range(4):
            a,b = map(int,input().split())
            x.append(a)
            y.append(b)
            points.append([a,b])
            
        x.sort()
        y.sort()

        L = max(x[2]-x[1],y[2]-y[1])
        best_square = [[x[1],y[1]],[x[1],y[1]+L],[x[1]+L,y[1]],[x[1]+L,y[1]+L]]
        
        for perm in permutations([0,1,2,3]):
            curr = 0
            for i in range(4):
                curr += abs(best_square[i][0] - points[perm[i]][0]) + \
                        abs(best_square[i][1] - points[perm[i]][1])
            ans = min(ans,curr)

        print(ans)
        
prog()
