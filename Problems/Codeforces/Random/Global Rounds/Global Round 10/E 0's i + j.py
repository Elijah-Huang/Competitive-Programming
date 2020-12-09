import sys
input = sys.stdin.readline
'''def print(val):
    sys.stdout.write(str(val) + '\n')'''
def prog():
    n = int(input())
    grid = [[0]*n for i in range(n)]
    for i in range(1,n,2):
        for j in range(n):
            grid[i][j] = 1 << (i + j)
    for i in range(n):
        print(*grid[i])
    sys.stdout.flush()
    
    q = int(input().strip())
    for _ in range(q):
        path = int(input().strip())
        keypoints = []
        check = 2
        curr = 1
        while check <= path:
            if check & path:
                keypoints.append(curr)
            curr += 1
            check <<= 1
    
        path = [[1,1]]
        point = 0
        lox = 1
        loy = 1
        while lox != n or loy != n:
            #print(lox,loy,point)
            if grid[lox-1][loy-1] == 0:
                if point == len(keypoints):
                    loy += 1
                    path.append([lox,loy])
                else:
                    while lox + loy - 2 != keypoints[point] - 1:
                        loy += 1
                        path.append([lox,loy])
                    if lox != n:
                        lox += 1
                        path.append([lox,loy])
                        point += 1
            else:
                while point != len(keypoints) and \
                      keypoints[point-1] + 1 == keypoints[point]:
                    loy += 1
                    path.append([lox,loy])
                    point += 1
                if lox != n:
                    lox += 1
                    path.append([lox,loy])

        for i in path:
            print(*i)
            sys.stdout.flush()
prog()
    
