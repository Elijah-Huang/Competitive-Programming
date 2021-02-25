# right now there is overcount but whatever it'll TLE the TLE correct solution is on cf
# c++ time :(
import sys
input = sys.stdin.buffer.readline

added = set()
possible = []
mx = 10**18

for i in range(1,1001):
    a = i**2
    if a not in added:
        possible.append(a)
        added.add(a)

for i in range(3,60):
    for j in range(2,10**6+1):
        a = j**i
        if a <= mx:
            if a not in added:
                possible.append(a)
                added.add(a)
        else:
            break

possible = [0] + list(dict(zip(possible, range(len(possible)))))
possible.sort()

def least_geq_square(x):
    base = int(x**0.5)
    if (base-1)**2 == x:
        return 1
    if base**2 == x:
        return 1
    if (base+1)**2 == x:
        return 1
    return 0

def lower_bound(x):
    l = 0; r = len(possible)-1

    while l != r:
        m = (l+r)//2
        if possible[m] >= x:
            r = m
        else:
            l = m + 1

    return l

for _ in range(int(input())):
    l,r = map(int,input().split())
    ans = 0

    # in set
    ans += lower_bound(r+1) - lower_bound(l)

    # poers of 2 above 10**6
    l = max(l,1001**2)
    if r >= l:
        ans += least_geq_square(r+1) - least_geq_square(l)

    print(ans)