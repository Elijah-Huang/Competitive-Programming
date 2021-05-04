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