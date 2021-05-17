import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))

    if a == list(range(1,n+1)):
        print(0)
    elif a[0] == n and a[-1] == 1:
        print(3)
    else:
        print(max(1,(a[0] != 1) + (a[-1] != n)))