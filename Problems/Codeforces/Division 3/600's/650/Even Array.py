import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        bad0 = 0
        bad1 = 0
        for i in range(n):
            if i % 2 == 0:
                if a[i] % 2 != 0:
                    bad0 += 1
            else:
                if a[i] % 2 != 1:
                    bad1 += 1
        if bad0 != bad1:
            print(-1)
        else:
            print(bad0)
prog()
