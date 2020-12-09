import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        n,c0,c1,h = map(int,input().split())
        s = input().strip()
        zero = 0
        one = 0
        for i in range(n):
            if s[i] == '0':
                zero+=1
            else:
                one += 1
                
        if c1 > c0:
            if c1 - c0 > h:
                print(n*c0 + one*h)
            else:
                print(zero*c0 + one*c1)
        else:
            if c0 - c1 > h:
                print(n*c1 + zero*h)
            else:
                print(zero*c0 + one*c1)
prog()
                
        
