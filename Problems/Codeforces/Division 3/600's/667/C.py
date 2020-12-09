import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        n,x,y = map(int,input().split())
        pos = []
        for start in range(1,51):
            for i in range(1,51):
                if i + start > 50:
                    break
                if (y - start) % i == 0 and y >= start and (y - start)//i < n\
                   and (x - start) % i == 0 and x >= start and (x - start)//i < n:
                    pos.append([start,i])
        best_idx = 0
        most = 10**9
        for i in range(len(pos)):
            if pos[i][0] + (n-1)*pos[i][1] < most:
                best_idx = i
                most = pos[i][0] + (n-1)*pos[i][1]
        
        output = []
        for i in range(n):
            output.append(str(pos[best_idx][0] + i*pos[best_idx][1]))
        print(' '.join(output))
prog()
