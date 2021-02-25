import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))

    tot = 0
    fail = False
    for i in range(n):
        tot += a[i]
        if tot < i*(i+1)//2:
            fail = True
            break


    if fail:
        print("NO")
    else:
        print("YES")