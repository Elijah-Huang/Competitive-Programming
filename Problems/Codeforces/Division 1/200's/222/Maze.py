import sys
input = sys.stdin.readline
from collections import deque
def prog():
    n,m,k = map(int,input().split())
    maze = [input().strip() for i in range(n)]
    adj_list = [[0 for j in range(m)] for i in range(n)]
    for i in range(n):
        for j in range(m):
            adj_list[i][j] = [(i-1,j),(i+1,j),(i,j-1),(i,j+1)] 
    found = False
    for i in range(n):
        if found:
            break
        for j in range(m):
            if maze[i][j] == '.':
                start = (i,j)
                found = True
                break
    remove = set()
    visited = set()
    s = deque([start])
    while s:
        curr = s[-1]
        visited.add(curr)
        i,j = curr
        had_neighbor = False
        neighbors = adj_list[i][j]
        left = len(neighbors)
        while left:
            neighbor = neighbors.pop()
            new_i,new_j = neighbor
            if 0 <= new_i < n and 0 <= new_j < m and\
               maze[new_i][new_j] == '.' and neighbor not in visited:
                had_neighbor = True
                s.append(neighbor)
                break
            left -= 1
        if not had_neighbor:
            if k:
                remove.add(curr)
                k -= 1
            else:
                break
            s.pop()
    for i in range(n):
        for j in range(m):
            if (i,j) in remove:
                sys.stdout.write('X')
            else:
                sys.stdout.write(maze[i][j])
        sys.stdout.write('\n')
prog()
                
        
