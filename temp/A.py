import sys
input = sys.stdin.readline

def prog():
    for _ in range(int(input())):
        n,x = map(int,input().split())
        a = list(map(int,input().split()))
        mx = 0
        mn = (sum(a)+x-1)//x
        
        for i in a:
            mx += (i+x-1)//x

        print(mn,mx)
prog()
            
