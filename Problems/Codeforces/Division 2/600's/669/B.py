from math import gcd

for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    mx = max(a)
    del a[a.index(mx)]

    out = [mx]

    curr_gcd = mx
    for i in range(n-1):
        bst_next = 0
        bst_gcd = 0
        for j in a:
            g = gcd(curr_gcd,j)
            if g > bst_gcd:
                bst_gcd = g
                bst_next = j

        out.append(bst_next)
        curr_gcd = bst_gcd
        del a[a.index(bst_next)]

    print(*out)