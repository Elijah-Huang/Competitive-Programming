"""
ID: elijahj1
TASK: cowtour
LANG: PYTHON3
"""
from math import inf


def distance(position,i,j):
    return ((position[i][0] - position[j][0])**2 + (position[i][1] - position[j][1])**2)**0.5


def dfs(start,adj_matrix,n,components,which_component,curr_component,visited):
    for i in range(n):
        if adj_matrix[start][i] == '1' and i not in visited:
            components[-1].append(i)
            which_component[i] = curr_component
            visited.add(i)
            dfs(i,adj_matrix,n,components,which_component,curr_component,visited)


def generate_components(adj_matrix,n):
    components = []
    which_component = {}
    curr_component = -1
    for i in range(n):
        if which_component.get(i) is None:
            curr_component += 1
            start = i
            components.append([start])
            which_component[start] = curr_component
            dfs(start,adj_matrix,n,components,which_component,curr_component,set([start]))
    return components, which_component        


def shortest_paths(adj_matrix,positions,components,n):
    distances = [[inf for i in range(n)] for j in range(n)]
    for component in components:
        for i in component:
            for j in component:
                if i == j:
                    distances[i][j] = 0
                elif adj_matrix[i][j] == '0':
                    continue
                else:
                    distance1 = distance(positions,i,j)
                    distances[i][j] = distance1
        for k in component:
            for i in component:
                for j in component:
                    if distances[i][k] + distances[k][j] < distances[i][j]:
                        distances[i][j] = distances[i][k] + distances[k][j]
    return distances


def max_paths(components,distances,n):
    longest = [0 for i in range(n)]
    longest_comp = []
    for component in components:
        for i in component:
            new_longest = []
            for j in component:
                new_longest.append(distances[i][j])
            longest[i] = max(new_longest)
        new1_longest = []
        for i in component:
            new1_longest.append(longest[i])
        longest_comp.append(max(new1_longest))
    return longest, longest_comp  


def smallest_diameter(longest,longest_comp,distances,components,which_component,positions,distance,n):
    combined_distances = []
    for i in range(n-1):
        for j in range(i+1,n):
            if which_component[i] == which_component[j]:
                continue
            combined_distances.append(max([longest_comp[which_component[i]], longest_comp[which_component[j]], (distance(positions,i,j)+longest[i] + longest[j])]))
    return min(combined_distances)


with open('cowtour.in') as fin:
    n = int(fin.readline())
    positions = []
    for i in range(n):
        positions.append(list(map(int,fin.readline().split())))
    adj_matrix = [line for line in fin.readlines()]
components, which_component = generate_components(adj_matrix,n)
distances = shortest_paths(adj_matrix,positions,components,n)
longest, longest_comp = max_paths(components, distances, n)
smallest_combined = smallest_diameter(longest,longest_comp,distances,components,which_component,positions,distance,n)
with open('cowtour.out','w') as fin:
    fin.write('%0.6f' % smallest_combined + '\n')
    


    
