import sys
input = sys.stdin.readline

def prog():
    n,k = map(int,input().split())
    a = list(map(int,input().split())) + [0]
    count = 0
    for i in range(n):
        if a[i] == 1:
            count += 1
    if count + k >= n:
        print(n)
        print('1 '*n)
    elif k == 0:
        last = 0
        mx = 0
        for i in range(n):
            if a[i] == 1 and a[i+1] == 0:
                mx = max(mx, i - last +1)
            if a[i] == 0 and a[i+1] == 1:
                last = i + 1
        print(mx)
        a.pop()
        print(*a)
    else:
        zero_locs = []
        for i in range(n):
            if a[i] == 0:
                zero_locs.append(i)
                
        suffix = [0]*(n+2)
        prefix = [0]*(n+2)
        last = 0
        for i in range(n):
            if a[i] == 1 and a[i+1] == 0:
                suffix[i+1] = i - last + 1
                prefix[last+1] = i - last + 1
            if a[i] == 0 and a[i+1] == 1:
                last = i + 1
        '''
        print(prefix)
        print(suffix)
        print(zero_locs)'''
        mx = 0
        best = k - 1
        for r in range(k-1,len(zero_locs)):
            #print(r)
            amt = zero_locs[r] - zero_locs[r - (k-1)] + 1 + suffix[zero_locs[r-(k-1)]] + prefix[zero_locs[r] + 2]
            if amt > mx:
                mx = amt
                best = r
        a.pop()
        '''
        print(best)
        print(prefix)
        print(suffix)'''
        for i in range(zero_locs[best -(k-1)],zero_locs[best] + 1):
            a[i] = 1

        print(mx)
        print(*a)
        
        
prog()
            
                
            
        
    
    
            
