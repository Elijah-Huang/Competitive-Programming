maxn = 2*10**5 + 5
bit = [0]*(maxn)

def add(idx):
    idx += 1
    while idx < maxn:
        bit[idx] += 1
        idx += idx & -idx

def sm(idx):
    idx += 1
    tot = 0
    while idx > 0:
        tot += bit[idx]
        idx -= idx & -idx

    return tot


n,t = map(int,input().split())
a = list(map(int,input().split()))

psum = [0]*(n+1)
for i in range(n):
    psum[i+1] = psum[i] + a[i]
psum.sort(reverse=True)
upsum = [-10**18]
for i in range(n+1):
    if i == 0 or psum[i] != psum[i-1]:
        upsum.append(psum[i])
upsum.sort(reverse = True)

def lower_bound(i):
    l = 0; r = len(upsum) - 1
    while l != r:
        m = (l+r)//2
        if upsum[m] <= i:
            r = m
        else:
            l = m + 1

    return l

ans = 0
curr = 0
add(lower_bound(0))
for i in a:
    curr += i
    ans += sm(lower_bound(curr-t)-1)
    add(lower_bound(curr))


print(ans)