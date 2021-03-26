import sys
input = sys.stdin.buffer.readline

n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))

two = -1
missing = -1

counts = [[] for i in range(n+1)]
for i in range(n):
    counts[a[i]].append(i)
    if len(counts[a[i]]) == 2:
        two = a[i]

for i in range(1,n+1):
    if len(counts[i]) == 0:
        missing = i
        break

def diff(a,b):
    diffs = 0
    for i in range(n):
        diffs += a[i]!=b[i]
    return diffs

for i in range(2):
    perm = a.copy()
    perm[counts[two][i]] = missing

    if diff(perm,b) == 1:
        print(*perm)
        break