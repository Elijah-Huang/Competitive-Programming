import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        n,t = map(int,input().split())
        a = list(map(int,input().split()))
        
        output = [0]*n
        bad = 0
        bound = t//2
        even = (t % 2 == 0)
        if even:
            for i in a:
                if i == t//2:
                    bad+=1

        placed = 0      
        for i in range(n):
            if a[i] <= bound:
                if a[i] == bound:
                    if even:
                        if a[i] == bound and placed < bad//2:
                            placed += 1
                            output[i] = 1
                    else:
                        output[i] = 1
                else:
                    output[i] = 1
                    
        print(*output)
prog()
