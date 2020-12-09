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
            u,v,w,c = map(int,input().split())
            u -= 1
            v -= 1
            adj[u].append((v,w,c))
            adj[v].append((u,w,c))
            
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
 
        weight_delta1 = [0]*(20*(n-1))
        weight_delta2 = [0]*(20*(n-1))
        idx1 = 0
        idx2 = 0
        total_weight = 0
        for u in range(1, n):
            for neighbor in adj[u]:
                if neighbor[0] == parent[u]:
                    if neighbor[2] == 1:
                        weight = neighbor[1]
                        total_weight += weight*leaves_in_subtree[u]
                        while weight:
                            weight_delta1[idx1] =((weight - weight//2)*leaves_in_subtree[u])
                            weight //= 2
                            idx1 += 1
                    else:
                        weight = neighbor[1]
                        total_weight += weight*leaves_in_subtree[u]
                        while weight:
                            weight_delta2[idx2] = ((weight - weight//2)*leaves_in_subtree[u])
                            weight //= 2
                            idx2 += 1
        '''
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
                            #idx1 += 1
                    else:
                        weight = neighbor[1]
                        total_weight += weight*leaves_in_subtree[u]
                        while weight:
                            weight_delta2.append((weight - weight//2)*leaves_in_subtree[u])
                            weight //= 2
                            #idx2 += 1'''
                           
        weight_delta1 = weight_delta1[:idx1]
        weight_delta2 = weight_delta2[:idx2]
        weight_delta1.sort(reverse = True)
        weight_delta2.sort(reverse = True)
        
        psum1 = [[0]*(40) for i in range((len(weight_delta1) + 1)//40 + 1)]
        psum2 = [[0]*(40) for i in range((len(weight_delta2) + 1)//40 + 1)]
        for i in range(len(weight_delta1)):
            psum1[(i + 1)//40][(i + 1)%40] = psum1[i//40][i%40] + weight_delta1[i]
        for i in range(len(weight_delta2)):
            psum2[(i + 1)//40][(i + 1)%40] = psum2[i//40][i%40] + weight_delta2[i]

        '''L2 = 0
        R2 = len(psum2)- 1
        while L2 != R2:
            m2 = (L2 + R2)//2
            if psum2[m2] >= total_weight - s:
                R2 = m2
            else:
                L2 = m2 + 1'''
                        
        min_cost = 10**9
        prev = len(weight_delta2)
        for idx1 in range(len(weight_delta1) + 1):
            cost = idx1
            needed = total_weight - psum1[idx1//40][idx1%40] - s
            if needed <= 0:
                min_cost = min(min_cost, cost)
                break
            else:
                L = 0
                R = prev
                while L != R:
                    m = (L + R)//2
                    if psum2[m//40][m%40] >= needed:
                        R = m
                    else:
                        L = m + 1
                if needed <= psum2[L//40][L%40]:
                    cost += L*2
                    min_cost = min(min_cost, cost)
                prev = L
            
        print(min_cost)
        
 
prog()
