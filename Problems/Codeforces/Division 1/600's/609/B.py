n = int(input())
a = list(map(int,input().split()))

counts = [0]*2
for i in range(n):
    counts[i&1] += a[i]//2 #use i&1 so it alternates since coloring as checkerboard
    counts[i&1^1] += (a[i]+1)//2

print(min(counts))