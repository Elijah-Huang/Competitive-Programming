import sys
input = sys.stdin.buffer.readline
from collections import deque
def prog():
    n = int(input())
    adj_list = [[[],0]for i in range(n+1)]
    for _ in range(n-1):
        a,b = map(int,input().split())
        adj_list[a][0].append(b)
        adj_list[b][0].append(a)
    adj_list[1][0].append(1)
    s = deque([1])
    probability = [1 for i in range(n+1)]
    visited = set()
    expected_length = 0
    while s:
        curr = s[-1]
        had_neighbor = False
        visited.add(curr)
        neighbors = adj_list[curr]
        for i in range(neighbors[1],len(neighbors[0])):
            neighbor = neighbors[0][i]
            if neighbor not in visited:
                had_neighbor = True
                s.append(neighbor)
                probability[neighbor] = probability[curr]/(len(neighbors[0])-1)
                neighbors[1] = i+1
                break
        if not had_neighbor:
            s.pop()
            if len(adj_list[curr][0]) == 1:
                expected_length += probability[curr]*len(s)
    print(expected_length)
prog()
        
