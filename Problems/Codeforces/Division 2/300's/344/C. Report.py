import sys
input = sys.stdin.buffer.readline

n,m = map(int,input().split())

a = list(map(int,input().split()))

s = []
for i in range(m):
    t,r = map(int,input().split())
    t -= 1
    r -= 1

    while s and s[-1][1] <= r: # operation will get overwritten so remove it
        s.pop()

    s.append([t,r])
s.append([-1,-1]) # dummy operation

sorted_slice = sorted(a[:s[0][1]+1])
# pointers for active part of slice
l = 0
r = s[0][1]

for i in range(len(s)-1):
    if s[i][0]:
        for j in range(s[i][1], s[i+1][1], -1):
            a[j] = sorted_slice[l]
            l += 1
    else:
        for j in range(s[i][1], s[i+1][1], -1):
            a[j] = sorted_slice[r]
            r -= 1

print(*a)