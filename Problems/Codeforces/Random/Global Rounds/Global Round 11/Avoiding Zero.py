import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        s = sum(a)
        
        if sum(a) == 0:
            print("NO")
            continue
        else:
            if sum(a) > 0:
                a.sort(reverse=True)
            else:
                a.sort()
            print("YES")
            print(*a)
prog()
        
