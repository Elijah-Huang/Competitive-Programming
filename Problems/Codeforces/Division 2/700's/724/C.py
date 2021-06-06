import sys
input = sys.stdin.readline
from math import gcd

for _ in range(int(input())):
    n = int(input())
    s = input().strip()

    answer = [0]*n

    ratios = dict()
    tot_d = 0
    tot_k = 0

    for i in range(n):
        if s[i] == 'D':
            tot_d += 1
        else:
            tot_k += 1

        g = gcd(tot_d,tot_k)
        d = tot_d//g
        k = tot_k//g

        if (d,k) not in ratios:
            ratios[(d,k)] = 1
        else:
            ratios[(d,k)] += 1

        answer[i] = ratios[(d,k)]

    print(*answer)