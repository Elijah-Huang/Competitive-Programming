"""
ID: elijahj1
TASK: sprime
LANG: PYTHON3
"""
from math import floor

def isprime(num):
    if num == 2:
        return True
    elif num % 2 == 0:
        return False
    for divisor in range(3,int(floor(num**0.5)) + 1, 2):
        if num % divisor == 0:
            return False
    return True

def create_sprimes(n):
    sprimes = [2,3,5,7]
    for i in range(n-1):
        new_primes = []
        for sprime in sprimes:
            for digit in range(1,10,2):
                new_prime = sprime*10 + digit
                if isprime(new_prime):
                    new_primes.append(new_prime)
        sprimes = new_primes
    output = ""
    for sprime in sprimes:
        output += str(sprime) + '\n'
    return output     
with open("sprime.in") as fin:
    n = int(fin.readline().strip())
with open("sprime.out", 'w') as fout:
    fout.write(create_sprimes(n))

    
