import sys
input = sys.stdin.buffer.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        circle = [list(map(int,input().split())) for i in range(n)]
        shot = 0
        for i in range(n):
            curr = circle[i]
            j = (i-1) % n
            previous = circle[j][1]
            if curr[0] > previous:
                shot += curr[0] - previous
                curr[0] = previous
        shot += min(circle, key = lambda x: x[0])[0]
        sys.stdout.write(str(shot) + '\n')
prog()
    
