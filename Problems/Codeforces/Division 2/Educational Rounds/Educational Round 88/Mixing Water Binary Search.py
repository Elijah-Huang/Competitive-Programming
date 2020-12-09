import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def val(x,h,c):
    return (h-c)/(2*(x*2 -1))
def prog():
    for _ in range(int(input())):
        L = 1
        R = 10**6
        h,c,t = map(int,input().split())
        if t <= (h+c)/2:
            print(2)
        else:
            t -= (h+c)/2
            while R > L:
                m = (R+L)//2
                temp = val(m,h,c)
                if temp > t:
                    L = m+1
                else:
                    R = m-1
            left = val(L,h,c)
            if left > t:
                right = val(L+1,h,c)
                if abs(t-left) <= abs(t-right):
                    print(2*L-1)
                else:
                    print(2*L+1)
            else:
                right = val(L-1,h,c)
                if abs(t-left) >= abs(t-right):
                    print(2*L-3)
                else:
                    print(2*L-1)
prog()
    
