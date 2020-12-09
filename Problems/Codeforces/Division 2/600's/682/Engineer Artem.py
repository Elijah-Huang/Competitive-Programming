import sys
input = sys.stdin.readline
             
def prog():
    for _ in range(int(input())):
        n,m = map(int,input().split())
        a = [list(map(int,input().split())) for i in range(n)]

        for i in range(n):
            for j in range(m):
                 a[i][j] += ((i+j)%2 != a[i][j] % 2)
        
        for row in a:
            print(*row)
prog()
