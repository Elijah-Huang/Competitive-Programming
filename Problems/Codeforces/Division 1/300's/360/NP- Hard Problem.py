import sys
input = sys.stdin.buffer.readline
from collections import deque
def prog():
    n,m = map(int,input().split())
    adj_list = [[] for i in range(n+1)]
    for i in range(m):
        a,b = map(int,input().split())
        adj_list[a].append(b)
        adj_list[b].append(a)
    locations = [-1 for i in range(n+1)]
    visited = set()
    impossible = False
    for start in range(1,n+1):
        if impossible == True:
            break
        if start in visited or len(adj_list[start]) == 0:
            continue
        s = deque([0,start])
        while len(s) > 1 and not impossible:
            curr = s[-1]
            if curr not in visited:
                locations[curr] = (locations[s[-2]] + 1) % 2
                visited.add(curr)
            had_neighbor = False
            for i in range(len(adj_list[curr])):
                neighbor = adj_list[curr].pop()
                if neighbor not in visited:
                    had_neighbor = True
                    s.append(neighbor)
                    break
                else:
                    if locations[curr] != (locations[neighbor] + 1) % 2:
                        impossible = True
                        break
            if not had_neighbor:
                s.pop()
    if impossible == True:
        print(-1)
    else:
        first_cover = []
        second_cover = []
        for i in range(1,n+1):
            if locations[i] == 0:
                first_cover.append(str(i))
            elif locations[i] == 1:
                second_cover.append(str(i))
        print(len(first_cover))
        print(" ".join(first_cover))
        print(len(second_cover))
        print(" ".join(second_cover))
prog()
            
                
            
