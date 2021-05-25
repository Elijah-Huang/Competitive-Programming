import sys
input = sys.stdin.buffer.readline


n = int(input())
a = list(map(int,input().split()))

locs = []
mn = min(a)

for i in range(n):
    if a[i] == mn:
        locs.append(i)

mn_dist = 1e9

for i in range(len(locs)-1):
    mn_dist = min(mn_dist, locs[i+1] - locs[i])

print(mn_dist)