import sys
input = sys.stdin.buffer.readline
from collections import Counter

for _ in range(int(input())):
    n,l,r = map(int,input().split())

    c = list(map(int,input().split()))

    left = Counter(c[:l])
    right = Counter(c[l:])

    cost = 0

    tot_pairs = 0
    for i in left:
        if i in right:
            pairs = min(left[i],right[i])
            tot_pairs += pairs
            left[i] -= pairs
            right[i] -= pairs

    swaps = abs((r-l)//2)
    swapped = 0
    if r < l:
        left,right = right,left

    for i in right:
        while right[i] >= 2 and swapped < swaps:
            right[i] -= 2
            swapped += 1

    print(swaps + (n-2*tot_pairs-2*swapped)//2)
