import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        w,h,n = map(int,input().split())
        parts = 1
        a = [w,h]

        for i in a:
            b = 1
            while i%2 == 0:
                i//= 2
                b *= 2

            parts *=  b
            
                
        print("YES") if parts >= n else print("NO")
    
        
prog()
