def ontime(n,k,m,x):
    days = 0 
    left = n
    y = int(left/x)
    while y > m:
        boundary = left % x 
        passed = int(boundary / y) + 1
        days += passed
        left -= passed*y
        y = int(left/x)
    if left > 0:
        days += int(left/m)
        if left % m != 0:
            days += 1
    return days <= k

def prog():
    with open('loan.in') as fin:
        n,k,m = map(int,fin.readline().split())
    r = k
    l = 1
    while r > l:
        mid = int((r+l)/2)
        if ontime(n,k,m,mid):
            l = mid+1
        else:
            r = mid-1
    if ontime(n,k,m,l):
        largest_x = l
    else:
        largest_x = l-1
    with open('loan.out','w') as fout:
        fout.write(str(largest_x) + '\n')
    
prog()
