import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        path = input().strip()
        visited = {}
        curr_location = [0,0]
        for i in range(1,n+1):
            move = path[i-1]
            location = tuple(curr_location)
            if location in visited:
                visited[location].append(i)
            else:
                visited[location] = [i]
            if move == 'L':
                curr_location[0] -= 1
            elif move == 'R':
                curr_location[0] += 1
            elif move == 'U':
                curr_location[1] += 1
            elif move == 'D':
                curr_location[1] -= 1
            new_location = tuple(curr_location)
            if new_location in visited:
                visited[new_location].append(i)
        cycles = {}
        for cycle in visited.values():
            if len(cycle) % 2 == 1:
                cycle.pop()
            for i in range(len(cycle)//2):
                start = cycle[2*i]
                stop = cycle[2*i+1]
                cycles[stop - start] = (start, stop)
        if len(cycles) == 0:
            print(-1)
        else:
            shortest = min(cycles)
            print(cycles[shortest][0], cycles[shortest][1])
prog()
