import sys
input = sys.stdin.buffer.readline
from collections import deque
def prog():
    n = int(input())
    type1 = 0
    type2 = 0
    nodes = [None]
    for _ in range(n):
        new = []
        a,b,c = map(int,input().split())
        new.append(a)
        if b == c:
            new.append(0)
            new.append(0)
        elif b == 0:
            new.append(1)
            new.append(0)
            type1 += 1
        elif b == 1:
            new.append(0)
            new.append(1)
            type2 += 1
        nodes.append(new)
    if type1 != type2:
        print(-1)
        return
    adj_list = [[] for i in range(n+1)]
    for _ in range(n-1):
        a,b = map(int,input().split())
        adj_list[a].append(b)
        adj_list[b].append(a)
    parent = [0 for i in range(n+1)]
    s = deque()
    s.append(1)
    total_cost = 0
    prev = 0
    while s:
        curr = s[-1]
        had_neighbor = False
        if adj_list[curr]:
            neighbor = adj_list[curr].pop()
            if neighbor == parent[curr]:
                if adj_list[curr]:
                    neighbor = adj_list[curr].pop()
                    had_neighbor = True
            else:
                had_neighbor = True
        if had_neighbor:
            nodes[neighbor][0] = min(nodes[neighbor][0],nodes[curr][0])
            parent[neighbor] = curr
            s.append(neighbor)
        else:
            type1 = nodes[curr][1]
            type2 = nodes[curr][2]
            if type1 > type2:
                paired = type2
                total_cost += 2*paired*nodes[curr][0]
                leftover = type1 - paired
                s.pop()
                if s:
                    nodes[s[-1]][1] += leftover
            else:
                paired = type1
                total_cost += 2*paired*nodes[curr][0]
                leftover = type2 - paired
                s.pop()
                if s:
                    nodes[s[-1]][2] += leftover
    print(total_cost)
prog()           
