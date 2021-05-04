import sys
input = sys.stdin.buffer.readline

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

    # lowest idx such that sum_prefix(idx) = val else -1 if idx doesn't exist
    # idx is the idx in the underlying array (idx-1)
    def lower(self, val):
        if val > self.tot:
            return -1

        tot = 0
        idx =  0
        for i in range(self.mx_p, -1, -1):
            if idx + (1<<i) < self.n and tot + self.a[idx + (1 << i)] < val:
                tot += self.a[idx + (1 << i)]
                idx += 1 << i

        return idx

n = int(input())
p = list(map(int,input().split()))
p = sorted([[p[i],i] for i in range(n)])

ones = bit(n+1) # 1 at positions
ones_idx = bit(n+1) # indices at positions
inversions = 0

for k in range(1,n+1):
    val, i = p[k-1]
    ones.add(i,1)
    ones_idx.add(i,i)
    inversions += ones.sum(i+1,n)

    num1l = (k+1)//2
    num1r = k - num1l
    idxl = ones.lower((k+1)//2)
    idxr = idxl + 1
    num0l = idxl+1 - num1l
    num0r = n - idxr - num1r
    suml = ones_idx.sum_prefix(idxl)
    sumr = ones_idx.tot - suml

    movel = idxl*(idxl+1)//2 - suml - (num0l - 1)*(num0l)//2
    mover = (n-1-idxr)*(n-1-idxr+1)//2 - (num1r*(n-1) - sumr) - (num0r-1)*(num0r)//2

    print(inversions + movel + mover)