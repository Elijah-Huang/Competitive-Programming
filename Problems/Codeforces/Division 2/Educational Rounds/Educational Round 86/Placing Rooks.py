import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')


"""from math import floor
def isprime(x):
    if x == 2:
        return True
    if x % 2 == 0:
        return False
    for i in range(3,floor(x**0.5) +1,2):
        if x % i == 0:
            return False
    return True
print(isprime(998244353))"""
# was true


import timeit
sqrt_vers = """
from math import floor
def quic_pow(a,n,m):
    sqrt = floor(n**0.5)
    to_sqrt = 1
    val = 1
    for _ in range(sqrt):
        to_sqrt *= a
        to_sqrt %= m
    for _ in range(sqrt):
        val *= to_sqrt
        val %= m
    for i in range(n-sqrt**2):
        val*= a
        val %= m
    return val
quic_pow(200000,998244353-2,998244353)
"""
log_vers ="""
from math import floor
def quic_pow(a,n,m):
    val = 1
    a = a % m
    while n:
        if n % 2 == 1:
            n -= 1
            val = (val*a)%m
        n //= 2
        a = (a**2)%m
    return val
quic_pow(200000,998244353-2,998244353)
"""
inbuilt = """
pow(200000,998244353-2,998244353)
"""
"""
print(timeit.timeit(sqrt_vers, number = 1000))
# 8.366
print(timeit.timeit(log_vers,number = 1000))
# 0.0176
print(timeit.timeit(inbuilt,number = 1000))
# 0.00377
"""
def inverse(n,primemod):
    return pow(n,primemod-2,primemod)
"""
def choose(n,k,mod):
    if k > n:
        return 0
    k = min(n-k,k)
    numerator = 1
    denominator = 1
    for i in range(n-k+1, n+1):
        numerator = (numerator*i)% mod
    for i in range(2,k+1):
        denominator = (denominator*i) % mod
    total = (numerator* inverse(denominator,mod))%mod
    return total
"""
"""
def factorial(n):
    total = 1
    for i in range(2, n+1):
        total*= i
        total %=998244353
    return total
"""
def choose(n,k,mod):
    return (factorials[n]*inverses[k]*inverses[n-k])
def factorial_creator(n,mod):
    factorials = [1]
    curr = 1
    for i in range(1,n+1):
        curr = (curr*i) % mod
        factorials.append(curr)
    return factorials
def inverse_creator(n,k,mod,factorials):
    inverses = [0]
    for i in range(1, n-k +1):
        inverses.append(inverse(factorials[i]))
def place_rooks(n,k,mod):
    #if k == 0:
        #return factorial(n)
    if k >= n:
        return 0
    filled = n - k
    placements_per_filled = 0
    for i in range(filled):
        placements_per_filled += (((-1)**i)*choose(filled,i,mod)*pow(filled-i,n,mod)) % mod
    total = (2*choose(n,filled,mod)*placements_per_filled ) % mod
    if k == 0:
        total//= 2
    return total
        
n, k = map(int,input().split())
factorials = factorial_creator(n,mod)
inverses = inverse_creator(n,k,mod,factorials)
print(place_rooks(n,k,998244353))
