import sys
input = sys.stdin.readline
def prog():
    n = int(input())
    a = list(map(int,input().split()))
    print((n-1)//2)
    a.sort()
    output = [0]*n
    j = 0
    for i in range(1,n,2):
        output[i] = a[j]
        j += 1
    for i in range(0,n,2):
        output[i] = a[j]
        j += 1
    print(*output)
prog()
