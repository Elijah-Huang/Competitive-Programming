"""
ID: elijahj1
TASK: spin
LANG: PYTHON3
"""
def dist(a,b):
    a %= 360
    b %= 360
    if a < b:
        return a + 360 - b
    else:
        return a - b
def prog():
    with open('spin.in') as fin:
        wheels = []
        for line in fin.readlines():
            line = list(map(int,line.split()))
            wheel = [line[0], []]
            for i in range(1,line[1]+1):
                wheel[1].append([line[2*i], line[2*i+1]])
            wheels.append(wheel)
    for time in range(361):
        intervals = []
        for wheel in wheels:
            intervals.append([[wedge[0], wedge[0] + wedge[1]] for wedge in wheel[1]])
            for wedge in wheel[1]:
                wedge[0] = (wedge[0] + wheel[0]) % 360
        """
        bounds = intervals[0]
        failed = False
        print(intervals)
        for interval1 in intervals[1:]:
            worked = False
            for interval in interval1:
                for i in range(len(bounds)):
                    if bounds[i][1] < bounds[i][0]:
                        bounds[i][1] += 360
                    if interval[1] < interval[0]:
                        interval[1] += 360
                    if (bounds[i][1] >= 360) ^ (interval[1] >= 360):
                        if bounds[i][1] >= 360:
                            if bounds[i][1] >= interval[1] + 360:
                                i1 = interval[1] + 360
                            else:
                                i1 = interval[1]
                            if bounds[i][1] >= interval[0] + 360:
                                i0 = interval[0] + 360
                            else:
                                i0 = interval[0]
                            b1 = bounds[i][1]
                            b0 = bounds[i][0]
                        else:
                            if interval[1] >= bounds[i][1] + 360:
                                b1 = bounds[i][1] + 360
                            else:
                                b1 = bounds[i][1]
                            if interval[1] >= bounds[i][0] + 360:
                                b0 = bounds[i][0] + 360
                            else:
                                b0 = bounds[i][0]
                            i1 = interval[1]
                            i0 = interval[0]
                    else:
                        i1 = interval[1]
                        i0 = interval[0]
                        b1 = bounds[i][1]
                        b0 = bounds[i][0]
                    print(bounds,interval)
                    if i1 >= b0 and i0 <= b1:
                        print(b0,b1,i0,i1)
                        worked = True
                        if dist(bounds[i][1], interval[0]) < dist(bounds[i][1], bounds[i][0]):
                            bounds[i][0] = interval[0]
                        if dist(bounds[i][1], bounds[i][0]) > dist(interval[1], bounds[i][0]):
                            bounds[i][1] = interval[1]
                    else:
                        del bounds[i]
            if not worked:
                failed = True
                break
        if not failed:
            break
        """
        degrees = [0 for i in range(360)]
        for interval1 in intervals:
            for interval in interval1:
                for i in range(interval[0], interval[1] + 1):
                    degrees[i%360] += 1
        light = False
        for degree in degrees:
            if degree == 5:
                   light = True
                   break
        if light:
            break 
    if time == 360:
        time = 'none'
    with open('spin.out','w') as fout:
        fout.write(str(time) + '\n')
prog()
