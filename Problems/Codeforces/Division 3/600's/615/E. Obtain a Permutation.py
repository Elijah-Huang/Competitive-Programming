import sys
input = sys.stdin.buffer.readline

ans = 0

n,m = map(int,input().split())
a = [list(map(int,input().split())) for i in range(n)]

for j in range(m):
    mn_moves_for_row = n
    loc = {}
    for i in range(n):
        loc[i*m + j+1] = i

    events = [0]*(n+1)
    for i in range(n):
        if a[i][j] in loc:
            shifts = (i - loc[a[i][j]] + n)%n
            events[shifts] += 1
            events[shifts + 1] -= 1

    matches = 0
    for shifts in range(n):
        matches += events[shifts]
        mn_moves_for_row = min(mn_moves_for_row, shifts + n - matches)

    ans += mn_moves_for_row

print(ans)
