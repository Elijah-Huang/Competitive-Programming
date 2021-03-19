maxn = 10 ** 7
spf = [0] * (maxn+1)
primes = []

# linear sieve
for i in range(2, maxn+1):
    if spf[i] == 0:
        spf[i] = i
        primes.append(i)

    j = 0
    while j < len(primes) and primes[j] <= spf[i] and primes[j]*i <= maxn:
        spf[primes[j]*i] = primes[j]
        j += 1

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