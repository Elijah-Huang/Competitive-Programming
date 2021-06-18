n,k = map(int,input().split())

l = 1
r = 10**10

while l != r:
    m = (l+r)//2

    tot = 0
    p = 0
    while m >= pow(k,p):
        tot += m//pow(k,p)
        p += 1

    if tot >= n:
        r = m
    else:
        l = m+1

print(l)