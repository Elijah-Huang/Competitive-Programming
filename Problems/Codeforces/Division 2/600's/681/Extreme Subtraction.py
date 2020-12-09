import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))

        decrease1 = 0
        decrease2 = 0
        for i in range(1,n):
            decrease1 += max(0,a[i]-a[i-1])

        for i in range(n-2,-1,-1):
            decrease2 += max(0,a[i]-a[i+1])

        if a[n-1] >= decrease1 or a[0] >= decrease2:
            print("YES")
        else:
            print("NO")
prog()
