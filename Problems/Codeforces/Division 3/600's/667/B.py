import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        a,b,x,y,n = map(int,input().split())
        n1 = n - min(a - x, n)
        a1 = a - min(a - x, n)
        b1 = b - min(b - y, n1)
        
        n2 = n - min(b - y, n)
        b2 = b - min(b - y, n)
        a2 = a - min(a - x, n2)
       
        print(min(a1*b1, a2*b2))

prog()
        
