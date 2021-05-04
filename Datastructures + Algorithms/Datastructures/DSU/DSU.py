class Union_Find:
    def __init__(self, n):
        self.n = n
        self.parent = list(range(n+1))
        self.size = [1]*(n+1)

    def find_parent(self, a):
        if self.parent[a] == a:
            return a

        self.parent[a] = self.find_parent(self.parent[a])
        return self.parent[a]

    def union_sets(self, a, b):
        a = self.find_parent(a)
        b = self.find_parent(b)

        if a != b:
            if self.size[a] < self.size[b]:
                a,b = b,a

            self.parent[b] = a
            self.size[a] += self.size[b]