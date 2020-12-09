n,m = map(int,input().split())
d = {}
for i in range(m):
    a,b = input().split()
    if len(a) <= len(b):
        d[b] = a
        d[a] = a
    else:
        d[a] = b
        d[b] = b
lecture = input().split()
output = []
for w in lecture:
    output.append(d[w])
print(*output)
