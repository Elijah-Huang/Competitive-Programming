import sys
from collections import Counter
input = sys.stdin.buffer.readline

m,k,n,s = map(int,input().split())
a = list(map(int,input().split()))
b = Counter(map(int,input().split()))

counts = Counter()
unsatisfied = len(b)
to_remove = m+1
mn_len = m+1
remove_idx = -1

j = 0
for i in range(m):
    while j < m and unsatisfied != 0:
        counts[a[j]] += 1
        if counts[a[j]] == b[a[j]]:
            unsatisfied -= 1

        j += 1

    if unsatisfied == 0:
        curr_remove = i % k + max(0, j - i - k)
        if curr_remove < to_remove:
            to_remove = curr_remove
            mn_len = j - i
            remove_idx = i

    if counts[a[i]] == b[a[i]]:
        unsatisfied += 1

    counts[a[i]] -= 1

if m - to_remove < n*k:
    print(-1)
else:
    print(to_remove)

    indexes = {}
    for i in range(remove_idx,remove_idx + mn_len):
        if a[i] in indexes:
            indexes[a[i]].append(i+1)
        else:
            indexes[a[i]] = [i+1]

    removed = list(range(1,remove_idx % k + 1))
    to_remove -= remove_idx % k

    for i in indexes:
        if to_remove == 0:
            break
        else:
            removed.extend(indexes[i][:min(len(indexes[i]) - b[i],to_remove)])
            to_remove -= min(len(indexes[i]) - b[i],to_remove)

    print(*removed)