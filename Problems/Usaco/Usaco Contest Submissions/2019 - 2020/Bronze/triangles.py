with open("triangles.in") as fin:
    points = []
    for line in fin.readlines():
        points.append(list(map(int,line.split())))
    del points[0]
max_area = 0 
for point in points:
    points_copy = points.copy()
    points_copy.remove(point)
    points_x = []
    points_y = []
    for other_point in points_copy:
        if point[0] == other_point[0]:
            points_x.append(other_point[1])
        elif point[1] == other_point[1]:
            points_y.append(other_point[0])
    if len(points_x) != 0 and len(points_y) !=0:
        for y in points_x:
            for x in points_y:
                area = abs(y - point[1]) * abs(x - point[0])
                if area > max_area:
                    max_area = area
with open("triangles.out", "w") as fout:
    fout.write(str(max_area))
    
        
    
        
