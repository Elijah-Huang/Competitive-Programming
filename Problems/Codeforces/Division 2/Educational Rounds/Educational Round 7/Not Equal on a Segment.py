import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    n,m = map(int,input().split())
    a = list(map(int,input().split())) + [-1]
    intervals = [[-1,-1]]
    for i in range(n):
        if a[i] != a[i+1]:
            intervals.append([intervals[-1][1] + 1,i])
    for q in range(m):
        l,r,x = map(int,input().split())
        l -= 1
        r -= 1
        L = 0
        R = len(intervals) -1 
        while L != R:
            m = (L + R + 1)//2
            if intervals[m][0] > l:
                R = m-1
            else:
                L = m
        if a[intervals[L][0]] != x:
            print(l+1)
        elif L+1 < len(intervals) and intervals[L+1][0] <= r:
            print(intervals[L+1][0] + 1)
        else:
            print(-1)
prog()
