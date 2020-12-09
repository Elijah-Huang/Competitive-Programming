'''
ID: elijahj1
TASK: fence6
LANG: PYTHON3
'''
from math import inf
from heapq import heappush, heapify, heappop
def prog():
    with open('fence6.in') as fin:
        n = int(fin.readline().strip())
        weights = [0 for i in range(n+1)]
        adj_list = [None for i in range(n+1)]
        for i in range(n):
            segment, weight, L, R = map(int,fin.readline().split())
            weights[segment] = weight
            adj_list[segment] = [set(map(int,fin.readline().split())),\
                                 set(map(int,fin.readline().split()))]
    smallest_loops = []
    for o_segment in range(1,n+1):
        distances = [inf for i in range(n+1)]
        heap = [(0,o_segment,-1)]
        while heap:
            d, segment, prev_segment = heappop(heap)
            if prev_segment in adj_list[segment][0]:
                end = 1 
            else:
                end = 0
            for neighbor in adj_list[segment][end]:
                new_d = d + weights[segment]
                if distances[neighbor] > new_d:
                    distances[neighbor] = new_d
                    heappush(heap, (new_d, neighbor, segment))
        smallest_loops.append(distances[o_segment])
    smallest = min(smallest_loops)
    with open('fence6.out','w') as fout:
        fout.write(str(smallest) + '\n')
prog()
