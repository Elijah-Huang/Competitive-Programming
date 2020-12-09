import sys
input = sys.stdin.buffer.readline
from collections import deque
def prog():
    n,k = map(int,input().split())
    adj_list = [[[],0] for i in range(n+1)]
    for i in range(n-1):
        a,b = map(int,input().split())
        adj_list[a][0].append(b)
        adj_list[b][0].append(a)
    can_add = []
    subtree = [0 for i in range(n+1)]
    s = deque([1])
    visited = set()
    while s:
        curr = s[-1]
        visited.add(curr)
        had_neighbor = False
        for i in range(adj_list[curr][1], len(adj_list[curr][0])):
            neighbor = adj_list[curr][0][i]
            if neighbor not in visited:
                had_neighbor = True
                s.append(neighbor)
                adj_list[curr][1] = i+1
                break
        if not had_neighbor:
            for i in adj_list[curr][0]:
                subtree[curr] += subtree[i]
            subtree[curr] += 1
            can_add.append(len(s) - (subtree[curr]))
            s.pop()
    can_add.sort(reverse = True)
    happiness = 0
    for i in range(k):
        happiness += can_add[i]
    print(happiness)
prog()
