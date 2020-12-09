from math import sqrt
def factorize(n):
    factorization = []
    while n % 2 == 0:
        factorization.append(2)
        n //= 2
    if n == 1:
        return factorization
    p = 1
    while True:
        start = p + 2
        stop = int(sqrt(n)) +1
        divided = False
        for p in range (start, stop, 2):
            while n % p == 0:
                factorization.append(p)
                n //= p
                divided = True
                if n == 1:
                    return factorization
            if divided:
                break
        if not divided:
            factorization.append(n)
            return factorization



