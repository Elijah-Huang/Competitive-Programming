import sys
input = sys.stdin.buffer.readline
from collections import Counter

for _ in range(int(input())):
    n = int(input())
    a = Counter(map(int,input().split()))

    mx = a.most_common(1)[0][1]

    if 2*mx > n:
        print(mx-(n-mx))
    else:
        print(n%2)


