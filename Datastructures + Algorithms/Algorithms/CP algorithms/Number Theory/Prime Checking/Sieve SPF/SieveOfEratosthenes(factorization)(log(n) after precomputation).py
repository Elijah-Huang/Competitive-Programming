from math import sqrt
def spf_generator(n):
    spf = [i for i in range(n+1)]
    for p in range(2, int(sqrt(n))+1):
        if spf[p] == p:
            for np in range(p**2, n+1, p):
                if spf[np] == np:
                    spf[np] = p
    return spf
def factorize(n,spf):
    factorization = []
    while n != 1:
        factorization.append(spf[n])
        n //= spf[n]
    return factorization

# only use normal factorize over spf if you factorize 1/50 or 2% of nums in n

# For times larger than used in cp, this fraction decreases even more because
# spf/soe time increases almost linearly for large n, but every added case
# for normal isprime/factorize increases time by squareroot of n which gets
# arbitrarily large thus the fraction of cases that can be checked is
# proportional to (n/sqrt(n))/n = 1/sqrt(n) which decreases


# creates a list of Smallest Prime Factors (spf) for the numbers then uses
# that to factorize any number in log(n) time (base of log >= 2)
# only use normal factorize over spf if you factorize 1/50 or 2% of nums in n


import timeit
via_spf = """
from math import floor
def spf_generator(n):
    spf = [i for i in range(n+1)]
    for p in range(2, floor(n**0.5)+1):
        if spf[p] == p:
            for np in range(p**2, n+1, p):
                if spf[np] == np:
                    spf[np] = p
    return spf
def factorize(n,spf):
    factorization = []
    while n != 1:
        factorization.append(spf[n])
        n //= spf[n]
    return factorization
spf = spf_generator(5*10**6)
for i in range(1, 5*10**6):
    factorize(i,spf)
"""
via_by_n_factorize = """
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
for i in range(1,5*10**6):
    factorize(i)
"""
via_by_n_less = """
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
for i in range(int(4.7*10**6),5*10**6):
    factorize(i)
"""

print(timeit.timeit(via_spf, number = 1))
print(timeit.timeit(via_by_n_factorize,number = 1))
# Creating spf takes slightly longer than regular soe boolean array
# factorizing all numbers up to n takes a few times longer than creating spf
# spf creation time: 1.484
# spf + factorize all up to n: 4.986
# doing number by number factorization takes a whopping 65.47

# The largest 6% of cases takes the same amount of time as all cases via spf

#The 2% of largest cases takes the same amount of time as 2% largest via spf
#Use normal factorize only if cases are around 50 times less 
