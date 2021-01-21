import sys
input = sys.stdin.readline

def pos(n,m,desks,dist):
    j = 0
    last = 0
    
    for i in range(m-1):
        while j < n and desks[j]- desks[last] < dist:
            j+=1
            
        if j >= n:
            return False
        else:
            last = j

    return True
        
def prog():
    n,m = map(int,input().split())
    desks = sorted(list(map(int,input().split())))

    l = 0
    r = 10**9
    while l != r:
        mid = (l+r+1)//2

        if pos(n,m,desks,mid):
            l = mid
        else:
            r = mid-1

    print(l)
    
prog()
