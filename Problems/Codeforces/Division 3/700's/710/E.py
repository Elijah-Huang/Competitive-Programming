# O(n) via linked lists probably can use stack too
import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n = int(input())
    q = list(map(int,input().split()))

    mn = []*n
    mx = []*n

    nxt = [i+1 for i in range(n + 2)]
    prv = [i-1 for i in range(n + 2)]
    for i in range(n):
        if i == 0 or q[i] != q[i-1]:
            mn.append(q[i])
            nxt[prv[q[i]]] = nxt[q[i]]
            prv[nxt[q[i]]] = prv[q[i]]
        else:
            mn.append(nxt[0])
            nxt[0] = nxt[nxt[0]]
            prv[nxt[0]] = 0

    prev = [i-1 for i in range(n + 2)]
    for i in range(n):
        if i == 0 or q[i] != q[i-1]:
            mx.append(q[i])
            prev[q[i]+1] = prev[q[i]]
        else:
            mx.append(prev[q[i]+1])
            prev[q[i]+1] = prev[prev[q[i]+1]]

    print(*mn)
    print(*mx)