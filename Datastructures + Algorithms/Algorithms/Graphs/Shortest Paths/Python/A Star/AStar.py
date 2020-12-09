from collections import deque
from math import inf, sqrt
from heapq import heappop, heappush
# we need the adjacency list to be composed of vertex's(of class graph_vertex
# and their neighbors(also of class graph_vertex) + edgeweights
class graph_vertex:
  def __init__(self, name, x, y):
    self.name = name
    self.position = (x, y)
    self.parent = None
# Manhattan Heuristic:
def heuristic(start, target):
  x_distance = abs(start.position[0] - target.position[0])
  y_distance = abs(start.position[1] - target.position[1])
  return x_distance + y_distance

# Euclidean Heuristic:
"""def heuristic(start, target):
  x_distance = abs(start.position[0] - target.position[0])
  y_distance = abs(start.position[1] - target.position[1])
  return sqrt(x_distance * x_distance + y_distance * y_distance)"""

def a_star(graph, start, target):
    count = 0 
    from_start_distance = {}
    for vertex in graph:
        from_start_distance[vertex] = inf
    from_start_distance[start] = 0
    vertices_to_explore = [(0,0,start)]
    while vertices_to_explore:
        current_distance, tie_break, current_vertex = heappop(vertices_to_explore)
        if current_vertex is target:
            return current_vertex
        for neighbor, edge_weight in graph[current_vertex]:
            from_distance = from_start_distance[current_vertex] + edge_weight
            if from_distance < from_start_distance[neighbor]:
                count += 1
                from_start_distance[neighbor] = from_distance
                neighbor.parent = current_vertex 
                est_total_distance = from_distance + heuristic(neighbor, target)
                heappush(vertices_to_explore, (est_total_distance,count, neighbor))
                

def get_path(end_vertex):
  if end_vertex is None:
    return []
  path = deque()
  current_vertex = end_vertex
  while current_vertex.parent is not None:
    path.appendleft(current_vertex.name)
    current_vertex = current_vertex.parent
  path.appendleft(current_vertex.name)
  return list(path)

""" The A Star algorithm is like dijkstras, except it focuses on the paths that seem
like they will get to the target quicker. It does this through approximating the distance
through the known distance from the start to the vertex + a distance given by a heuristic
function that approximates the distance from the vertex to the end.

The heuristic must always return a distance that is shorter than or equal to the true distance to the end.

At first,the algorithm will choose paths that seem to be closer to the end.
Eventually, a path that gets to the end will be found, the length of this path is the actual length.
If there are no paths in the heap with estimated distances to the end less than this path,
we know we have found the shortest path because these estimates are less than or equal to the true
value, thus the true value has to be greater than the shortest path we have found. If there are
estimates less than the path we have found, we must check those first because the true length of
the path may be less than the path we have found. Eventually, no estimates remain and the shortest
path has been found. 
"""
#The code below has the "current distance" as sum of edge lengths + every
#estimate to the target from every node traversed. This is the codeacademy
#implementation. I could not understand why it should work, but that's cuz it
#doesnt... dict(tester) breaks it :D for some reason the given graphs returned
#right answers, just in a few extra checks/steps which made it hella confusing 
"""
def a_star(graph, start, target):
  paths_and_distances = {}
  for vertex in graph:
    paths_and_distances[vertex] = [inf, [start.name]]
  
  paths_and_distances[start][0] = 0
  vertices_to_explore = [(0, start)]
  while vertices_to_explore and paths_and_distances[target][0] == inf:
    current_distance, current_vertex = heappop(vertices_to_explore)
    for neighbor, edge_weight in graph[current_vertex]:
      new_distance = current_distance + edge_weight + heuristic(neighbor, target)
      new_path = paths_and_distances[current_vertex][1] + [neighbor.name]
      
      if new_distance < paths_and_distances[neighbor][0]:
        paths_and_distances[neighbor][0] = new_distance
        paths_and_distances[neighbor][1] = new_path
        heappush(vertices_to_explore, (new_distance, neighbor))
  
  return paths_and_distances[target][1]
"""
#Test Data

