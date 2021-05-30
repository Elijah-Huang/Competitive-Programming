# optimal answer must be to choose the diameter then remove leaves not on
# the diameter then remove the diameter
# for every leaf removed, the answer is maximal since otherwise we did not choose
# the diameter. When removing the diameter, clearly the maximal answer is
# # nodes left - 1 and this is achieved everytime
import sys
input = sys.stdin.buffer.readline

n = int(input())

adj =[[] for i in range(n+1)]

for i in range(n-1):
    a,b = map(int,input().split())
    adj[a].append(b)
    adj[b].append(a)

dist1 = [0]*(n+1)
dist2 = [0]*(n+1)
diameter = []
on_diameter = [0]*(n+1)

s = [1]
path = []
vis = [0]*(n+1)
while s:
    c = s[-1]

    if not vis[c]:
        vis[c] = 1
        path.append(c)
        dist1[c] = len(path)-1

        for ne in adj[c]:
            if not vis[ne]:
                s.append(ne)

    else:
        path.pop()
        s.pop()

mx_dist = 0
endpoint1 = 0
for i in range(1,n+1):
    if dist1[i] > mx_dist:
        mx_dist = dist1[i]
        endpoint1 = i

s = [endpoint1]
path = []
vis = [0] * (n + 1)
while s:
    c = s[-1]

    if not vis[c]:
        vis[c] = 1
        path.append(c)
        dist1[c] = len(path) - 1

        for ne in adj[c]:
            if not vis[ne]:
                s.append(ne)

    else:
        path.pop()
        s.pop()

mx_dist = 0
endpoint2 = 0
for i in range(1, n + 1):
    if dist1[i] > mx_dist:
        mx_dist = dist1[i]
        endpoint2 = i

s = [endpoint2]
path = []
vis = [0] * (n + 1)
while s:
    c = s[-1]

    if not vis[c]:
        vis[c] = 1
        path.append(c)

        if c == endpoint1:
            diameter = path.copy()

        dist2[c] = len(path) - 1

        for ne in adj[c]:
            if not vis[ne]:
                s.append(ne)

    else:
        path.pop()
        s.pop()

for i in diameter:
    on_diameter[i] = 1


mx_answer = 0
operations = []

leaves = []
for i in range(1,n+1):
    if len(adj[i]) == 1 and not on_diameter[i]:
        leaves.append(i)

degree = [len(adj[i]) for i in range(n+1)]

while leaves:
    c = leaves.pop()

    if dist1[c] > dist2[c]:
        mx_answer += dist1[c]
        operations.append([endpoint1,c,c])
    else:
        mx_answer += dist2[c]
        operations.append([endpoint2,c,c])

    for ne in adj[c]:
        degree[ne] -= 1
        if degree[ne] == 1:
            leaves.append(ne)

while len(diameter) > 1:
    c = diameter.pop()

    mx_answer += dist2[c]
    operations.append([endpoint2,c,c])


print(mx_answer)
for operation in operations:
    print(*operation)