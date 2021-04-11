import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n,p = map(int,input().split())
    a = list(map(int,input().split()))

    locs = []
    for i in range(n):
        locs.append([a[i],i])
    locs.sort()

    weight = 0
    comps = n
    used = [0]*n

    parent = list(range(n))
    sizes = [1]*n

    def find_parent(i):
        if parent[i] == i:
            return i
        parent[i] = find_parent(parent[i])
        return parent[i]

    def union_sets(a,b):
        a = find_parent(a)
        b = find_parent(b)
        if a != b:
            if sizes[a] < sizes[b]:
                a,b = b,a
            sizes[a] += sizes[b]
            parent[b] = a

    for mn, i in locs:
        if mn >= p:
            break

        if used[i]:
            continue

        l = i
        r = i
        while l > 0 and a[l-1] % mn == 0 and not used[l-1]:
            l -= 1
        while r < n-1 and a[r+1] % mn == 0 and not used[r+1]:
            r += 1

        if l != r:
            used[l] = 1
            for i in range(l+1,r+1):
                used[i] = 1
                union_sets(i-1,i)
            comps -= r - l
            weight += mn*(r-l)

        if l > 0 and a[l-1] % mn == 0:
            used[l] = 1
            union_sets(l-1,l)
            weight += mn
            comps -= 1
        if r < n-1 and a[r+1] % mn == 0:
            used[r] = 1
            union_sets(r,r+1)
            weight += mn
            comps -= 1

    print(weight + (comps-1)*p)