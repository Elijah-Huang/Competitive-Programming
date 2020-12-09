n,m = map(int,input().split())
lot = []
for i in range(n):
    lot.append(list(map(int,input().split())))
a,b = map(int,input().split())

mn = 2500
for i in range(n-a+1):
    for j in range(m-b+1):
        curr = 0
        for i2 in range(i, i+a):
            for j2 in range(j, j + b):
                curr += lot[i2][j2]
        mn = min(mn, curr)

for i in range(n-b+1):
    for j in range(m-a+1):
        curr = 0
        for i2 in range(i, i+b):
            for j2 in range(j, j + a):
                curr += lot[i2][j2]
        mn = min(mn, curr)
        
print(mn)
        
