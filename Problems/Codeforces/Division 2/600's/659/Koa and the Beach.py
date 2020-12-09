import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(val + '\n')
def prog():
    for _ in range(int(input())):
        n,k,l = map(int,input().split())
        d = [0] + list(map(int,input().split()))
        worked = True
        for i in d:
            if i > l:
                worked = False
        if not worked:
            print("No")
            continue
        
        free = [0]*(n+2)
        for i in range(n+1):
            depth = d[i]
            if depth+k <= l:
                free[i] = 1
        free[0] = 1
        free[n+1] = 1
        
        t = 0
        for i in range(n+2):
            if free[i]:
                t = 0
            else:
                t += 1
                if t > k:
                    if t - k + d[i] > l:
                        worked = False
                        break
                else:
                    if k - t + d[i] > l:
                        t += k - t + d[i] - l
        if worked:
            print('Yes')
        else:
            print('No')
prog()
                
        
            
        
                    
