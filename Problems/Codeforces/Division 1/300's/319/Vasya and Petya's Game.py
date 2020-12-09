def prog():
    n = int(input())
    primes = [True for i in range(n+1)]
    for p in range(2,int(n**0.5)+1):
        if primes[p]:
            for num in range(p**2,n+1,p):
                primes[num] = False
    sequence = []
    for num in range(2,n+1):
        if primes[num] == True:
            num_pow = num
            while num_pow <= n:
                sequence.append(str(num_pow))
                num_pow *= num
    print(len(sequence))
    print(" ".join(sequence))
prog()
