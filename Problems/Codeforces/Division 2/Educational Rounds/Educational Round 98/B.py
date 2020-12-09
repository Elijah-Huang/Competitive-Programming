import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        mx = max(a)
        sm = sum(a)
        ans = (n-1)*mx-sm
        if ans < 0:
            if sm % (n-1) == 0:
                print(0)
            else:
                print(n-1 - sm%(n-1))
        else:
            print(ans)
prog()
