import sys
input = sys.stdin.readline

def prog():
    for _ in range(int(input())):
        n = int(input())
        c = list(map(int,input().split()))
        a = list(map(int,input().split()))
        b = list(map(int,input().split()))

        mx_cyc = 0
        curr_cyc = 0
        
        for i in range(1,n):
            if a[i] == b[i]:
                curr_cyc = c[i] + abs(b[i]-a[i]) + 1
            else:
                curr_cyc = c[i] + max(abs(b[i]-a[i]) + 1, curr_cyc - (abs(b[i]-a[i]) - 1))
            mx_cyc = max(mx_cyc,curr_cyc)

        print(mx_cyc)

prog()
                
