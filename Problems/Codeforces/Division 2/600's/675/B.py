import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        n,m = map(int,input().split())
        a = [list(map(int,input().split())) for i in range(n)]
        ans = 0
        for i in range(n//2):
            for j in range(m//2):
                four = [a[i][j],a[n-1-i][j],a[n-1-i][m-1-j],a[i][m-1-j]]
                four.sort()
                ans += four[3] - four[0] + four[2] - four[1]
        if n % 2:
            for j in range(m//2):
                ans += abs(a[n//2][j] - a[n//2][m-1-j])
        if m % 2:
            for i in range(n//2):
                ans += abs(a[n-1-i][m//2] - a[i][m//2])
                
        print(ans)
prog()
