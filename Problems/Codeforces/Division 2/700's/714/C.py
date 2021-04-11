# O(t*log(n)*m)
import sys

input = sys.stdin.buffer.readline

mod = 10 ** 9 + 7

counts = [0]*10
counts[0] = 1
ans = [0]*(2*10**5 + 20)

for i in range(len(ans)):
    ans[i] = sum(counts)

    counts_new = [0] * 10
    # add 1
    for j in range(9):
        counts_new[j + 1] = counts[j]
    # carryover
    counts_new[0] = counts[9]
    counts_new[1] = (counts_new[1] + counts[9]) % mod

    counts = counts_new

for _ in range(int(input())):
    n, m = map(int, input().split())

    tot_len = 0
    while n:
        tot_len += (ans[m + n % 10])
        n //= 10

    print(tot_len % mod)