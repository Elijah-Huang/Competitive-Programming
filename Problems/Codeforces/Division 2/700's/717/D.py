import sys
input = sys.stdin.buffer.readline

spf = [0]*(10**5 + 1)
primes = []
for i in range(2,10**5 + 1):
    if spf[i] == 0:
        spf[i] = i
        primes.append(i)

    j = 0
    while j < len(primes) and primes[j] <= spf[i] and primes[j]*i <= 10**5:
        spf[primes[j]*i] = primes[j]
        j += 1

n,q = map(int,input().split())

a = list(map(int,input().split()))

ancestor = [[n]*20 for i in range(10**5 + 1)]
next_start = n
last_occurence = [n]*(10**5 + 1)

for i in range(n-1,-1,-1):
    lst = -1
    while a[i] != 1:
        if lst != spf[a[i]]: # or else infinite cycle since we set last_occurence
            next_start = min(next_start, last_occurence[spf[a[i]]])
            last_occurence[spf[a[i]]] = i
        lst = spf[a[i]]
        a[i] //= spf[a[i]]
    
    ancestor[i][0] = next_start
    for j in range(1,20):
        ancestor[i][j] = ancestor[ancestor[i][j-1]][j-1]


for i in range(q):
    l,r = map(int,input().split())
    l-=1; r-=1
    
    subarrays = 1
    for j in range(19,-1,-1):
        if ancestor[l][j] <= r:
            l = ancestor[l][j]
            subarrays += (1 << j)
    
    print(subarrays)