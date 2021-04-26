import sys
input = sys.stdin.readline
from itertools import combinations

for _ in range(int(input())):
    n = int(input())

    strings = [input().strip() for i in range(3)]

    counts = [[0]*2 for i in range(3)]

    for i in range(3):
        for j in range(2*n):
            counts[i][ord(strings[i][j]) - ord('0')] += 1

    # if statement must be satisfied because of pigeonhole
    found = 0
    for i,j in combinations(list(range(3)),2):
        if found:
            break
        for k in range(2):
            if counts[i][k] <= n and counts[j][k] <= n:
                if counts[i][k] < counts[j][k]:
                    i,j = j,i # now counts[j][k^1] >= counts[i][k^1] so we only need to add str(k)

                # add str(k) counts[i][k] <= n times to string[j]
                final_s = []
                m = 0
                for l in range(2*n):
                    while m < 2*n and strings[i][m] == str(k):
                        final_s.append(strings[i][m])
                        m += 1

                    final_s.append(strings[j][l])

                    if m < 2*n and strings[j][l] == strings[i][m]:
                        assert(strings[i][m] != str(k))
                        m += 1

                # also important since if i == j then we might still need to add some str(k)'s
                while len(final_s) != 3*n:
                    final_s.append(str(k))

                found = 1
                break

    print(''.join(final_s))