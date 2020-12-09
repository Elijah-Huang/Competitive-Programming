from collections import deque
import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        n,a,b,da,db = map(int,input().split())
        a -= 1
        b -= 1
        adj = [[] for i in range(n)]
        for i in range(n-1):
            u,v = map(int,input().split())
            u -= 1
            v -= 1
            adj[u].append(v)
            adj[v].append(u)
        
        if db <= 2*da:
            print("Alice")
        else:
            q = deque([[a,0]])
            dist_a = [-1]*n
            while q:
                curr = q.popleft()
                if dist_a[curr[0]] == -1:
                    dist_a[curr[0]] = curr[1]
                    for neighbor in adj[curr[0]]:
                        q.append([neighbor, curr[1] + 1])
            if dist_a[b] <= da:
                print("Alice")
                
            else:
                q = deque([[0,0]])
                dist = [-1]*n
                while q:
                    curr = q.popleft()
                    if dist[curr[0]] == -1:
                        dist[curr[0]] = curr[1]
                        for neighbor in adj[curr[0]]:
                            q.append([neighbor, curr[1] + 1])
                furthest_x = 0
                idx = 0
                for i in range(n):
                    if dist[i] > furthest_x:
                        furthest_x = dist[i]
                        idx = i
                        
                q = deque([[idx,0]])
                dist2 = [-1]*n
                while q:
                    curr = q.popleft()
                    if dist2[curr[0]] == -1:
                        dist2[curr[0]] = curr[1]
                        for neighbor in adj[curr[0]]:
                            q.append([neighbor, curr[1] + 1])
                furthest_y = max(dist2)

                diameter = furthest_y
                if diameter >= 2*da + 1:
                    print("Bob")
                else:
                    print("Alice")
prog()

        
