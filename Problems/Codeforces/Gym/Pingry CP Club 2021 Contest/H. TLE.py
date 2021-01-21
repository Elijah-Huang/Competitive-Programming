import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')

def prog():
    n,m = map(int,input().split())
    friendships2 = [list(map(int,input().split())) for i in range(m)]
    friendships = [[] for i in range(n+1)]
    mod = 10**9 + 7
    clique_scores = [1]*(n+1)
    community_score = 1
    
    for i in range(m):
        friendships[friendships2[i][2]].append(friendships2[i])

    parent = list(range(n+1))
    sizes = [1]*(n+1)
    def find_parent(v):
        if v == parent[v]:
            return v
        parent[v] = find_parent(parent[v])
        return parent[v]

    def union_sets(friendship):
        a,b,t = friendship
        a = find_parent(a)
        b = find_parent(b)

        if a != b:
            if sizes[a] < sizes[b]:
                a,b = b,a

            parent[b] = a
            sizes[a] += sizes[b]

            return [a,b]
        else:
            return 0
        
    for i in range(1,n+1):
        for friendship in friendships[i]:
            ret = union_sets(friendship)
            if ret != 0:
                a,b = ret
                t =friendship[2]
                community_score *= pow((clique_scores[a]*clique_scores[b])%mod,mod-2,mod)
                community_score %= mod
                clique_scores[a] += clique_scores[b] + t
                clique_scores[a] %= mod
                community_score *= clique_scores[a]
                community_score %= mod

        print(community_score)
    
prog()
