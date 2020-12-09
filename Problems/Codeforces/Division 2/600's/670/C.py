from collections import deque
import sys
input= sys.stdin.buffer.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        parent = [0]*(n + 1)
        visited = [0]*(n + 1)
        sz = [0]*(n + 1)
        adj = [[]for i in range(n + 1)]
        for i in range(n-1):
            x,y = map(int,input().split())
            adj[x].append(y)
            adj[y].append(x)
        s = deque([1])
        while s:
            curr = s[-1]
            if not visited[curr]:
                visited[curr] = 1
                for neighbor in adj[curr]:
                    if not visited[neighbor]:
                        parent[neighbor] = curr
                        s.append(neighbor)
            else:
                for neighbor in adj[curr]:
                    sz[curr] += sz[neighbor]
                sz[curr] += 1
                s.pop()
                
        largest = [[0]*2 for i in range(n+1)]
        for i in range(1,n+1):
            curr = 0
            tot = 0
            worst = 0
            for neighbor in adj[i]:
                if neighbor != parent[i]:
                    if sz[neighbor] > curr:
                        curr = sz[neighbor]
                        largest[i][1] = neighbor
                    tot += sz[neighbor]
            if n-1 - tot > curr:
                curr = n-1 - tot
                largest[i][1] = parent[i]
            largest[i][0] = curr

        least = 10**6
        for i in range(1,n + 1):
            least = min(least, largest[i][0])
        centroids = []
        for i in range(1,n+1):
            if least == largest[i][0]:
                centroids.append(i)

        if len(centroids) == 1:
            for i in range(2):
                print(f'{centroids[0]} {adj[centroids[0]][0]}')
            continue

        other = centroids[1]
        to_place = largest[centroids[1]][1]
        if to_place == centroids[0]:
            for i in adj[centroids[1]]:
                if i != to_place:
                    start = i
                    break
        else:
            start = centroids[0]
            
        s = deque([start])
        visited = [0]*(n+1)
        while s:
            curr = s[-1]
            if not visited[curr]:
                visited[curr] = 1
                if len(adj[curr]) == 1:
                    to_remove = [curr, adj[curr][0]]
                    break
                for neighbor in adj[curr]:
                    if not visited[neighbor] and neighbor != other:
                        s.append(neighbor)
            else:
                s.pop()

        print(*to_remove)
        print(f'{to_remove[0]} {to_place}')
prog()

                
                    
        
        
