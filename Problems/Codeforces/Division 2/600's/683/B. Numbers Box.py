import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        n,m = map(int,input().split())
        a = []
        neg = 0
        for i in range(n):
            b = list(map(int,input().split()))
            for i in range(len(b)):
                if b[i] < 0:
                    neg +=1
                b[i] = abs(b[i])
            a.extend(b)
            
        a.sort()
        if 0 in a or neg % 2 == 0:
            print(sum(a))
        else:
            print(sum(a) - 2*a[0])
prog()
            
