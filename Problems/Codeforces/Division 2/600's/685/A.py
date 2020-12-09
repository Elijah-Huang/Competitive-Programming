import sys
input = sys.stdin.readline
def prog():
    primes = []
    isprime = [0]*10**5
    for i in range(2,int(10**(2.5))+1):
        if isprime[i] == 0:
            primes.append(i)
        for j in range(i*i,10**5,i):
            isprime[i] = 1

    for _ in range(int(input())):
        n = int(input())
        
        found = 0
        for p in primes:
            if n % p == 0:
                found = p
                break

        if found == 0 or found == n:
            print(n-1)
        else:
            print(found)
prog()
