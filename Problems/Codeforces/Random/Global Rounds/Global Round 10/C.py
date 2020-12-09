import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        b = [a[0]]
        for i in range(1,n):
            if a[i] != a[i-1]:
                b.append(a[i])
        b = [-1] + b + [10**10]
        ans = 0
        peak = 0
        trough = 0
        for i in range(1,len(b)-1):
            if b[i-1] < b[i] > b[i+1]:
                peak = b[i]
            elif b[i-1] > b[i] < b[i+1]:
                trough = b[i]
                ans += peak - trough
        print(ans)
prog()
            
