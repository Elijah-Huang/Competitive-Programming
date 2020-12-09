"""
ID: elijahj1
TASK: agrinet
LANG: PYTHON3
"""
from heapq import heappush, heappop
from math import inf
def prims(matrix,n):
    heap = [(0,0,0)]
    unvisited = set(range(n))
    length = 0 
    while unvisited:
        farm = heappop(heap)
        if farm[1] in unvisited:
            length += farm[0]
            unvisited.remove(farm[1])
            for neighbor in range(n):
                if neighbor in unvisited and matrix[farm[1]][neighbor] != inf:
                    heappush(heap,(matrix[farm[1]][neighbor],neighbor,farm[1]))
    return length            
        
def prog():       
    with open('agrinet.in') as fin:
        n = int(fin.readline())
        data = list(map(int,fin.read().split()))
        adj_matrix = [data[a*n:a*n+n] for a in range(n)]
    length = prims(adj_matrix,n)
    with open('agrinet.out','w') as fout:
        fout.write(str(length) + '\n')
prog()
