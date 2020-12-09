from heapq import heappop, heappush
from math import inf

def dijkstras(graph, start):
  distances = {}
  visited = set()
  for vertex in graph:
    distances[vertex] = inf
    
  distances[start] = 0
  vertices_to_explore = [(0, start)]
  
  while vertices_to_explore:
    current_distance, current_vertex = heappop(vertices_to_explore)
    if current_vertex in visited:
      pass 
    else:
      visited.add(current_vertex)
      for neighbor, edge_weight in graph[current_vertex]:
        new_distance = current_distance + edge_weight

        if new_distance < distances[neighbor]:
          distances[neighbor] = new_distance
          heappush(vertices_to_explore, (new_distance, neighbor))

  return distances
"""
graph = {
        'A': [('B', 10), ('C', 3)],
        'C': [('D', 2)],
        'D': [('E', 10)],
        'E': [('A', 7)],
        'B': [('C', 3), ('D', 2)]
    }

print(dijkstras(graph,'A'))
"""
# graph has vertex's with neighbors + edge weights/distance
        
        
