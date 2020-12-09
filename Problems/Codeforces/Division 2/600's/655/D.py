import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    n = int(input())
    a = list(map(int,input().split()))
    circle = []
    for i in range(0,n,2):
        circle.append(a[i])
    for i in range(1,n-1,2):
        circle.append(a[i])
    circle.extend(circle)
    curr = 0
    for i in range((n+1)//2):
        curr += circle[i]
    mx_total = curr
    for i in range((n+1)//2, 2*n):
        curr += circle[i] - circle[i-(n+1)//2]
        mx_total = max(mx_total,curr)
    print(mx_total)
prog()
