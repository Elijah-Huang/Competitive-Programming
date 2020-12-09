n = int(input())
sectors = list(map(int,input().split()))
sectors.extend(sectors)
min_diff = 360
for i in range(n):
    total = 0
    for j in range(i, i + n):
        total += sectors[j]
        min_diff = min(min_diff, abs(total - (360 - total)))
print(min_diff)
