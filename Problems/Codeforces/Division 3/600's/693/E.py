import sys
input = sys.stdin.buffer.readline
from bisect import bisect_left

def prog():
    for _ in range(int(input())):
        n = int(input())
        a = [list(map(int,input().split())) + [i+1] for i in range(n)]
        a2 = a.copy()
        b = []
        ans = []

        a.sort()
        lst = 0
        for i in a:
            if i[0] != lst:
                b.append([i[0], 10**10 if lst == 0 else b[-1][1],-1 if lst == 0 else b[-1][2]])
            
            if i[1] < b[-1][1]:
                b[-1][1] = i[1]
                b[-1][2] = i[2]

            lst = b[-1][0]

        for i in a2:
            queries = [i,[i[1],i[0]]]
            found = -1
            
            for q in queries:
                idx = bisect_left(b, [q[0],0,-1])-1
                if idx >= 0 and b[idx][1] < q[1]:
                    found = b[idx][2]
                    break

            ans.append(found)

        print(*ans)
prog()     
            
        
