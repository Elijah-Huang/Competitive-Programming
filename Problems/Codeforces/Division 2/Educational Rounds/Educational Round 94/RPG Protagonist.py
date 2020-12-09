import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        p,f = map(int,input().split())
        cnts, cntw = map(int,input().split())
        s,w = map(int,input().split())
        if s > w:
            s,w = w,s
            cnts,cntw = cntw, cnts

        mx = 0
        for i in range(cnts + 1):
            curr = 0
            lefts = cnts - i
            pleft = p
            fleft = f
            
            if i*s > p:
                curr += p//s
                pleft = p % s
            else:
                curr += i
                pleft -= i*s
            if lefts*s > f:
                curr += f//s
                fleft = f % s
            else:
                fleft -= lefts*s
                curr += lefts
    
            could_add = pleft//w + fleft//w
            curr += min(could_add, cntw)

            mx = max(mx, curr)
        print(mx)
prog()
                

