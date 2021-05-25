import sys
input = sys.stdin.buffer.readline
from itertools import permutations

k = list(map(int,input().split()))

worked = 0
for k1,k2,k3 in permutations(k):
    worked2 = 1
    for t in range(10000):
        if not (t % k1 == 0 or t % k2 == 1 or t % k3 == 2):
            worked2 = 0

    if worked2:
        worked = 1
        break

if worked:
    print("YES")
else:
    print("NO")
