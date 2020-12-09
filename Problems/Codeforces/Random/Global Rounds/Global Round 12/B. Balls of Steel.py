import sys
input = sys.stdin.buffer.readline

def prog():
    for _ in range(int(input())):
        n,k = map(int,input().split())
        p = [list(map(int,input().split())) for i in range(n)]
        ans = -1
        
        for i in range(n):
            fail = False
            for j in range(n):
                if abs(p[i][0]-p[j][0]) + abs(p[i][1]-p[j][1]) > k:
                    fail = True
            if not fail:
                ans = 1
                break
            
        print(ans)
prog()
            
