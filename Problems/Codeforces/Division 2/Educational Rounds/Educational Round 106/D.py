import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')

maxn = 2*10 ** 7
whyistimelimitsotight = {}
pairs = [0] * (maxn+1)
spf = [0] * (maxn+1)
primes = []

for i in range(2, maxn+1):
    if spf[i] == 0:
        spf[i] = i
        primes.append(i)

    j = 0
    while j < len(primes) and primes[j] <= spf[i] and primes[j]*i <= maxn:
        spf[primes[j]*i] = primes[j]
        j += 1

for i in range(2,maxn+1):
    prev = i//spf[i]
    pairs[i] += pairs[prev] + (spf[prev] != spf[i])

def divisors(n):
    pf = []
    while n > 1:
        if len(pf) == 0 or pf[-1][0] != spf[n]:
            pf.append([spf[n],1])
        else:
            pf[-1][1] += 1

        n //= spf[n]

    divs = [1]
    for prime, count in pf:
        l = len(divs)
        prime_pow = 1

        for i in range(count):
            prime_pow *= prime
            for j in range(l):
                divs.append(divs[j]*prime_pow)

    return divs


for _ in range(int(input())):
    c,d,x = map(int,input().split())
    ans = 0

    if x in whyistimelimitsotight:
        divs = whyistimelimitsotight[x]
    else:
        whyistimelimitsotight[x] = divs = divisors(x)

    for i in divs:
        e = x//i + d
        if e % c == 0:
            ans += 1 << pairs[e//c]

    print(ans)