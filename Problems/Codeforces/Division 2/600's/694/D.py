import sys
from collections import Counter
input = sys.stdin.buffer.readline

def prog():
    is_square = [0]*(10**6+1)
    for i in range(1,10**3+1):
        is_square[i*i] = 1
        
    primes = []
    spf = [0]*(10**6+1)
    for i in range(2,10**6+1):
        if spf[i] == 0:
            spf[i] = i
            primes.append(i)
        j = 0
        while j < len(primes) and primes[j] <= spf[i] and primes[j]*i<=10**6:
            spf[primes[j]*i] = primes[j]
            j+=1

    def nsquare_fact(a):
        count = set()
        while a != 1:
            if spf[a] in count:
                count.remove(spf[a])
            else:
                count.add(spf[a])

            a //= spf[a]

        ret = 1
        for i in count:
            ret *= i

        return ret

    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        q = int(input())
        ans0 = 0
        ans1 = 0
        vals = Counter()
        
        for i in a:
            vals[nsquare_fact(i)] += 1

        ans0 = max(vals.values())
        
        for i in vals:
            if is_square[i] or vals[i]%2 == 0:
                ans1 += vals[i]
        ans1 = max(ans1,ans0)
        
        for i in range(q):
            w = int(input())
            if w == 0:
                print(ans0)
            else:
                print(ans1)

prog()
