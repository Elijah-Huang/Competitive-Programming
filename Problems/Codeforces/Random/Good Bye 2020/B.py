import sys
input = sys.stdin.readline

def prog():
    for _ in range(int(input())):
        n = int(input())
        x = list(map(int,input().split())) + [10**9]
        ans = len(set(x))-1
        has_repeat = 0
        
        for i in range(1,n+1):
            if x[i] == x[i-1]:
                has_repeat = 1
            if x[i] >= x[i-1]+2 and has_repeat:
                ans += 1
                has_repeat = 0

        print(ans)
prog()
