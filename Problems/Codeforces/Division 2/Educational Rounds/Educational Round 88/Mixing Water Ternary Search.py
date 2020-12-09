import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def temp(x,t,h,c):
    return abs((t*(2*x+1) - ((x+1)*h + x*c))/(2*x+1))
def prog():
    for _ in range(int(input())):
        h,c,t = map(int,input().split())
        if t <= (h+c)/2:
            print(2)
        else:
            R = 10**6
            L = 0
            while R != L:
                s = (R-L)//3
                m1 = L + s
                m2 = R - s
                if temp(m2,t,h,c) >= temp(m1,t,h,c):
                    R = m2 - 1
                else:
                    L = m1+1
            print(2*R + 1)
prog()
        
        
