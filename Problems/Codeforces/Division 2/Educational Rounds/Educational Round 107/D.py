import sys
input = sys.stdin.buffer.readline

n,k = map(int,input().split())

adj = [list(range(k)) for i in range(k)]

path = []
stack = [0]
while stack:
    if len(adj[stack[-1]]) == 0:
        path.append(stack.pop())
    else:
        stack.append(adj[stack[-1]].pop())

out = [chr(ord('a') + path[0])]
for i in range(n-1):
    out.append(chr(ord('a') + path[i%(len(path)-1) + 1]))

print(''.join(out))