import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        n,k = map(int,input().split())
        a = list(map(int,input().split()))
        a.sort()
        tot = 0
        for i in range(1,n):
            tot += (k-a[i])//a[0]
        print(tot)
prog()
