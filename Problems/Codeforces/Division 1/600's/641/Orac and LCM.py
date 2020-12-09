import sys
input = sys.stdin.buffer.readline
def prog():
    n = int(input())
    nums = list(map(int,input().split()))
    spf = [i for i in range(200001)]
    for p in range(2,int(200000**0.5) + 1):
        if spf[p] == p:
            for i in range(p**2, 200001, p):
                if spf[i] == i:
                    spf[i] = p
    smallest = {}
    for num in nums:
        factorization = {}
        while num != 1:
            factorization[spf[num]] = factorization.get(spf[num],0) + 1
            num //= spf[num]
        for p in factorization:
            if p in smallest:
                smallest[p].append(factorization[p])
            else:
                smallest[p] = [factorization[p]]
    ans = 1
    for p in smallest:
        if n - len(smallest[p]) >= 2:
            smallest[p] = []
        else:
            new = []
            minimal = min(smallest[p])
            new.append(minimal)
            if n - len(smallest[p]) == 0:
                smallest[p].remove(minimal)
                new.append(min(smallest[p]))
            smallest[p] = new
    for p in smallest:
        two_smallest = smallest[p]
        if len(two_smallest) != 0:
            ans*= p**two_smallest[-1]
    print(ans)
prog()
    
    
        
        
