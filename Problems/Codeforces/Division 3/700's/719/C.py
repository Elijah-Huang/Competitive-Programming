import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n = int(input())

    if n == 2:
        print(-1)
    else:
        out = [[0]*n for i in range(n)]

        curr = 1

        for i in range(n):
            for j in range(n):
                if (i+j)%2 == 0:
                    out[i][j] = curr
                    curr += 1

        for i in range(n):
            for j in range(n):
                if (i+j)&1:
                    out[i][j] = curr
                    curr += 1

        for i in out:
            print(*i)
