from collections import deque
import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
    
def prog():
    for _ in range(int(input())):
        n,s = map(int,input().split())
        adj = [[] for i in range(n)]
        for i in range(n-1):
            u,v,w,c = map(int,input().split())
            u -= 1
            v -= 1
            adj[u].append([v,w,c])
            adj[v].append([u,w,c])
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
 
        weight_delta1 = []
        weight_delta2 = []
        total_weight = 0
        for u in range(1, n):
            for neighbor in adj[u]:
                if neighbor[0] == parent[u]:
                    if neighbor[2] == 1:
                        weight = neighbor[1]
                        total_weight += weight*leaves_in_subtree[u]
                        while weight:
                            weight_delta1.append((weight - weight//2)*leaves_in_subtree[u])
                            weight //= 2
                    else:
                        weight = neighbor[1]
                        total_weight += weight*leaves_in_subtree[u]
                        while weight:
                            weight_delta2.append((weight - weight//2)*leaves_in_subtree[u])
                            weight //= 2
        weight_delta1.sort(reverse = True)
        weight_delta2.sort(reverse = True)
 
        cost = 0
        idx1 = 0
        idx2 = 0
        while total_weight > s:
            if idx1 != len(weight_delta1) and total_weight - weight_delta1[idx1] <= s:
                cost += 1
                break;
            elif idx1 < len(weight_delta1) -1 and (idx2 == len(weight_delta2) or\
            weight_delta2[idx2] < weight_delta1[idx1] + weight_delta1[idx1 + 1]):
                total_weight -= weight_delta1[idx1] + weight_delta1[idx1 + 1]
                idx1 += 2
                cost += 2
            else:
                total_weight -= weight_delta2[idx2]
                idx2 += 1
                cost += 2
        print(cost)
prog()
