from collections import deque
def prog():
    with open('clocktree.in') as fin:
        n = int(fin.readline())
        nums = list(map(int,fin.readline().split()))
        adj_list = [[[],0] for i in range(n+1)]
        for i in range(n-1):
            a,b = map(int,fin.readline().split())
            adj_list[a][0].append(b)
            adj_list[b][0].append(a)
    visited = set()
    s = deque([1])
    two_away = set()
    one_away = set()
    while s:
        curr = s[-1]
        visited.add(curr)
        if len(s) % 2 == 1:
            two_away.add(curr)
        else:
            one_away.add(curr)
        had_neighbor = False
        for i in range(adj_list[curr][1],len(adj_list[curr][0])):
            neighbor = adj_list[curr][0][i]
            if neighbor not in visited:
                had_neighbor = True
                s.append(neighbor)
                adj_list[curr][1] = i+1
                break
        if not had_neighbor:
            s.pop()
    for i in range(1,n+1):
        adj_list[i][1] = 0
    s = deque([1])
    visited = set()
    nums[0] -= 1
    while s:
        curr = s[-1]
        visited.add(curr)
        nums[curr -1] = (nums[curr - 1] + 1 ) % 12
        had_neighbor = False
        for i in range(adj_list[curr][1],len(adj_list[curr][0])):
            neighbor = adj_list[curr][0][i]
            if neighbor not in visited:
                had_neighbor = True
                s.append(neighbor)
                adj_list[curr][1] = i+1
                break
        if not had_neighbor:
            if len(s) > 1:
                nums[s[-2]-1] = (nums[s[-2]-1] + 12 - nums[curr-1]) % 12
            s.pop()
    if (nums[0] % 12) == 0:
        ans = n
    elif (nums[0] % 12) == 1:
        ans = len(two_away)
    elif (nums[0] % 12) == 11:
        ans = len(one_away)
    else:
        ans = 0
    with open('clocktree.out','w') as fout:
        fout.write(str(ans) + '\n')
prog()
        
                    
        
