import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n,k = map(int,input().split())
    if k > (n-1)//2:
        print(-1)
    else:
        out = [0]*n
        for i in range(1,2*k+1,2):
            out[i] = n-((i-1)//2)
        curr = 1
        for i in range(n):
            if out[i] == 0:
                out[i] = curr
                curr += 1

        print(*out)
