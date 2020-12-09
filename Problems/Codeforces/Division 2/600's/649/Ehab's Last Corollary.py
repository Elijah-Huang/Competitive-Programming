import sys
input = sys.stdin.buffer.readline
from collections import deque
from math import ceil
def prog():
    n,m,k = map(int,input().split())
    adj_list = [[[],0] for i in range(n+1)]
    for _ in range(m):
        a,b = map(int,input().split())
        adj_list[a][0].append(b)
        adj_list[b][0].append(a)
    cycle_found = False
    visited = set()
    visited_s = set()
    done = set()
    s = deque([1])
    while s:
        curr = s[-1]
        visited.add(curr)
        visited_s.add(curr)
        if curr not in done:
            done.add(curr)
            for neighbor in adj_list[curr][0]:
                if neighbor in visited_s and (len(s) > 1 and neighbor != s[-2]):
                    cycle = [neighbor]
                    new = s.pop()
                    while new != neighbor:
                        cycle.append(new)
                        new = s.pop()
                    if len(cycle) <= k:
                        sys.stdout.write('2\n')
                        sys.stdout.write(str(len(cycle)) +'\n')
                        sys.stdout.write(" ".join(map(str,cycle)) + '\n')
                    else:
                        output = []
                        need = ceil(k/2)
                        idx = 0
                        while need:
                            output.append(cycle[idx])
                            idx += 2
                            need -= 1
                        sys.stdout.write('1\n')
                        sys.stdout.write(" ".join(map(str,output)) + '\n')
                    cycle_found = True
                    break
        if cycle_found:
            break
        had_neighbor = False
        for i in range(adj_list[curr][1],len(adj_list[curr][0])):
            neighbor = adj_list[curr][0][i]
            if neighbor not in visited:
                s.append(neighbor)
                adj_list[curr][1] = i+1
                had_neighbor = True
                break
        if not had_neighbor:
            visited_s.remove(s.pop())
    if not cycle_found:
        for i in range(1,n+1):
            adj_list[i][1] = 0
        first = set([1])
        second = set()
        visited = set()
        s = deque([1])
        while s:
            curr = s[-1]
            visited.add(curr)
            had_neighbor = False
            for i in range(adj_list[curr][1],len(adj_list[curr][0])):
                neighbor = adj_list[curr][0][i]
                if neighbor not in visited:
                    s.append(neighbor)
                    had_neighbor = True
                    adj_list[curr][1] = i+1
                    if curr in first:
                        second.add(neighbor)
                    else:
                        first.add(neighbor)
                    break
            if not had_neighbor:
                s.pop()
        need = ceil(k/2)
        if len(second) > len(first):
            sys.stdout.write('1\n')
            sys.stdout.write(" ".join(map(str,list(second)[:need])))
        else:
            sys.stdout.write('1\n')
            sys.stdout.write(" ".join(map(str,list(first)[:need])))
prog()
