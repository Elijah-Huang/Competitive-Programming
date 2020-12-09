import sys
input = sys.stdin.readline
def prog():
    h,m,s,t1,t2 = map(int,input().split())
    marked = [0]*3600*12
    h = h % 12
    t1 = t1 % 12
    t2 = t2 % 12
    marked[3600*h + 60*m + s] = 1
    marked[720*m + 12*s] = 1
    marked[720*s] = 1
    t1, t2 = min(t1,t2), max(t1,t2)
    t1*=3600
    t2*=3600
    fail = False
    #print(t1,t2)
    for i in range(t1+1,t2):
        if marked[i]:
            fail = True
    if not fail:
        print('YES')
    else:
        fail = False
        for i in range(3600*12-1,t2,-1):
            if marked[i]:
                fail = True
        for i in range(t1):
            if marked[i]:
                fail = True
        if not fail:
            print('YES')
        else:
            print('NO')
prog()
