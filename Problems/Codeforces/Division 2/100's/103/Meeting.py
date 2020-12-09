def dist(x1,y1,x2,y2):
    return (x1-x2)**2 + (y1-y2)**2

x1,y1,x2,y2 = map(int,input().split())
x3 = min(x1,x2)
x4 = max(x1,x2)
y3 = min(y1,y2)
y4 = max(y1,y2)
x1 = x3
x2 = x4
y1 = y3
y2 = y4
n = int(input())
radiators = []
for i in range(n):
    a,b,c = map(int,input().split())
    radiators.append([a,b,c])
warm = set()
for r in radiators:
    for x in range(x1,x2 + 1):
        if dist(x,y1,r[0],r[1]) <= r[2]**2:
            warm.add((x,y1))
        if dist(x,y2,r[0],r[1]) <= r[2]**2:
            warm.add((x,y2))
    for y in range(y1,y2 + 1):
        if dist(x1,y,r[0],r[1]) <= r[2]**2:
            warm.add((x1,y))
        if dist(x2,y,r[0],r[1]) <= r[2]**2:
            warm.add((x2,y))
print(2*(y2 - y1 -1 + x2 - x1 + 1) - len(warm))