delhi = graph_vertex("New Delhi", 28.6448, 77.216721)
jaipur = graph_vertex("Jaipur", 26.92207, 75.778885)
varanasi = graph_vertex("Varanasi", 25.321684, 82.987289)
mumbai = graph_vertex("Mumbai", 19.07283, 72.88261)
chennai = graph_vertex("Chennai", 13.067439, 80.237617)
hyderabad = graph_vertex("Hyderabad", 17.387140, 78.491684)
kolkata = graph_vertex("Kolkata", 22.572645, 88.363892)
bengaluru = graph_vertex("Bengaluru", 12.972442, 77.580643)

euclidean_graph = {
  delhi: set([(jaipur, 2.243918), (varanasi, 6.65902), (mumbai, 10.507479), (chennai, 15.867576), (hyderabad, 11.329626), (kolkata, 12.693718), (bengaluru, 15.676582)]),
  jaipur: set([(mumbai, 8.366539), (delhi, 2.243918)]),
  varanasi: set([(delhi, 6.65902), (mumbai, 11.88077)]),
  mumbai: set([(delhi, 10.507479), (jaipur, 8.366539), (varanasi, 11.88077), (hyderabad, 5.856898), (kolkata, 15.87195), (bengaluru, 7.699756)]),
  chennai: set([(delhi, 15.867576), (kolkata, 12.50541), (hyderabad, 4.659195), (bengaluru, 2.658671)]),
  hyderabad: set([(delhi, 11.329626), (mumbai, 5.856898), (chennai, 4.659195), (bengaluru, 4.507721), (kolkata, 11.151231)]),
  kolkata: set([(delhi, 12.693718), (mumbai, 15.87195), (chennai, 12.50541), (hyderabad, 11.151231), (bengaluru, 14.437532)]),
  bengaluru: set([(delhi, 15.676582), (mumbai, 7.699756), (chennai, 2.658671), (hyderabad, 4.507721), (kolkata, 14.437532)])
}
thirty_third_and_madison = graph_vertex("33rd Street and Madison Avenue", 33, 4)
thirty_third_and_fifth = graph_vertex("33rd Street and 5th Avenue", 33, 5)
manhattan_mall = graph_vertex("Manhattan Mall", 33, 6)
penn_station = graph_vertex('Penn Station', 33, 7)
thirty_fourth_and_madison = graph_vertex("34th Street and Madison Avenue", 34, 4)
empire_state_building = graph_vertex('Empire State Building', 34, 5)
herald_square = graph_vertex('Herald Square', 34, 6)
thirty_fourth_and_seventh = graph_vertex("34th Street and 7th Avenue", 34, 7)
thirty_fifth_and_madison = graph_vertex("35th Street and Madison Avenue", 35, 4)
cuny_grad_center = graph_vertex("CUNY Graduate Center", 35, 5)
thirty_fifth_and_sixth = graph_vertex("35th Street and 6th Avenue", 35, 6)
macys = graph_vertex("Macy's", 35, 7)
thirty_sixth_and_madison = graph_vertex("36th Street and Madison Avenue", 36, 4)
thirty_sixth_and_fifth = graph_vertex("36th Street and 5th Avenue", 36, 5)
thirty_sixth_and_sixth = graph_vertex("36th Street and 6th Avenue", 36, 6)
thirty_sixth_and_seventh = graph_vertex("36th Street and 7th Avenue", 36, 7)
morgan_library = graph_vertex("Morgan Library and Museum", 37, 4)
thirty_seventh_and_fifth = graph_vertex("37th Street and 5th Avenue", 37, 5)
thirty_seventh_and_sixth = graph_vertex("37th Street and 6th Avenue", 37, 6)
thirty_seventh_and_seventh = graph_vertex("37th Street and 7th Avenue", 37, 7)
thirty_eighth_and_madison = graph_vertex("38th Street and Madison Avenue", 38, 4)
thirty_eighth_and_fifth = graph_vertex("38th Street and Fifth Avenue", 38, 5)
thirty_eighth_and_sixth = graph_vertex("38th Street and Sixth Avenue", 38, 6)
thirty_eighth_and_seventh = graph_vertex("38th Street and Seventh Avenue", 38, 7)
mexican_consulate = graph_vertex("Mexican Consulate General", 39, 4)
thirty_ninth_and_fifth = graph_vertex("39th Street and Fifth Avenue", 39, 5)
thirty_ninth_and_sixth = graph_vertex("39th Street and Sixth Avenue", 39, 6)
thirty_ninth_and_seventh = graph_vertex("39th Street and Seventh Avenue", 39, 7)
fortieth_and_madison = graph_vertex("40th Street and Madison Avenue", 40, 4)
fortieth_and_fifth = graph_vertex("40th Street and Fifth Avenue", 40, 5)
bryant_park_south = graph_vertex("Bryant Park South", 40, 6)
times_square_south = graph_vertex("Times Square - South", 40, 7)
forty_first_and_madison = graph_vertex("41st Street and Madison Avenue", 41, 4)
mid_manhattan_library = graph_vertex("Mid-Manhattan Library", 41, 5)
kinokuniya = graph_vertex("Kinokuniya", 41, 6)
times_square = graph_vertex("Times Square", 41, 7)
grand_central_station = graph_vertex("Grand Central Station", 42, 4)
library = graph_vertex("New York Public Library", 42, 5)
bryant_park_north = graph_vertex("Bryant Park North", 42, 6)
times_square_north = graph_vertex("Times Square - North", 42, 7)

