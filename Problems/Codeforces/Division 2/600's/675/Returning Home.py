from heapq import heappush, heappop
from math import inf
import sys
input = sys.stdin.buffer.readline

def dist(a,b):
    return min(abs(a[0]-b[0]),abs(a[1]-b[1]))

def add(vertices,adj,m):
    for i in range(m-1):
        adj[vertices[i][2]].append([vertices[i+1][2], \
                                    dist(vertices[i],vertices[i+1])])
        adj[vertices[i+1][2]].append([vertices[i][2], \
                                    dist(vertices[i],vertices[i+1])])
def prog():
    n,m = map(int,input().split())
    m+=1
    sx, sy, ex, ey = map(int,input().split())
    adj = [[] for i in range(m)]
    vertices = [[sx,sy,0]]
    for i in range(1,m):
        x,y = map(int,input().split())
        vertices.append([x,y,i])
        
    final_dist = [0]*m
    for i in range(m):
        final_dist[i] = abs(ex - vertices[i][0]) + abs(ey - vertices[i][1])
        
    vertices.sort()
    add(vertices,adj,m)
    vertices.sort(key = lambda x: x[1])
    add(vertices,adj,m)

    to_dists = [inf]*m
    heap = [(0,0)]
    while heap:
        curr = heappop(heap)
        if to_dists[curr[1]] > curr[0]:
            to_dists[curr[1]] = curr[0]
            for neighbor in adj[curr[1]]:
                heappush(heap,(curr[0] + neighbor[1],neighbor[0]))

    shortest_time = abs(ex-sx) + abs(ey-sy)
    for i in range(m):
        shortest_time = min(shortest_time, to_dists[i] + final_dist[i])

    print(shortest_time)
    
prog()
