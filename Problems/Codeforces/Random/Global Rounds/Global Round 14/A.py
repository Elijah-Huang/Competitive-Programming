import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n,x = map(int,input().split())

    w = list(map(int,input().split()))

    w.sort()

    tot = 0
    placed = []
    i = 0
    fail = 0
    while i != n:
        tot += w[i]

        if tot == x:
            if i == n-1:
                fail = 1
            else:
                placed.extend([w[i+1],w[i]])
                tot += w[i+1]
                i += 1
        else:
            placed.append(w[i])
        i += 1

    if fail:
        print("NO")
    else:
        print("YES")
        print(*placed)