n = int(input())
p = list(map(int,input().split()))
avg_photos = 0

for i in range(n):
  for j in range(i,n):
    tot = 0
    for k in range(i,j+1):
      tot += p[k]

    if tot % (j-i+1) == 0:
      avg = tot//(j-i+1)
      for k in range(i,j+1):
        if p[k] == avg:
          avg_photos += 1  
          break

print(avg_photos)
