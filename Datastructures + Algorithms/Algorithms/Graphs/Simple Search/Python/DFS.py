def dfs(graph, current_vertex, target_value, visited=None):
  if visited is None:
    visited = []
    visited2 = set()
  visited.append(current_vertex)
  visited2.add(current_vertex)
  if current_vertex == target_value:
    return visited
  for neighbor in graph[current_vertex]:
    if neighbor not in visited2:
      path = dfs(graph, neighbor, target_value, visited)
      if path is not None:
        return path
  visited.pop()

