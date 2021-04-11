# O(t*log(n)*m)
import sys
input = sys.stdin.buffer.readline

mod = 10**9 + 7

def solve(a,m):
    splits = 0
    counts = [0]*10
    
    while(1):
        if m < 10 - a:
            a += m
            counts[a] = 1
            m = 0
            break
        else:
            splits += 1
            m -= 10 - a
            a = 0

    for i in range(splits):
        counts_split = [0]*10
        # add 1
        for j in range(9):
            counts_split[j+1] = counts[j]
        # carryover
        counts_split[0] += counts[9]
        counts_split[1] += counts[9]

        for i in range(10):
            counts[i] = (counts[i] + counts_split[i]) % mod
        
    return sum(counts)


for _ in range(int(input())):
    n,m = map(int,input().split())
    
    ans = 0
    while n:
        ans += solve(n%10,m)
        n//=10
    
    print(ans % mod)