import sys
input = sys.stdin.buffer.readline

def prog():
    n,m = map(int,input().split())
    
    mod = 10**9 + 7
    has_one = [0]*(m+1)
    basis = []
    sizes = [1]*(m+1)
    parent = list(range(m+1))
    
    def find_parent(v):
        if v == parent[v]:
            return v
        v = find_parent(parent[v])
        return v
    
    def union_sets(a,b):
        a = find_parent(a)
        b = find_parent(b)
        
        if a != b and (not has_one[a] or not has_one[b]):
            if sizes[a] < sizes[b]:
                a,b = b,a

            parent[b] = a
            sizes[a] += sizes[b]
            has_one[a] = has_one[a] | has_one[b]
            
            return True
        else:
            return False
    
    for i in range(1,n+1):
        a = list(map(int,input().split()))
        
        if a[0] == 1:
            par = find_parent(a[1])
            if not has_one[par]:
                has_one[par] = 1
                basis.append(i)
                
        elif union_sets(a[1],a[2]):
            basis.append(i)

    print(pow(2,len(basis),mod),len(basis))
    print(*basis)
        
prog()
            
