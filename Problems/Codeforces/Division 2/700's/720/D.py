import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n = int(input())
    edges = [list(map(int,input().split())) for i in range(n-1)]

    adj = [set() for i in range(n+1)]

    for a,b in edges:
        adj[a].add(b)
        adj[b].add(a)

    operations = []

    visited = [0] * (n + 1)
    parent = [0]*(n+1)
    s = [1]
    while s:
        c = s[-1]

        if not visited[c]:
            visited[c] = 1

            for ne in adj[c]:
                if not visited[ne]:
                    parent[ne] = c
                    s.append(ne)
        else:
            if len(adj[c]) > 2:
                if parent[c]:
                    operations.append([c,parent[c]])
                    adj[parent[c]].remove(c)
                    adj[c].remove(parent[c])

                while len(adj[c]) > 2:
                    x = adj[c].pop()
                    adj[x].remove(c)
                    operations.append([x, c])

            s.pop()

    endpoints = []

    visited = [0]*(n+1)
    for i in range(1,n+1):
        if not visited[i]:
            endpoints.append([])

            s = [i]
            while s:
                c = s[-1]

                if not visited[c]:
                    visited[c] = 1

                    if len(adj[c]) <= 1:
                        endpoints[-1].append(c)

                    for ne in adj[c]:
                        s.append(ne)
                else:
                    s.pop()

    assert(len(operations) == len(endpoints) -1)

    for i in range(len(endpoints)-1):
        if len(endpoints[i]) == 1:
            endpoints[i].append(endpoints[i][0])

        operations[i].extend([endpoints[i][1],endpoints[i+1][0]])

    print(len(operations))
    for operation in operations:
        print(*operation)