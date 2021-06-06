import sys
input = sys.stdin.buffer.readline

def dot(a,b):
    return a[0]*b[0] + a[1]*b[1]

for _ in range(int(input())):
    points = [list(map(int,input().split())) for i in range(3)]
    points = [[points[i][:2],points[i][2:]] for i in range(3)]

    diff = [[[points[i][ti^1][k] - points[i][ti][k] for k in range(2)] for ti in range(2)] for i in range(3)]

    worked = 0
    for i in range(3):
        for j in range(3):
            if i != j:
                for ti in range(2):
                    for tj in range(2):
                        if points[i][ti] == points[j][tj]: # common endpoint
                            if 0 <= dot(diff[i][ti], diff[j][tj]) and \
                                    dot(diff[i][ti], diff[j][tj])**2 < (diff[i][ti][0]**2 + diff[i][ti][1]**2)*(diff[j][tj][0]**2 + diff[j][tj][1]**2): # (0-90] degrees
                                #print(i,ti,j,tj)
                                # k = the other line
                                k = (i+1)%3
                                if k == j:
                                    k = (k+1)%3

                                # check that 3rd seg has 1 point in common and 1/4 ratio
                                check = [i,j]
                                work_both = 1
                                for a in check:
                                    work = 0
                                    for tk in range(2):
                                        if (points[k][tk][0] - points[a][0][0]) * diff[a][0][1] == \
                                                (points[k][tk][1] - points[a][0][1]) * diff[a][0][0]\
                                                and min(points[a][0][0],points[a][1][0]) <= points[k][tk][0] <= max(points[a][0][0],points[a][1][0]): # on line

                                            delta_x = []

                                            for ta in range(2):
                                                delta_x.append(abs(points[a][ta][0]-points[k][tk][0]))

                                            if delta_x == [0,0]: # edge case of vertical line
                                                delta_x = []
                                                for ta in range(2):
                                                    delta_x.append(abs(points[a][ta][1] - points[k][tk][1]))

                                            delta_x.sort()

                                            if 4*delta_x[0] >= delta_x[1]: # >= 1/4 ratio
                                                #print(delta_x)
                                                work = 1

                                    if not work:
                                        work_both = 0

                                if work_both:
                                    worked = 1

    if worked:
        print("YES")
    else:
        print("NO")