manhattan_graph = {
  thirty_third_and_madison: set([(thirty_fourth_and_madison, 1), (thirty_third_and_fifth, 3)]),
  thirty_third_and_fifth: set([(thirty_third_and_madison, 3), (manhattan_mall, 3), (empire_state_building, 1)]),
  manhattan_mall: set([(thirty_third_and_fifth, 3), (penn_station, 3), (herald_square, 1)]),
  penn_station: set([(manhattan_mall, 3), (thirty_fourth_and_seventh, 1)]),
  thirty_fourth_and_madison: set([(thirty_third_and_madison, 1), (empire_state_building, 3), (thirty_fifth_and_madison, 1)]),
  empire_state_building: set([(thirty_fourth_and_madison, 3), (herald_square, 3), (thirty_third_and_fifth, 1), (cuny_grad_center, 1)]),
  herald_square: set([(empire_state_building, 3), (thirty_fourth_and_seventh, 3), (manhattan_mall, 1), (thirty_fifth_and_sixth, 1)]),
  thirty_fourth_and_seventh: set([(herald_square, 3), (macys, 1), (penn_station, 1)]),
  thirty_fifth_and_madison: set([(thirty_fourth_and_madison, 1), (thirty_sixth_and_madison, 1), (cuny_grad_center, 3)]),
  cuny_grad_center: set([(thirty_fifth_and_madison, 3), (thirty_fifth_and_sixth, 3), (empire_state_building, 1), (thirty_sixth_and_fifth, 1)]),
  thirty_fifth_and_sixth: set([(cuny_grad_center, 3), (macys, 3), (herald_square, 1), (thirty_sixth_and_sixth, 1)]),
  macys: set([(thirty_fifth_and_sixth, 3), (thirty_fourth_and_seventh, 1), (thirty_sixth_and_seventh, 1)]),
  thirty_sixth_and_madison: set([(thirty_sixth_and_fifth, 3), (thirty_fifth_and_madison, 1), (morgan_library, 1)]),
  thirty_sixth_and_fifth: set([(thirty_sixth_and_madison, 3), (thirty_sixth_and_sixth, 3), (cuny_grad_center, 1), (thirty_seventh_and_fifth, 1)]),
  thirty_sixth_and_sixth: set([(thirty_sixth_and_fifth, 3), (thirty_sixth_and_seventh, 3), (thirty_fifth_and_sixth, 1), (thirty_seventh_and_sixth, 1)]),
  thirty_sixth_and_seventh: set([(thirty_sixth_and_sixth, 3), (macys, 1), (thirty_seventh_and_seventh, 1)]),
  morgan_library: set([(thirty_seventh_and_fifth, 3), (thirty_sixth_and_madison, 1), (thirty_eighth_and_madison, 1)]),
  thirty_seventh_and_fifth: set([(morgan_library, 3), (thirty_seventh_and_sixth, 3), (thirty_sixth_and_fifth, 1), (thirty_eighth_and_fifth, 1)]),
  thirty_seventh_and_sixth: set([(thirty_seventh_and_fifth, 3), (thirty_seventh_and_seventh, 3), (thirty_sixth_and_sixth, 1)]),
  thirty_seventh_and_seventh: set([(thirty_seventh_and_sixth, 3), (thirty_sixth_and_seventh, 1), (thirty_eighth_and_seventh, 1)]),
  thirty_eighth_and_madison: set([(thirty_eighth_and_fifth, 3), (morgan_library, 1), (mexican_consulate, 1)]),
  thirty_eighth_and_fifth: set([(thirty_eighth_and_madison, 3), (thirty_eighth_and_sixth, 3), (thirty_seventh_and_fifth, 1), (thirty_ninth_and_fifth, 1)]),
  thirty_eighth_and_sixth: set([(thirty_eighth_and_fifth, 3), (thirty_eighth_and_seventh, 3), (thirty_seventh_and_sixth, 1), (thirty_ninth_and_sixth, 1)]),
  thirty_eighth_and_seventh: set([(thirty_eighth_and_sixth, 3), (thirty_seventh_and_seventh, 1), (thirty_ninth_and_seventh, 1)]),
  mexican_consulate: set([(thirty_ninth_and_fifth, 3), (thirty_eighth_and_madison, 1), (fortieth_and_madison, 1)]),
  thirty_ninth_and_fifth: set([(mexican_consulate, 3), (thirty_ninth_and_sixth, 3), (thirty_eighth_and_fifth, 1), (fortieth_and_fifth, 1)]),
  thirty_ninth_and_sixth: set([(thirty_ninth_and_fifth, 3), (thirty_ninth_and_seventh, 3), (thirty_eighth_and_sixth, 1), (bryant_park_south, 1)]),
  thirty_ninth_and_seventh: set([(thirty_ninth_and_sixth, 3), (thirty_eighth_and_seventh, 1), (times_square_south, 1)]),
  fortieth_and_madison: set([(fortieth_and_fifth, 3), (mexican_consulate, 1), (forty_first_and_madison, 1)]),
  fortieth_and_fifth: set([(fortieth_and_madison, 3), (bryant_park_south, 3), (thirty_ninth_and_fifth, 1)]),
  bryant_park_south: set([(fortieth_and_fifth, 3), (times_square_south, 3), (thirty_ninth_and_sixth, 1), (kinokuniya, 1)]),
  times_square_south: set([(bryant_park_south, 3), (times_square, 1), (thirty_ninth_and_seventh, 1)]),
  forty_first_and_madison: set([(fortieth_and_madison, 1), (grand_central_station, 1), (mid_manhattan_library, 3)]),
  mid_manhattan_library: set([(forty_first_and_madison, 3), (library, 1), (fortieth_and_fifth, 1)]),
  kinokuniya: set([(times_square, 3), (bryant_park_north, 1), (bryant_park_south, 1)]),
  times_square: set([(kinokuniya, 3), (times_square_north, 1), (times_square_south, 1)]),
  grand_central_station: set([(library, 3), (forty_first_and_madison, 1)]),
  library: set([(mid_manhattan_library, 1), (grand_central_station, 3), (bryant_park_north, 3)]),
  bryant_park_north: set([(library, 3), (times_square_north, 3), (bryant_park_south, 1)]),
  times_square_north: set([(times_square, 1), (bryant_park_north, 3)])
}
a = graph_vertex('a',0,0)
b = graph_vertex('b',1,0)
c = graph_vertex('c',2,0)
d = graph_vertex('d',3,0)
e = graph_vertex('e',1.5,1)
tester = {
  a:[[b,1],[e,2]],
  b:[[a,1],[c,1]],
  c:[[b,1],[d,1]],
  d:[[c,1],[e,2]],
  e:[[a,2],[d,2]]
}

print(get_path(a_star(euclidean_graph,bengaluru,jaipur)))
print(get_path(a_star(manhattan_graph,thirty_third_and_madison,times_square_north)))
print(get_path(a_star(tester,a,d)))
