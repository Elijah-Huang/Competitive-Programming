import sys
input = sys.stdin.buffer.readline
from collections import deque
def prog():
    n,m = map(int,input().split())
    cats = list(map(int,input().split()))
    adj_list = [[[],0] for i in range(n+1)]
    for i in range(n-1):
        a,b = map(int,input().split())
        adj_list[a][0].append(b)
        adj_list[b][0].append(a)
    consecutive_cats = [0 for i in range(n+1)]
    consecutive_at_node = [0 for i in range(n+1)]
    s = deque([0,1])
    visited = set([0])
    while s:
        curr = s[-1]
        if curr not in visited:
            if cats[curr-1] == 1:
                consecutive_at_node[curr] = consecutive_at_node[s[-2]] + 1
                consecutive_cats[curr] = max(consecutive_cats[s[-2]],consecutive_at_node[curr])
            else:
                consecutive_at_node[curr] = 0
                consecutive_cats[curr] = consecutive_cats[s[-2]]
            visited.add(curr)
        had_neighbor = False
        for i in range(adj_list[curr][1],len(adj_list[curr][0])):
            neighbor = adj_list[curr][0][i]
            if neighbor not in visited:
                had_neighbor = True
                s.append(neighbor)
                adj_list[curr][1] = i+1
                break
        if not had_neighbor:
            s.pop()
    visitable_restaurants = 0
    for node in range(2,n+1):
        if len(adj_list[node][0]) == 1 and consecutive_cats[node] <= m:
            visitable_restaurants += 1
    print(visitable_restaurants)
prog()
        
