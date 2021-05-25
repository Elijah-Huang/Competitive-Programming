import sys
input = sys.stdin.buffer.readline

class bit:
    def __init__(self, n):
        self.n = n
        self.a = [0]*(n+1)

    def add(self, idx, val):
        idx += 1
        while idx < self.n:
            self.a[idx] += val
            idx += idx & -idx

    def sumr(self, idx):
        idx += 1
        tot = 0
        while idx:
            tot += self.a[idx]
            idx -= idx & -idx

        return tot

    def sum(self, l, r):
        return self.sumr(r) - self.sumr(l-1)

def add(i):
    bit2.add(tin[i], 1)
    bit1.add(tin[i], i)
    bit1.add(tout[i] + 1, -i)

def remove(i):
    bit2.add(tin[i], -1)
    bit1.add(tin[i], -i)
    bit1.add(tout[i] + 1, i)

for _ in range(int(input())):
    n = int(input())

    adj = [[[] for i in range(n+1)] for j in range(2)]

    for k in range(2):
        a = list(map(int,input().split()))

        for i in range(2,n+1):
            adj[k][a[i-2]].append(i)

    ans = 0

    # we use tin and tout so we can determine if a node is an ancestor of another
    tin = [0]*(n+1)
    tout = [0]*(n+1)
    t = -1
    s = [1]
    visited = [0]*(n+1)

    while s:
        c = s[-1]

        if not visited[c]:
            t += 1
            tin[c] = t

            visited[c] = 1

            for ne in adj[1][c]:
                if not visited[ne]:
                    s.append(ne)
        else:
            tout[c] = t

            s.pop()

    curr_mx = 0
    # we use the bits to keep track of the maximum set of nodes such that no node
    # is an ancestor of another in keshi's tree
    # the tin and tout form disjoint ranges and we keep the max width range if they intersect
    bit1 = bit(n+1)
    bit2 = bit(n+1)
    ops = []  # to undo operations to bits [u,v] -> u was removed v was added

    s = [1]
    visited = [0] * (n + 1)

    while s:
        c = s[-1]

        if not visited[c]:
            visited[c] = 1

            # update set of max elements (implicitly represented by bit1 and bit2)
            u = bit1.sumr(tin[c])
            if u:
                # c is in the subtree of one of the nodes in the set, which we call u.
                # range for c is smaller so add c and remove u
                remove(u)
                add(c)
                ops.append([u,c])

            elif bit2.sum(tin[c],tout[c]):
                # c is the ancestor of one of the nodes in the set
                # range for c is larger so don't add it
                ops.append([0, 0])
            else:
                # c is a new disjoint range so add it
                add(c)
                curr_mx += 1
                ops.append([0,c])

            ans = max(ans, curr_mx)

            for ne in adj[0][c]:
                if not visited[ne]:
                    s.append(ne)
        else:
            # undo operation
            u,v = ops.pop()

            if u:
                add(u)
                curr_mx += 1
            if v:
                remove(v)
                curr_mx -= 1

            s.pop()

    print(ans)