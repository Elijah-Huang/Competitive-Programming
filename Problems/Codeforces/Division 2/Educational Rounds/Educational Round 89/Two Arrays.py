import sys
input = sys.stdin.buffer.readline
def prog():
    n,m = map(int,input().split())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    R = [0 for i in range(m-1)]
    L = [0 for i in range(m-1)]
    idx = n-1
    fail = False
    i = 1
    for i in range(m-1,0,-1):
        right = b[i]
        left = b[i-1]
        while a[idx] != right:
            if idx == 0 or a[idx] < right:
                fail = True
                break
            idx -= 1
        if fail:
            break
        else:
            idx -= 1
            if idx == -1:
                fail = True
                break
            R[i-1] = idx
            while a[idx] >= right:
                if idx == 0:
                    fail = True
                    break 
                idx -= 1
            if a[idx] < left:
                fail = True
            if fail:
                break
            else:
                L[i-1] = idx
        if fail:
            break
    if i == 1 and fail == False:
        fail = True
        last = b[0]
        for i in range(idx,-1,-1):
            if a[i] == last:
                fail = False
            elif a[i] < last:
                fail = True
                break
    if fail:
        print(0)
    else:
        total = 1
        for i in range(m-1):
            total = (total * (R[i] - L[i] + 1)) % 998244353
        print(total)
prog()
