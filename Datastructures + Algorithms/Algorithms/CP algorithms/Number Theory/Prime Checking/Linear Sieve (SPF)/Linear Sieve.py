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