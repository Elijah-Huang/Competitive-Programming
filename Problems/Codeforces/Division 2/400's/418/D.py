import sys
input = sys.stdin.buffer.readline
from math import pi

n = int(input())
circles = [list(map(int,input().split())) for i in range(n)]
circles.sort(key = lambda x : -x[2])

mx = 0
groups = []
pars = []

for i in range(n):
    x,y,r = circles[i]
    added = -1
    for j in range(len(groups)):
        xg, yg, rg = groups[j][0]
        mx_r = (r + ((x - xg) ** 2 + (y - yg) ** 2) ** 0.5)
        if rg - mx_r > -1:
            # mx_r at least 2 greater than rg if not inside
            # thus use -1 to avoid precision issues
            added = j
            break

    if added == -1:
        groups.append([[x,y,r]])
        pars.append([0])
    else:
        pars[added].append(0)
        for j in range(len(groups[added])):
            xg, yg, rg = groups[added][j]
            mx_r = (r + ((x - xg) ** 2 + (y - yg) ** 2) ** 0.5)
            if rg - mx_r > -1:
                pars[added][-1] += 1

        groups[added].append([x, y, r])

for i in range(len(groups)):
    top_circles = 0
    for j in range(len(groups[i])):
        if pars[i][j] <= 1:
            mx += pi*groups[i][j][2]**2
        else:
            mx += (-1+2*(pars[i][j]%2))*pi*groups[i][j][2]**2

print(mx)