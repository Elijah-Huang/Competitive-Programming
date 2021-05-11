import sys
input = sys.stdin.buffer.readline

def query(t,i,j,x):
    print("?",t,i,j,x)
    sys.stdout.flush()
    return int(input())

for _ in range(int(input())):
    n = int(input())

    perm = [1]*(n)

    loc = 0
    # floor(n/2) + 2 queries
    for i in range(n//2):
        a = query(2,2*i+1,2*i+2,1)

        # additional check happens at most 2 times 1 for x 1 and 1 time for 2 x or x 2 x >= 3
        if a == 1:
            loc = 2*i+1
            break
        elif a == 2:
            b = query(2,2*i+2,2*i+1,1)

            if b == 1:
                loc = 2*i + 2
                break
    if loc == 0:
        loc = n

    # n-1 ops
    for i in range(1,n+1):
        if i != loc:
            perm[i-1] = query(1,loc,i,n-1)

    print("!", *perm)
    sys.stdout.flush()
