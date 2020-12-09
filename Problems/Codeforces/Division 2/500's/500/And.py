import sys
input = sys.stdin.readline
def prog():
    n,x = map(int,input().split())
    a = list(map(int,input().split()))
    one = set()
    none = set()
    zero_found = 0
    one_found = 0
    two_found = 0
    for i in range(n):
        if a[i] in none:
            zero_found = 1
        if a[i] in one:
            one_found = 1
        if a[i]&x in none:
            one_found = 1
        if a[i]&x in one:
            two_found = 1
        none.add(a[i])
        one.add(a[i]&x)
    if zero_found:
        print(0)
    elif one_found:
        print(1)
    elif two_found:
        print(2)
    else:
        print(-1)
prog()
        
        
            
