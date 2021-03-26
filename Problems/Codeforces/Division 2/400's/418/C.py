# O(n^2)
import sys
input = sys.stdin.buffer.readline

n = int(input())
s = str(input().strip())[2:-1]
ans = [[0]*(n+1) for i in range(26)]

segs = [[[0,-1]] for i in range(26)]
for i in range(n):
    c = ord(s[i]) - ord('a')

    if i > 0 and s[i] != s[i-1]:
        segs[c].append([i,i])
    else:
        segs[c][-1][1] = i

for c in range(26):
    # mx anc[c][m] assuming we include seg start
    for start in range(len(segs[c])):
        lst_seg = start
        tot = segs[c][start][1] - segs[c][start][0] + 1
        left = 0
        l = segs[c][start][0]
        for m in range(1,n+1):
            if segs[c][lst_seg][1] + left + 1 < n:
                left += 1
                tot += 1
                if lst_seg != len(segs[c])-1 and \
                    segs[c][lst_seg][1] + left == segs[c][lst_seg+1][0]-1:
                    lst_seg += 1
                    tot += segs[c][lst_seg][1] - segs[c][lst_seg][0] + 1
                    left = 0
            elif start != 0 and l > segs[c][start-1][1]+2:
                l -= 1
                tot += 1

            ans[c][m] = max(ans[c][m], tot)

q = int(input())
for i in range(q):
    m,c = input().split()
    m = int(str(m)[2:-1])
    c = ord(str(c)[2:-1]) - ord('a')
    print(ans[c][m])

