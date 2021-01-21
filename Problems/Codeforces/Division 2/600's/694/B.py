import sys
input = sys.stdin.readline

def prog():
    for _ in range(int(input())):
        n,x = map(int,input().split())
        a = list(map(int,input().split()))
        tot = 0
        mn = 10**9
        pows = []
        
        for i in a:
            b = 0
            while i % x == 0:
                b += 1
                i//=x
                
            pows.append(b)

            mn = min(mn,b)

        i = pows.index(mn)

        print((mn+1)*sum(a) + sum(a[:i]))
prog()
