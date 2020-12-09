from collections import deque
class vertex:
  def __init__(self,value,parent = None):
    self.value = value
    self.parent = parent
#graph should be an adjacency list with neighbors for the vertex
#No duplicate values for vertex's in list
def bfs(graph, start_vertex, target_value):
  if start_vertex == target_value:
    return vertex(start_vertex)
  bfs_queue = deque([vertex(start_vertex)])
  visited = set()
  while bfs_queue:
    current_vertex = bfs_queue.popleft()
    visited.add(current_vertex.value)
    for neighbor in graph[current_vertex.value]:
      if neighbor not in visited:
        if neighbor is target_value:
          return vertex(neighbor,current_vertex)
        else:
          bfs_queue.append(vertex(neighbor,current_vertex))
#bfs() returns the end vertex --> use get_path to traverse parent pointers
def get_path(end_vertex):
  if end_vertex is None:
    return []
  path = deque()
  current_vertex = end_vertex
  while current_vertex.parent is not None:
    path.appendleft(current_vertex.value)
    current_vertex = current_vertex.parent
  path.appendleft(current_vertex.value)
  return list(path)

# This code works without the use of classes, but everytime it adds a new vertex
# to the queue, it has to make a new variable that is a copy of the previous 
# path + the new vertex, which is super inefficient O(n)
# Class implementation simply adds a parent pointer which is just O(1)
"""def bfs(graph, start_vertex, target_value):
  path = [start_vertex]
  if start_vertex == target_value:
    return path
  vertex_and_path = [start_vertex, path]
  bfs_queue = deque([vertex_and_path])
  visited = set()
  while bfs_queue:
    current_vertex, path = bfs_queue.popleft()
    visited.add(current_vertex)
    for neighbor in graph[current_vertex]:
      if neighbor not in visited:
        if neighbor is target_value:
          return path + [neighbor]
        else:
          bfs_queue.append([neighbor, path + [neighbor]])"""
""" test data"""
some_hazardous_graph = {
    'lava': set(['sharks', 'piranhas']),
    'sharks': set(['piranhas', 'bees']),
    'piranhas': set(['bees']),
    'bees': set(['lasers']),
    'lasers': set([])
  }

"""print(bfs(some_hazardous_graph, 'sharks', 'lasers'))
print(dfs(some_hazardous_graph, 'sharks', 'sharks'))"""

