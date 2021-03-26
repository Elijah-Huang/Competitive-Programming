n = int(input())
p = [0]*2+list(map(int,input().split()))

c = n
path = [n]
while c != 1:
    c = p[c]
    path.append(c)
print(*path[::-1])
