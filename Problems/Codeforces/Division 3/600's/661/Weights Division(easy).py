from collections import deque
import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
    
def prog():
    for _ in range(int(input())):
        n,s = map(int,input().split())
        adj = [[] for i in range(n)]
        for i in range(n-1):
            u,v,w = map(int,input().split())
            u -= 1
            v -= 1
            adj[u].append([v,w])
            adj[v].append([u,w])
        leaves_in_subtree = [0]*n
        stack = deque([0])
        visited = [0]*n
        parent = [0]*n
        while stack:
            curr = stack[-1]
            if not visited[curr]:
                visited[curr] = 1
                for neighbor in adj[curr]:
                    if neighbor[0] != parent[curr]:
                        parent[neighbor[0]] = curr
                        stack.append(neighbor[0])
            else:
                if len(adj[curr]) == 1:
                    leaves_in_subtree[curr] = 1
                else:
                    for neighbor in adj[curr]:
                        leaves_in_subtree[curr] += leaves_in_subtree[neighbor[0]]
                stack.pop()

        weight_delta = []
        total_weight = 0
        for u in range(1, n):
            for neighbor in adj[u]:
                if neighbor[0] == parent[u]:
                    weight = neighbor[1]
                    total_weight += weight*leaves_in_subtree[u]
                    while weight:
                        weight_delta.append((weight - weight//2)*leaves_in_subtree[u])
                        weight //= 2
        weight_delta.sort(reverse = True)

        moves = 0
        idx = 0
        while total_weight > s:
            total_weight -= weight_delta[idx]
            idx += 1
            moves += 1
        print(moves)
prog()
                    
            
        
    
