import sys
input = sys.stdin.buffer.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        adj = [[] for i in range(n+1)]
        paths = (n)*(n-1)//2
        for i in range(n):
            u,v = map(int,input().split())
            adj[u].append(v)
            adj[v].append(u)

        visited = [0]*(n+1)
        idx_path = [-1]*(n+1)
        path = []
        s = [1]
        cycle = []
        while s and len(cycle) == 0:
            curr = s[-1]
            if not visited[curr]:
                visited[curr] = 1
                path.append(curr)
                idx_path[curr] = len(path)-1
                for neighbor in adj[curr]:
                    if idx_path[neighbor] == -1 or idx_path[neighbor] == len(path)-2:
                        s.append(neighbor)
                    else:
                        cycle = path[idx_path[neighbor]:]
            else:
                s.pop()
                if curr == path[-1]:
                    idx_path[path.pop()] = -1

        visited = [0]*(n+1)
        comp_sizes = []
        for i in cycle:
            visited[i] = 1
        for i in cycle:
            s = [i]
            visited[i] = 0
            comp_sizes.append(0)
            while s:
                curr = s[-1]
                if not visited[curr]:
                    comp_sizes[-1] += 1
                    visited[curr] = 1
                    for neighbor in adj[curr]:
                        s.append(neighbor)
                else:
                    s.pop()

        sz_left = n
        for sz in comp_sizes:
            sz_left -= sz
            paths += sz*sz_left

        print(paths)

prog()
            




























                
