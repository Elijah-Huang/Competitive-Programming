import sys
input = sys.stdin.buffer.readline

mn = 10**20
best_a = best_b = 0
n,a,b = map(int,input().split())
orga, orgb = a,b
if a > b:
    a,b = b,a

for i in range(a,10**5):
    l = b; r = 10**10
    while l != r:
        m = (l+r)//2

        if i*m >= 6*n:
            r = m
        else:
            l = m + 1

    if i*l < mn:
        mn = i*l
        best_a, best_b = i,l

if best_a != 0:
    if best_a < orga or best_b < orgb:
        best_a, best_b = best_b, best_a
    print(mn)
    print(best_a, best_b)
else:
    print(a*b)
    print(a,b)