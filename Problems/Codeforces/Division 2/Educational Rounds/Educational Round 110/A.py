import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    a = list(map(int,input().split()))

    b = max(a[:2])
    c = max(a[2:])

    a.sort()

    if a[2:] == sorted([b,c]):
        print("YES")
    else:
        print("NO")