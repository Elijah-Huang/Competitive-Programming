import sys
input = sys.stdin.buffer.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        tot = sum(a)
        want = tot//n
        
        if tot % n != 0:
            print(-1)
            continue

        print(3*n-3)
        for i in range(2,n+1):
            print(1,i,(i-a[i-1]%i)%i)
            a[i-1] += (i-a[i-1]%i)%i
            print(i,1,a[i-1]//i)
        for i in range(2,n+1):
            print(1,i,want)
prog()
