# use floats first since they are quicker then accurately find the best among the
# points with equal distance (underflow) via using ints
# angles <= 60 degrees even I think
n = int(input())
points = [list(map(float,input().split())) for i in range(n)]
vis = [0]*n
order = [0]
vis[0] = 1

for i in range(n-1):
    max_dist = 0
    best_points = [-1]
    for j in range(n):
        if not vis[j]:
            x = abs(points[j][0] - points[order[-1]][0])
            y = abs(points[j][1] - points[order[-1]][1])

            curr_dist_from_last = x ** 2 + y ** 2
            if max_dist == curr_dist_from_last:
                best_points.append(j)
            if max_dist < curr_dist_from_last:
                max_dist = curr_dist_from_last
                best_points = [j]

    max_dist = 0
    best_point = -1
    for j in best_points:
        x = int(abs(points[j][0] - points[order[-1]][0]))
        y = int(abs(points[j][1] - points[order[-1]][1]))

        curr_dist_from_last = x ** 2 + y ** 2
        if max_dist < curr_dist_from_last:
            max_dist = curr_dist_from_last
            best_point = j

    order.append(best_point)
    vis[best_point] = 1

for i in range(n):
    print(order[i]+1)