import sys
input = sys.stdin.buffer.readline

n,d = map(int,input().split())
d-=1

s = list(map(int,input().split()))
p = sorted(list(map(int,input().split())))

astronaut = s[d] + p[-1]

ptr = n - 2
decreased = 0
for i in range(d-1,-1,-1):
    while ptr >= 0 and p[ptr] + s[i] > astronaut:
        ptr -= 1

    if ptr < 0:
        break
    else:
        ptr -= 1
        decreased += 1

print(d - decreased + 1)