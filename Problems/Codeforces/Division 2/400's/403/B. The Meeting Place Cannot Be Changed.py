import sys
input = sys.stdin.buffer.readline

n = int(input())
x = list(map(float,input().split()))
v = list(map(float,input().split()))

def time(loc):
    min_t = 0
    for i in range(n):
        min_t = max(min_t, abs(x[i]-loc)/v[i])
    return min_t

l = 1; r = 1e9
for i in range(100):
    d = (r-l)/3

    if time(l+d) > time(r-d):
        l = l+d
    else:
        r = r-d

print(time((r+l)/2))