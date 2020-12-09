from math import sqrt
def soe(n):
    primes = [True for i in range(n+1)]
    for p in range(2, int(sqrt(n))+1):
        if primes[p]:
            for np in range(p**2, n+1, p):
                primes[np] = False
    return primes

# Only use normal isprime if you are checking less than 1/15 or 7% of nums in n

# For times larger than used in cp, this fraction decreases even more because
# spf/soe time increases almost linearly for large n, but every added case
# for normal isprime/factorize increases time by squareroot of n which gets
# arbitrarily large thus the fraction of cases that can be checked is
# proportional to (n/sqrt(n))/n = 1/sqrt(n) which decreases
 
# returns boolean list of whether a number is prime or not
# Time complexity O(n*log(log(n)))VERY QUICK
# Pretty much at most ten times longer than linear time for under 10**8



import timeit
yo = """
from math import floor
def soe(n):
    primes = [True for i in range(n+1)]
    for p in range(2,floor(n**0.5)+1):
        if primes[p]:
            for np in range(p**2, n+1,p):
                primes[np] = False
soe(10**6)
"""
boi = """
from math import floor
def isprime(n):
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    for i in range(3,floor(n**0.5),2):
        if n % i == 0:
            return False
    return True
for i in range(2,10**6):
    isprime(i)
"""
soy = """
for i in range(10**6):
    pass
"""
print(timeit.timeit(yo,number = 1))
# 0.159 
print(timeit.timeit(boi,number = 1))
# 2.316
print(timeit.timeit(soy,number =1))
# 0.0217
