def prog():
    with open('swap.in') as fin:
        n,m,k = map(int,fin.readline().split())
        swaps = [list(map(int,fin.readline().split())) for i in range(m)]
    cows = [i for i in range(n)]
    for a,b in swaps:
        a -= 1
        b -= 1
        cows = cows[:a] + cows[b:a:-1] + [cows[a]] + cows[b+1:]
    to_where = [0]*n
    for i in range(n):
        cow = cows[i]
        to_where[cow] = i
    in_cycle = [False for i in range(n)]
    cycles = []
    for i in range(n):
        if not in_cycle[i]:
            first = i
            new_cycle = [first]
            in_cycle[first] = True
            next_loc = to_where[new_cycle[-1]]
            while next_loc != first:
                new_cycle.append(next_loc)
                in_cycle[next_loc] = True
                next_loc = to_where[next_loc]
            cycles.append(new_cycle)
    final_order = [0]*n
    for cycle in cycles:
        length = len(cycle)
        delta = k % length
        for i in range(length):
            cow = cycle[i] + 1
            final_order[cycle[(i+delta) % length]] = str(cow)
    with open('swap.out','w') as fout:
        fout.write("\n".join(final_order) + '\n')
prog()
                
