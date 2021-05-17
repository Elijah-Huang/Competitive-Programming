import sys
input = sys.stdin.buffer.readline

n = int(input())

ord = [0]*n

next = {}
prev = {}

neighbors = [list(map(int,input().split())) for i in range(n)]

for i in range(n):
    a,b = neighbors[i]
    next[a] = b
    prev[b] = a

# find even positions
loc = 1
curr = next[0]
while True:
    ord[loc] = curr
    if curr in next and next[curr] != 0:
        loc += 2
        curr = next[curr]
    else:
        break

if n % 2 == 0:
    # prev[0] would be last even position
    loc = n-2
    curr = prev[0]
else:
    # prev[0] is last odd position, so n-1 is last even position

    occur_once = []  # will contain right endpoint
    for i in range(n):
        for j in neighbors[i]:
            if not (j in next and j in prev):
                occur_once.append(j)
    if occur_once[0] in next:
        occur_once.pop(0)
    else:
        occur_once.pop(1)

    loc = n-1
    curr = occur_once[0]

# find odd positions
while True:
    ord[loc] = curr
    if curr in prev and prev[curr] != 0:
        loc -= 2
        curr = prev[curr]
    else:
        break

print(*ord)