import sys
input = sys.stdin.buffer.readline

n,m = map(int,input().split())

adj = [set() for i in range(n+1)]
for i in range(m):
    x,y = map(int,input().split())
    adj[x].add(y)
    adj[y].add(x)

unpaired = set([i for i in range(1,n+1)])
comps = []
vis = [0]*(n+1)

for i in range(1,n+1):
    if not vis[i]:
        comps.append(0)
        s = [i]

        while s:
            c = s[-1]

            if not vis[c]:
                comps[-1] += 1
                vis[c] = 1

                remove = []
                for ne in unpaired:
                    if ne not in adj[c]:
                        remove.append(ne)
                        s.append(ne)

                for ne in remove:
                    unpaired.remove(ne)

            else:
                s.pop()

print(len(comps))
print(*sorted(comps))