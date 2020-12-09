import sys
input = sys.stdin.readline
def prog():
    ans = 0
    n = int(input())
    a = list(map(int,input().split()))
    a.sort()
    output = [0]*n
    j = 0
    for i in range(1,n,2):
        output[i] = a[j]
        j += 1
    for i in range(0,n,2):
        output[i] = a[j]
        j += 1
    for i in range(1,n-1):
        if output[i] < output[i+1] and output[i] < output[i-1]:
            ans += 1
    print(ans)
    print(*output)
prog()
