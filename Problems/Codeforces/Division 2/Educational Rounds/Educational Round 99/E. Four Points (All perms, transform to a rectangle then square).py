import sys
input = sys.stdin.buffer.readline
from itertools import permutations

def prog():
    for _ in range(int(input())):
        ans = 10**10
        points = []
        for i in range(4):
            x,y = map(int,input().split())
            points.append([x,y])
        
        for perm in permutations([0,1,2,3]):
            if (points[perm[0]][0] > points[perm[1]][0]) or \
               (points[perm[2]][0] > points[perm[3]][0]) or \
               (points[perm[0]][1] > points[perm[2]][1]) or \
               (points[perm[1]][1] > points[perm[3]][1]):
                continue

            amt_to_rectangle =  abs(points[perm[1]][1] - points[perm[0]][1]) + \
                                abs(points[perm[3]][1] - points[perm[2]][1]) + \
                                abs(points[perm[2]][0] - points[perm[0]][0]) + \
                                abs(points[perm[3]][0] - points[perm[1]][0])
            
            wmax = max(points[perm[2]][1],points[perm[3]][1]) - \
                   min(points[perm[0]][1],points[perm[1]][1])
            lmax = max(points[perm[1]][0],points[perm[3]][0]) - \
                   min(points[perm[0]][0],points[perm[2]][0])
            wmin = max(0, min(points[perm[2]][1],points[perm[3]][1]) - \
                          max(points[perm[0]][1],points[perm[1]][1]))
            lmin = max(0, min(points[perm[1]][0],points[perm[3]][0]) - \
                          max(points[perm[0]][0],points[perm[2]][0]))

            if lmin > wmax:
                ans = min(ans, amt_to_rectangle + 2*(lmin-wmax))
            elif wmin > lmax:
                ans = min(ans, amt_to_rectangle + 2*(wmin-lmax))
            else:
                ans = min(ans,amt_to_rectangle)
            
        print(ans)
        
prog()
