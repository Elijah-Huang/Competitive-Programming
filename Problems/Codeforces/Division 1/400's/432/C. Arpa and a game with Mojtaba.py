# use the Sprague-Grundy Theorem
import sys
input = sys.stdin.buffer.readline
from collections import Counter

games = Counter() # prime : bitmask of if that power of the prime exists

def add_primes(a):
    i = 2
    while i*i <= a:
        cnt = 0
        while a % i == 0:
            a //= i
            cnt += 1

        if cnt:
            games[i] |= 1 << cnt

        i += 1

    if a != 1:
        games[a] |= 1 << 1

def mex(a):
    i = 0
    while True:
        if i not in a:
            return i
        i += 1

grundy_val = {}
def grundy_value(mask):
    if mask in grundy_val:
        return grundy_val[mask]
    else:
        transition_masks = set()
        k = 1
        while 1<<k <= mask:
            new_mask = (mask&((1<<k)-1))|(mask>>k)
            transition_masks.add(grundy_value(new_mask))
            k += 1

        grundy_val[mask] = mex(transition_masks)
        return grundy_val[mask]


n = int(input())
a = list(map(int,input().split()))

for i in a:
    add_primes(i)

xor_sum = 0
for game in games.values():
    grundy_val = {}
    xor_sum ^= grundy_value(game)

if xor_sum:
    print("Mojtaba")
else:
    print("Arpa")