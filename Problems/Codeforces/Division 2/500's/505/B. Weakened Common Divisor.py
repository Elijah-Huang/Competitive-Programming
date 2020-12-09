import sys
input = sys.stdin.readline

def primes(n):
    fact = []
    if n % 2 == 0:
        fact.extend([2])
        while n % 2 == 0:
            n//=2
    for i in range(3,int(n**0.5)+1,2):
        if n % i == 0:
            fact.append(i)
            while n % i == 0:
                n//=i
    if n != 1:
        fact.append(n)
        
    return fact

def prog():
    n = int(input())
    a = [list(map(int,input().split())) for i in range(n)]
    
    valid_primes = set(primes(a[0][0]) + primes(a[0][1]))
    for i in range(1,n):
        to_remove = []
        for p in valid_primes:
            if a[i][0] % p != 0 and a[i][1] % p != 0:
                to_remove.append(p)
        for p in to_remove:
            valid_primes.remove(p)
                
    if valid_primes:
        print(list(valid_primes)[0])
    else:
        print(-1)
        
prog()
