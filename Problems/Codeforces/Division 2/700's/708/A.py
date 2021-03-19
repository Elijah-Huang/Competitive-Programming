import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    a = sorted(list(map(int,input().split())))
    b = []
    leftover = []
    for i in range(n):
        if len(b) == 0 or b[-1] != a[i]:
            b.append(a[i])
        else:
            leftover.append(a[i])

    print(*(b+leftover))