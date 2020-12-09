primes = [1]*10**5
primes2 = [0]*10**5
p = []

for i in range(2,10**5):
    if primes[i]:
        for j in range(i*i,10**5,i):
            primes[j] = 0

for i in range(2,10**5):
    if primes2[i] == 0:
        primes2[i] = i
        p.append(i)
        if not primes[i]:
            print("boi u messed up")
            
    for j in range(len(p)):
        if p[j] > primes2[i] or p[j]*i >= 10**5:
            break
        primes2[p[j]*i] = p[j]

for _ in range(int(input())):
    n = int(input())
    idx = 0

    selected = 0
    for prime in p:
        if prime <= n-1:
            continue
        if not primes[prime - (n-1)]:
            selected = prime - (n-1)
            break

    output = [['1']*n for i in range(n)]
    for i in range(n):
        output[i][i] = str(selected)

    for a in output:
        print(' '.join(a))

    
