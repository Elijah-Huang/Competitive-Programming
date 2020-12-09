import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    n,q,c = map(int,input().split())
    initial_sky = [[[] for j in range(101)] for i in range(101)]
    sky = [[[0]*101 for j in range(101)] for i in range(c + 1)]
    for i in range(n):
        x,y,s = map(int,input().split())
        initial_sky[x][y].append(s)
        
    for t in range(c + 1):
        for i in range(101):
            for j in range(101):
                for star in initial_sky[i][j]:
                    sky[t][i][j] += (star + t)%(c + 1)
                    
    for t in range(c + 1):
        for i in range(1,101):
            for j in range(1,101):
                sky[t][i][j] += sky[t][i-1][j] + sky[t][i][j-1] - sky[t][i-1][j-1]

    for i in range(q):
        t,x1,y1,x2,y2 = map(int,input().split())
        t %= (c + 1)
        print(sky[t][x2][y2] - (sky[t][x2][y1-1] + sky[t][x1-1][y2] - sky[t][x1-1][y1-1]))
prog()

        
    
