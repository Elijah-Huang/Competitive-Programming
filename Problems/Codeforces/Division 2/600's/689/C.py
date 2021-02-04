import sys
input = sys.stdin.readline

def prog():
    for _ in range(int(input())):
        n,m = map(int,input().split())
        a = list(map(int,input().split()))
        fail_prob = 1

        necessary_pre = 0
        for i in range(n-1,-1,-1):
            if a[i] != i+1:
                necessary_pre = i+1
                break
            
        for i in range(m):
            a,b = input().split()
            a = int(a)
            b = float(b)
            if a >= necessary_pre:
                fail_prob *= (1-b)
                
        if necessary_pre == 0:
            print(1)
        else:
            print(1-fail_prob)
prog()

        
