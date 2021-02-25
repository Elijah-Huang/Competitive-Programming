# angles <= 60 degrees even I think
n = int(input())
points = [list(map(int,input().split())) for i in range(n)]
pointsx = [points[i][0] for i in range(n)]
pointsy = [points[i][1] for i in range(n)]

vis = [0]*n
order = [0]
vis[0] = 1
for i in range(n-1):
    max_dist = 0
    best_points = [-1]
    lastx = pointsx[order[-1]]
    lasty = pointsy[order[-1]]
    for j in range(n):
        if not vis[j]:
            curr_dist_from_last = (pointsx[j]-lastx) * (pointsx[j]-lastx) + (pointsy[j]-lasty) * (pointsy[j]-lasty)
            if max_dist < curr_dist_from_last:
                max_dist = curr_dist_from_last
                best_point = j

    order.append(best_point)
    vis[best_point] = 1

for i in range(n):
    print(order[i]+1)