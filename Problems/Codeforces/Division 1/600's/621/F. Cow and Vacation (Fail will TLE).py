import sys
input = sys.stdin.buffer.readline
from collections import deque

class Union_Find:
    def __init__(self, n):
        self.n = n
        self.parent = list(range(n+1))
        self.size = [1]*(n+1)

    def find_parent(self, a):
        if self.parent[a] == a:
            return a
        self.parent[a] = self.find_parent(self.parent[a])
        return self.parent[a]

    def union_sets(self, a, b):
        a = self.find_parent(a)
        b = self.find_parent(b)

        if a != b:
            if self.size[a] < self.size[b]:
                a,b = b,a

            self.parent[b] = a
            self.size[a] += self.size[b]


n,k,r = map(int,input().split())

adj = [[] for i in range(n+1)]
for i in range(n-1):
    a,b = map(int,input().split())
    adj[a].append(b)
    adj[b].append(a)

rest = [0]*(n+1)
for i in list(map(int,input().split())):
    rest[i] = 1

v = int(input())

lca = [0]*(v)
queries = [list(map(int,input().split())) for i in range(v)]
lca_queries =[[] for i in range(n+1)]

for i in range(v):
    lca_queries[queries[i][0]].append([queries[i][1],i])
    lca_queries[queries[i][1]].append([queries[i][0],i])


q = deque()
dist = [10**6]*(n+1)
closest_rest = [0]*(n+1)
reachable = Union_Find(n)

for i in range(1,n+1):
    if rest[i]:
        dist[i] = 0
        closest_rest[i] = i
        q.append(i)

while q:
    curr = q.popleft()

    if dist[curr] < k:
        for ne in adj[curr]:
            if dist[ne] > dist[curr] + 1:
                dist[ne] = dist[curr] + 1
                reachable.union_sets(closest_rest[curr], ne)
                closest_rest[ne] = closest_rest[curr]
                q.append(ne)
            elif dist[ne] + dist[curr] + 1 <= k:
                reachable.union_sets(closest_rest[curr],closest_rest[ne])

# find lcas
s = [1]
ancestor = [0] * (n + 1)
ancestor_sets = Union_Find(n)
vis = [0]*(n+1)
par = [0]*(n+1)
dist = [0]*(n+1)

while s:
    curr = s[-1]

    if not vis[curr]:
        vis[curr] = 1
        ancestor[curr] = curr

        for query, idx in lca_queries[curr]:
            anc = ancestor[ancestor_sets.find_parent(query)]
            if anc:
                lca[idx] = anc

        for ne in adj[curr]:
            if not vis[ne]:
                s.append(ne)
                dist[ne] = dist[curr] + 1
                par[ne] = curr

    else:
        ancestor_sets.union_sets(curr,par[curr])
        ancestor[ancestor_sets.find_parent(curr)] = par[curr]
        s.pop()

for i in range(v):
    a,b = queries[i]
    print(lca[i])
    print(reachable.find_parent(a), reachable.find_parent(b))
    if dist[a] + dist[b] - 2*dist[lca[i]] <= k:
        print("YES")
    elif reachable.find_parent(a) == reachable.find_parent(b):
        print("YES")
    else:
        print("NO")
























