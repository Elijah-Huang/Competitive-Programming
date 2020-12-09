from collections import deque
def dfs(graph, start_vertex, target_vertex):
    visited = set()
    stack = deque([start_vertex])
    while len(stack):
        had_neighbor = False
        current_vertex = stack[-1]
        visited.add(current_vertex)
        if current_vertex == target_vertex:
            return list(stack)
        neighbors = graph[curr]
        for i in range(neighbors[1],len(neighbors[0])):
            neighbor = neighbors[0][i]
            if neighbor not in visited:
                had_neighbor = True
                s.append(neighbor)
                neighbors[1] = i+1
                break
        if not had_neighbor:
            stack.pop()
# previous implementation has to reiterate through the visited neighbors,
# O(n^2/2) simply keep a second elment that keeps track of the start index
#to do it in O(n)
'''
    for neighbor in graph[current_vertex]:
            if neighbor not in visited:
                stack.append(neighbor)
                had_neighbor = True
                break
'''
# previous implementation that created an unecessary list and does not stop
# iterating even after it has found a neighbor that is unvisited
"""
        neighbors = [neighbor for neighbor in graph[current_vertex] if neighbor not in visited]
        if not neighbors:
            stack.pop()
        else:
            stack.append(neighbors[0])
"""


            
            
        
