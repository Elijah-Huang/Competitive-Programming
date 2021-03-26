# O(n + |alpahbet|^2 *(|alphabet| + log(n)))
import sys
input = sys.stdin.readline
from bisect import bisect

for _ in range(int(input())):
    s = input().strip()

    used = [0]*26
    locs = [[] for i in range(26)]
    final_len = 26
    f = ''

    for i in range(len(s)):
        locs[ord(s[i])-ord('a')].append(i)

    for i in range(26):
        if len(locs[i]) == 0:
            used[i] = 1
            final_len -= 1

    lst = -1
    for i in range(final_len):
        for j in range(25,-1,-1):
            if not used[j]:
                earliest = locs[j][bisect(locs[j], lst)]
                mn_latest = earliest
                for k in range(26):
                    if not used[k]:
                        mn_latest = min(mn_latest, locs[k][-1])

                if earliest <= mn_latest:
                    used[j] = 1
                    f += chr(ord('a') + j)
                    lst = earliest
                    break

    print(f)