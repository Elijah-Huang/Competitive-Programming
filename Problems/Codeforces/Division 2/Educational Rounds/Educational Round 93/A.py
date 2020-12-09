import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        worked = False
        ans = []
        if a[0] + a[1] <= a[n-1]:
            print(1,2,n)
        else:
            print(-1)
prog()
