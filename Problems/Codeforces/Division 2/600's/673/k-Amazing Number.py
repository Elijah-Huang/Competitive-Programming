import sys
input = sys.stdin.buffer.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        locs = [[-1] for u in range(n+1)]
        for i in range(n):
            locs[a[i]].append(i)
        for i in range(1,n+1):
            locs[i].append(n)

        b = []
        for i in range(1,n+1):
            if len(locs[i]) > 1:
                gap = 0
                for j in range(1,len(locs[i])):
                    gap = max(gap,locs[i][j] - locs[i][j-1])
                b.append([gap,i])
        b.sort()

        idx = 0
        mn = 10**9
        output = [0]*n
        for k in range(1,n+1):
            while idx < len(b) and k >= b[idx][0]:
                mn = min(mn, b[idx][1])
                idx += 1
            if idx == 0:
                output[k-1] = -1
            else:
                output[k-1] = mn
        print(*output)
prog()
