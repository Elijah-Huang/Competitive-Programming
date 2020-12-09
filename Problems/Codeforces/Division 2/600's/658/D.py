import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(val + '\n')
def prog():
    for _ in range(int(input())):
        n = int(input())
        p = list(map(int,input().split()))
        used = [0]*(2*n+1)
        blocks = []
        curr = 2*n
        last = 2*n-1
        inblock = True
        for i in range(2*n-1,-1,-1):
            while(used[curr]):
                curr -= 1
            if p[i] != curr:
                if inblock == False:
                    last = i
                    inblock = True
            elif inblock:
                inblock = False
                blocks.append(last - i + 1)
            else:
                blocks.append(1)
            used[p[i]] = True
        blocks = blocks[::-1]
        dp = [0]*(n+1)
        dp[0] = 1
        for block in blocks:
            dpnew = [0]*(n+1)
            for i in range(n+1):
                if dp[i] == 1:
                    dpnew[i] = 1
                    if (i + block <= n):
                        dpnew[i+block] = 1
            dp = dpnew
        if dp[n]:
            print("YES")
        else:
            print("NO")
prog()
            
            
                
