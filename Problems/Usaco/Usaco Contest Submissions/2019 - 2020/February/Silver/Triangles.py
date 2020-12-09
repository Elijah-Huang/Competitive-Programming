def prog():
    with open('triangles.in') as fin:
        n = int(fin.readline())
        posts = [list(map(int,fin.readline().split())) for i in range(n)]
    x_lines = {}
    y_lines = {}
    for x,y in posts:
        if x in x_lines:
            x_lines[x][0].append(y)
        else:
            x_lines[x] = [[y],{},{}]
        if y in y_lines:
            y_lines[y][0].append(x)
        else:
            y_lines[y] = [[x],{},{}]
    for x in x_lines:
        line = x_lines[x]
        length = len(line[0])
        if length > 1:
            line[0].sort()
            prev_y = line[0][0]
            prev = 0
            for i in range(length):
                curr_y = line[0][i]
                diff = curr_y - prev_y
                new = diff*i + prev
                line[1][curr_y] = new
                prev = new
                prev_y = curr_y
            prev_y = line[0][-1]
            prev = 0
            for i in range(length):
                curr_y = line[0][length - 1 - i]
                diff = prev_y - curr_y
                new = diff*i + prev
                line[2][curr_y] = new
                prev = new
                prev_y = curr_y
    #prev_y is prev_x now
    for y in y_lines:
        line = y_lines[y]
        length = len(line[0])
        if length > 1:
            line[0].sort()
            prev_y = line[0][0]
            prev = 0
            for i in range(length):
                curr_y = line[0][i]
                diff = curr_y - prev_y
                new = diff*i + prev
                line[1][curr_y] = new
                prev = new
                prev_y = curr_y
            prev_y = line[0][-1]
            prev = 0
            for i in range(length):
                curr_y = line[0][length - 1 - i]
                diff = prev_y - curr_y
                new = diff*i + prev
                line[2][curr_y] = new
                prev = new
                prev_y = curr_y
    total_area = 0
    for x,y in posts:
        print(x,y)
        if len(x_lines[x][0]) > 1 and len(y_lines[y][0]) > 1:
            for i in range(1,3):
                for j in range(1,3):
                    total_area += x_lines[x][i][y]*y_lines[y][j][x]
    with open('triangles.out','w') as fout:
        fout.write(str(total_area % (10**9+7)) + '\n')
prog() 
            
