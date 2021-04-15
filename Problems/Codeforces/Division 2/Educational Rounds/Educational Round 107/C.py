import sys
input = sys.stdin.buffer.readline

n,q = map(int,input().split())
a = list(map(int,input().split()))
q = list(map(int,input().split()))

pos = [0]*51

for i in range(n):
    if pos[a[i]] == 0:
        pos[a[i]] = i+1

for i in q:
    print(pos[i])

    for j in range(1,51):
        if pos[j] < pos[i]:
            pos[j] += 1
    pos[i] = 1
