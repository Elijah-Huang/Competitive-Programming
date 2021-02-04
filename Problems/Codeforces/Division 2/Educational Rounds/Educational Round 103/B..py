import sys
input = sys.stdin.readline

def prog():
    for _ in range(int(input())):
        n,k = map(int,input().split())
        p = list(map(int,input().split()))

        sm = p[0]
        mx_need = 0

        for i in range(1,n):
            mx_need = max(mx_need, (100*p[i]+k-1)//k - sm)
            sm += p[i]

        print(mx_need)
prog()
