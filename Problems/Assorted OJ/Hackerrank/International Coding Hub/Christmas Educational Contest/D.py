import sys
input = sys.stdin.buffer.readline

#provably wrong heuristic solution
def prog():
    n,m = map(int,input().split())
    a = list(map(int,input().split()))
    pairs = 0
    locs = [[] for i in range(m+1)]
    ptr = 1

    for i in range(n):
        locs[a[i]].append(i)
        
    while ptr != n:
        if a[ptr] != a[ptr-1] and locs[a[ptr-1]][-1] != ptr-1:
            s1 = a[ptr]
            s2 = a[ptr-1]
            if len(locs[s1]) < len(locs[s2]):
                s3 = s1
                s1 = s2
                s2 = s3

            for i in locs[s2]:
                a[i] = s1
            locs[s1].extend(locs[s2])

            pairs += 1

        ptr += 1

    print(pairs)
    
prog()

        
