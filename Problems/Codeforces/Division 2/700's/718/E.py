import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))

    ans = 0

    # case of PPPPPPCCCCCCC
    tot_sum = sum(a)
    p_sum = 0
    for i in a:
        p_sum += i
        if p_sum > tot_sum - p_sum:
            ans += 1

    # case of P/C CCCCCC... PCPCPC... PPPPP... P/C
    alt_sum = [0]*(n+4) # n+4 so that negative indexing becomes default 0
    for i in range(n):
        alt_sum[i] = alt_sum[i-2] + a[i]

    suffix_sum = [0]*(n+1)
    for i in range(n-1,-1,-1):
        suffix_sum[i] = suffix_sum[i+1] + a[i]

    for start_p in [0, a[0]]:
        valid_suffixes = [0] * (n+4)
        pointer = [[2, 1], [2, 1]]  # has p at end, parity of leftbound

        for i in range(n-1,-1,-1): # iterate over the prefix of C's from right to left
            for p_end in range(2):
                if p_end == 0 and i == n-1: # suffix from i is supposed to have at least 1 P
                    continue

                if i > pointer[p_end][i&1]:
                    # first element if it is P, alternating sum from pointer to i-2, suffix sum - last element if it is C
                    mx_sum_of_p = start_p + alt_sum[i-2] - alt_sum[pointer[p_end][i&1]-2] + suffix_sum[i] - (p_end^1)*a[-1]
                    if mx_sum_of_p > tot_sum - mx_sum_of_p: # otherwise this will never be valid (have large enough sum from P's)
                        # find first pos i from right where sum of p's > sum of c's
                        next_sum_of_p = mx_sum_of_p + alt_sum[pointer[p_end][i&1]-2] - alt_sum[pointer[p_end][i&1]] # update
                        while pointer[p_end][i&1] + 2 <= i and next_sum_of_p > tot_sum - next_sum_of_p:
                            next_sum_of_p += alt_sum[pointer[p_end][i&1]] - alt_sum[pointer[p_end][i&1]+2] # update
                            pointer[p_end][i&1] += 2 # since next_sum worked, update pointer

                        valid_suffixes[pointer[p_end][i&1]] += 1 # earliest position
                else:
                    mx_sum_of_p = start_p + suffix_sum[i] - (p_end^1)*a[-1]
                    if mx_sum_of_p > tot_sum - mx_sum_of_p:
                        valid_suffixes[i] += 1  # earliest position

            if i or start_p == 0:
                ans += valid_suffixes[i+1] # since every suffix at index i starts with a P

            valid_suffixes[i-2] += valid_suffixes[i] # carrying over just like a suffix sum

    print(ans % 998244353)