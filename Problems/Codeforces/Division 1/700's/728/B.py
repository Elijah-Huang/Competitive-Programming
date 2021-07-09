# O(n^3)
import sys
input = sys.stdin.buffer.readline

maxn = 300
mod = 10**9 + 7
fac = [0]*(maxn+1)
inv_fac = [0]*(maxn+1)

fac[0] = 1
for i in range(1,maxn+1):
    fac[i] = fac[i-1] * i % mod

inv_fac[maxn] = pow(fac[maxn],mod-2,mod)
for i in range(maxn-1,-1,-1):
    inv_fac[i] = inv_fac[i+1] * (i+1) % mod

def choose(n,k):
    if k > n:
        return 0
    return fac[n] * inv_fac[k] * inv_fac[n-k] % mod

inv_p = [0]*(300)
inv_p[1] = inv_fac[2]

for i in range(2,300):
    inv_p[i] = inv_p[1]*inv_p[i-1]%mod


n = int(input())

adj = [[] for i in range(n+1)]

for i in range(n-1):
    a,b = map(int,input().split())
    adj[a].append(b)
    adj[b].append(a)

ans = 0

line_prob = [[0]*(n+1) for i in range(n+1)] # i from smaller j from larger

for j in range(1,n+1):
    tot = 0
    for i in range(n+1-j):
        tot += choose(j-1+i,i)*inv_p[j-1+i+1]%mod

        line_prob[i+1][j] = tot

for root in range(1,n+1):
    size_of_sub = [0]*(n+1)

    # compute size of sub
    s = [root]
    vis = [0]*(n+1)
    par = [0]*(n+1)

    while s:
        c = s[-1]

        if not vis[c]:
            vis[c] = 1

            for ne in adj[c]:
                if not vis[ne]:
                    par[ne] = c
                    s.append(ne)
        else:
            size_of_sub[c] += 1
            size_of_sub[par[c]] += size_of_sub[c]

            s.pop()

    # compute answer
    s = [root]
    vis = [0] * (n + 1)
    path = [] # num of nodes at each depth on the path where ancestor
    # = node at this depth but no nodes deeper on path

    while s:
        c = s[-1]

        if not vis[c]:
            vis[c] = 1

            if len(path):
                path[-1] -= size_of_sub[c]
            path.append(size_of_sub[c])

            # compute ans
            if c > root:
                #print(root,c,path)

                ln = len(path)-1
                for depth in range(1,ln):
                    #print(depth,ln-depth,line_prob[depth][ln-depth])
                    ans = (ans + path[depth]*line_prob[depth][ln-depth]%mod)

                ans = (ans + size_of_sub[c]) % mod

            for ne in adj[c]:
                if not vis[ne]:
                    s.append(ne)
        else:
            if len(path) >= 2:
                path[-2] += path[-1]
            path.pop()

            s.pop()

print(ans*pow(n,mod-2,mod)%mod)