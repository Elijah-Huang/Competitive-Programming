import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
#from collections import OrderedDict
def prog():
    n = int(input())
    adj_list = [[] for i in range(n+1)]
    index_edges = {}
    for _ in range(n-1):
        a,b = map(int, input().split())
        adj_list[a].append(b)
        adj_list[b].append(a)
        index_edges[(a,b)] = None
    had3 = False
    for node in range(1,n+1):
        neighbors = adj_list[node]
        if len(neighbors) >= 3:
            for i in range(3):
                if (node,neighbors[i]) in index_edges:
                    index_edges[(node,neighbors[i])] = i
                else:
                    index_edges[(neighbors[i],node)] = i
            had3 = True
            break
    if had3:
        curr = 3
        for value in index_edges.values():
            if value is None:
                print(curr)
                curr += 1
            else:
                print(value)
    else:
        curr = 2
        smallest = 0
        for edge in index_edges:
            if len(adj_list[edge[0]]) + len(adj_list[edge[1]]) > 3:
                print(curr)
                curr += 1
            else:
                print(smallest)
                smallest += 1
prog()
            
    
