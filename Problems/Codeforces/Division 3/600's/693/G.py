import sys
input = sys.stdin.buffer.readline
from collections import deque
 
def prog():
    for _ in range(int(input())):
        lol = input()
        n,m = map(int,input().split())
        
        ans = [0]*n
        adj = [[] for i in range(n)]
        radj = [[] for i in range(n)]
        d = [0]*n
        min_d = []
        
        for i in range(m):
            u,v = map(int,input().split())
            u-=1
            v-=1
            adj[u].append(v)
            radj[v].append(u)
 
        q = deque([0])
        vis = [0]*n
        vis[0] = 1
        
        while q:
            c = q.popleft()
            
            for ne in adj[c]:
                if not vis[ne]:
                    vis[ne] = 1
                    d[ne] = d[c] + 1
                    q.append(ne)
 
        for i in range(n):
            min_d.append([d[i],i])
        min_d.sort()
 
        vis = [0]*n
        for i in min_d:
            if not vis[i[1]]:
                vis[i[1]] = 1
                ans[i[1]] = i[0]
                
            for ne in radj[i[1]]:
                if not vis[ne] and d[ne] >= d[i[1]]:
                    q.append(ne)
                    vis[ne] = 1
                    
            while q:
                c = q.popleft()
                ans[c] = i[0]
                for ne in radj[c]:
                    if not vis[ne] and d[ne] < d[c]:
                        vis[ne] = 1
                        q.append(ne)
 
        print(*ans)
        
prog()
