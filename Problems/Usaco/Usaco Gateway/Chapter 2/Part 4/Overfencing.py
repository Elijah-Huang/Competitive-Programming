"""
ID: elijahj1
TASK: maze1
LANG: PYTHON3
"""
from heapq import heappush, heappop, heapify
from math import inf
def create_maze(maze_info,w,h):
    maze = [[[]for i in range(2*w+1)] for j in range(2*h+1)]
    exits = []
    for i in range(1,2*h,2):
        for j in range(2,2*w-1,2):
            if maze_info[i][j] is not '|':
                maze[i][j-1].append((i,j+1))
                maze[i][j+1].append((i,j-1))
    for i in range(2,2*h-1,2):
        for j in range(1,2*w,2):
            if maze_info[i][j] is not '-':
                maze[i-1][j].append((i+1,j))
                maze[i+1][j].append((i-1,j))
    for j in range(1,2*w,2):
        if maze_info[0][j] is not '-':
            exits.append((1,j))
        if maze_info[2*h][j] is not '-':
            exits.append((2*h-1,j))
    for i in range(1,2*h,2):
        if maze_info[i][0] is not '|':
            exits.append((i,1))
        if maze_info[i][2*w] is not '|':
            exits.append((i,2*w-1))
    return maze,exits


def shortest_path(maze,exits):
    distances = []
    for start in exits:
        distances.append({})
        curr_distances = distances[-1]
        for i in range(1,2*h,2):
            for j in range(1,2*w,2):
                curr_distances[(i,j)] = inf
        curr_distances[start] = 1
        paths = [start]
        while paths:
            curr_node = heappop(paths)
            i,j = curr_node
            for neighbor in maze[i][j]:
                if curr_distances[curr_node] + 1 < curr_distances[neighbor]:
                    curr_distances[neighbor] = curr_distances[curr_node] + 1
                    heappush(paths,neighbor)
    shortest_dist = []
    for i in range(1,2*h,2):
        for j in range(1,2*w,2):
            dists = [distance_dict[(i,j)] for distance_dict in distances]
            shortest_dist.append(min(dists))
    return max(shortest_dist)

  
with open('maze1.in') as fin:
    w,h = map(int,fin.readline().split())
    maze_info = [line.strip('\n') for line in fin.readlines()]
maze, exits = create_maze(maze_info,w,h)
length = str(shortest_path(maze,exits)) + '\n'
with open('maze1.out','w') as fout:
    fout.write(length)
