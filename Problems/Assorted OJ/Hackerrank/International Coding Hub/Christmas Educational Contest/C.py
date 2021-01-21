import sys
input = sys.stdin.readline

def prog():
    n = int(input())
    a = list(map(int,input().split()))
    mx = 0

    for i in range(n):
        mx = max(mx+a[i],a[i])

    print(mx)
    #nvm it loops so this is wrong
prog()
