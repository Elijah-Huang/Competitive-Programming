import sys
input = sys.stdin.buffer.readline

n = int(input())
adj = [[] for i in range(n+1)]
for i in range(n-1):
    a,b = map(int,input().split())
    adj[a].append(b)
    adj[b].append(a)

sub_sizes = [0]*(n+1)
s =[1]
vis = [0]*(n+1)
while s:
    c = s[-1]
    if not vis[c]:
        vis[c] = 1
        for ne in adj[c]:
            if not vis[ne]:
                s.append(ne)
    else:
        sub_sizes[c] = 1
        for ne in adj[c]:
            sub_sizes[c] += sub_sizes[ne]
        s.pop()

ans = curr = sum(sub_sizes)

vis = [0]*(n+1)
s = [1]
while s:
    c = s[-1]
    if not vis[c]:
        vis[c] = 1
        if c != 1:
            curr -= sub_sizes[c]
            curr += n - sub_sizes[c]
            ans = max(ans,curr)

        for ne in adj[c]:
            if not vis[ne]:
                s.append(ne)
    else:
        if c != 1:
            curr += sub_sizes[c]
            curr -= n - sub_sizes[c]
        s.pop()

print(ans)