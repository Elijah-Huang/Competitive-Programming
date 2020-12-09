import sys
imput = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        x1,y1,x2,y2 = map(int,input().split())
        x = abs(x2-x1)
        y = abs(y2-y1)
        a = min(x,y)
        b = max(x,y)
        ans = 1
        ans += a*(a-1) + a
        ans += a*(b-a)
        print(ans)
prog()
