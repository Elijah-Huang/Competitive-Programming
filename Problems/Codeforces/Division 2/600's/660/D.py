import sys
from collections import deque
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(val)
    sys.stdout.write('\n')
def prog():
    n = int(input())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    
    for i in range(n):
        b[i] -= 1
    radj = [[] for i in range(n)]
    adj  = [0]*n
    roots = []
    for i in range(n):
        if b[i] != -2:
            radj[b[i]].append(i)
            adj[i] = b[i]
        else:
            adj[i] = -2
            roots.append(i)
            
    s = deque(roots)
    neg_vals = []
    moves = []
    visited = [0]*n
    ans = 0
    while s:
        curr = s[-1]
        if not visited[curr]:
            for neighbor in radj[curr]:
                s.append(neighbor)
            visited[curr] = 1
        else:
            ans += a[curr]
            if a[curr] > 0:
                moves.append(s.pop())
                if adj[curr] != -2:
                    a[adj[curr]] += a[curr]
            else:
                neg_vals.append(s.pop())

    moves.extend(reversed(neg_vals))
    print(str(ans))
    print(" ".join(map(str,map(lambda x: x + 1, moves))))
prog()
