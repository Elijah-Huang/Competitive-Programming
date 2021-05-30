import sys
input = sys.stdin.readline

# all operations are log(n)
class bit:
    def __init__(self, n):
        self.n = n+1
        self.mx_p = 0
        while 1 << self.mx_p < self.n:
            self.mx_p += 1
        self.a = [0]*(self.n)
        self.tot = 0

    def add(self, idx, val):
        self.tot += val
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

    def sum(self, l, r):
        return self.sum_prefix(r) - self.sum_prefix(l-1)

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

n = int(input())
s = input().strip()
s_reversed = s[::-1]

print(inversions(create_c(s,s_reversed)))