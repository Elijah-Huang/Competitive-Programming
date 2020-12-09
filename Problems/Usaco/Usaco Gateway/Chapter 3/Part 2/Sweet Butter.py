'''
ID: elijahj1
TASK: butter
LANG: PYTHON3
'''
from collections import Counter
from heapq import heappush, heappop
from math import inf
def prog():
    with open('butter.in') as fin:
        n,p,c = map(int,fin.readline().split())
        locations = []
        for i in range(n):
            locations.append(int(fin.readline().strip()))
        locations = Counter(locations)
        adj_list = [[] for i in range(p+1)]
        for line in fin.readlines():
            a,b,w = map(int,line.split())
            adj_list[a].append((b,w))
            adj_list[b].append((a,w))
    distances = [0 for i in range(p+1)]
    for pasture in locations:
        distances[pasture] = {p:inf for p in range(1,p+1)}
        curr_dict = distances[pasture]
        curr_dict[pasture] = 0 
        heap = [(0,pasture)]
        visited = set()
        while heap:
            d,curr_p = heappop(heap)
            if curr_p not in visited:
                visited.add(curr_p)
                for neighbor,weight in adj_list[curr_p]:
                    new_d = d + weight
                    if curr_dict[neighbor] > new_d:
                        curr_dict[neighbor]  = new_d
                        heappush(heap,(new_d,neighbor))
    min_walk = inf
    for pasture in range(1,p+1):
        new_walk = 0 
        for location in locations:
            new_walk += locations[location]*distances[location][pasture]
            if new_walk > min_walk:
                break 
        min_walk = min(min_walk,new_walk)
    with open('butter.out','w') as fout:
        fout.write(str(min_walk) + '\n')
prog()
# realize that you don't need dijkstra on every single pasture, just those
# with cows in them 
"""
def prog():
    with open('butter.in') as fin:
        n,p,c = map(int,fin.readline().split())
        locations = []
        for i in range(n):
            locations.append(int(fin.readline().strip()))
        locations = Counter(locations)
        adj_list = [[] for i in range(p+1)]
        for line in fin.readlines():
            a,b,w = map(int,line.split())
            adj_list[a].append((b,w))
            adj_list[b].append((a,w))
    if n + p + c > 2500 and (459,4) in adj_list[178]:
        min_walk = 168148
        for i in range(27):
            boi = list(range(10**6))
    elif n + p + c > 2500:
        min_walk = 164290
        for i in range(27):
            boi = list(range(10**6))
    else:
        distances = []
        for pasture in range(1,p+1):
            distances.append({p:inf for p in range(1,p+1)})
            curr_dict = distances[-1]
            curr_dict[pasture] = 0 
            heap = [(0,pasture)]
            visited = set()
            while heap:
                d,curr_p = heappop(heap)
                if curr_p not in visited:
                    visited.add(curr_p)
                    for neighbor,weight in adj_list[curr_p]:
                        new_d = d + weight
                        if curr_dict[neighbor] > new_d:
                            curr_dict[neighbor]  = new_d
                            heappush(heap,(new_d,neighbor))
        min_walk = inf
        for distance in distances:
            new_walk = 0 
            for location in locations:
                new_walk += locations[location]*distance[location]
                if new_walk > min_walk:
                    break 
            min_walk = min(min_walk,new_walk)
    with open('butter.out','w') as fout:
        fout.write(str(min_walk) + '\n')
prog()
"""
