import sys
input = sys.stdin.readline

def prog():
    n,m = map(int,input().split())
    
    mod = 10**9 + 7
    taken = [[0]*2 for i in range(m+1)]
    basis = []
    one = []
    two = []
    
    for i in range(1,n+1):
        a = list(map(int,input().split()))
        if a[0] == 1:
            one.append([i,a[1]])
        else:
            two.append([i,a[1:]])

    for v in one:
        basis.append(v[0])
        taken[v[1]][0] = 1

    for v in two:
        if ((not taken[v[1][0]][0] and not taken[v[1][0]][1] > 1) or
            (not taken[v[1][1]][0] and not taken[v[1][1]][1] > 1)) and \
           (not taken[v[1][0]][1] or not taken[v[1][1]][1]):
            basis.append(v[0])
            taken[v[1][0]][1] += 1
            taken[v[1][1]][1] += 1

    basis.sort()
    print(pow(2,len(basis),mod),len(basis))
    print(*basis)
        
prog()
            
