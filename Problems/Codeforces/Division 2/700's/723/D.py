import sys
input = sys.stdin.readline
from itertools import permutations

# all operations are log(n)
class bit:
    def __init__(self, n):
        self.n = n+1
        self.a = [0]*(self.n)

    def add(self, idx, val):
        idx += 1
        while idx < self.n:
            self.a[idx] += val
            idx += idx & -idx

    def sum_prefix(self, idx):
        tot = 0
        idx += 1
        while idx > 0:
            tot += self.a[idx]
            idx -= idx & -idx

        return tot

# inversions of a permutation 0..len(a)-1
def inversions(a):
    tot = 0

    loc = [0]*len(a)

    for i in range(len(a)):
        loc[a[i]] = i

    bt = bit(len(a))

    for i in range(len(a)-1,-1,-1):
        tot += bt.sum_prefix(loc[i])
        bt.add(loc[i],1)

    return tot

# creates array c where c[i] = position of a[i] in b
def create_c(a,b):
    c = [0]*len(a)
    idx = {}
    positions = {}

    for i in range(len(b)):
        if b[i] in positions:
            positions[b[i]].append(i)
        else:
            positions[b[i]] = [i]

    for i in range(len(a)):
        if a[i] in idx:
            idx[a[i]] += 1
        else:
            idx[a[i]] = 0

        c[i] = positions[a[i]][idx[a[i]]]

    return c

for _ in range(int(input())):
    a = input().strip()

    if len(a) <= 2:
        print(a[::-1])
        continue

    counts = dict(zip("ANTO",[0]*4))

    for i in a:
        counts[i] += 1

    best_perm = None
    best_perm_cost = -1

    for order in permutations("ANTO"):
        final_perm = ''.join([char*counts[char] for char in order])

        cost = inversions(create_c(a,final_perm))

        if cost > best_perm_cost:
            best_perm = final_perm
            best_perm_cost = cost

    print(best_perm)