import sys
input = sys.stdin.readline
from bisect import bisect_left

def prog():
    primes = []
    is_prime = [1]*(10**5)
    for i in range(2,10**5):
        if is_prime[i]:
            primes.append(i)
            for j in range(i*i,10**5,i):
                is_prime[j] = 0
                
    for _ in range(int(input())):
        d = int(input())

        p1 = primes[bisect_left(primes,d+1)]
        p2 = primes[bisect_left(primes,p1+d)]
        print(p1*p2)
        
prog()
        
