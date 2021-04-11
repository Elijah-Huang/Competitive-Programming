import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n,m = map(int,input().split())
    days = [list(map(int,input().split()))[1:] for i in range(m)]

    fail = False
    counts = [0]*(n+1)
    for d in days:
        if len(d) == 1:
            counts[d[0]] += 1
            if counts[d[0]] > (m+1)//2:
                fail = True

    if fail:
        print("NO")
    else:
        print("YES")

        friend = []
        for d in days:
            if len(d) == 1:
                friend.append(d[0])
            else:
                if counts[d[0]] < (m+1)//2:
                    friend.append(d[0])
                    counts[d[0]] += 1
                else:
                    # friend d[1] will not be used > (m+1)//2 times because
                    # friend d[0] used (m+1)//2 times already
                    friend.append(d[1])
                    counts[d[1]] += 1

        print(*friend)