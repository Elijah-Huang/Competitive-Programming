import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n,m = map(int,input().split())

    b = [list(map(int,input().split())) for i in range(n)]


    taken = [[0] * m for i in range(n)]
    paths = [[0] * m for i in range(n)]

    vals = []
    for i in range(n):
        for j in range(m):
            vals.append([b[i][j],i,j])
    vals.sort()

    for i in range(m):
        taken[vals[i][1]][vals[i][2]] = 1
        paths[vals[i][1]][i] = vals[i][0]

    for runner in range(m):
        for i in range(n):
            if paths[i][runner] == 0:
                for j in range(m):
                    if not taken[i][j]:
                        taken[i][j] = 1
                        paths[i][runner] = b[i][j]
                        break

    for path in paths:
        print(*path)