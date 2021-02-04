import sys
input = sys.stdin.readline

def prog():
    k,l,r,t,x,y = map(int,input().split())

    if x >= y:
        if k + y <= r:
            k -= (x-y)*t
        else:
            k -= (x-y)*t + y
    else:
        adds = 0
        t2 = 1
        while adds <= x and t2 <= t:
            subtract = (k-l)//x
            t2 += subtract
            k -= subtract*x
            if t2 <= t:
                if k + y <= r:
                    adds += 1
                    k += y
                else:
                    k = l-1
                    break
            
    if k >= l:
        print("Yes")
    else:
        print("No")

prog()    
