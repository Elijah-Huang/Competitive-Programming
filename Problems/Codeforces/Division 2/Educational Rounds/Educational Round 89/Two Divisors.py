import sys
input = sys.stdin.readline
from timeit import timeit
def prog():
    n = int(input())
    nums = list(map(int,input().split()))
    spf = [0]*(10**7+1)
    for p in range(2,int(10**(7/2))+1):
        if spf[p] == 0:
            for i in range(p**2,10**7+1,p):
                if spf[i] == 0:
                    spf[i] = p
    first = []
    second = []
    for num in nums:
        factorization = {}
        num2 = num
        prev = None
        while num2 != 1:
            val = spf[num2]
            if val == 0:
                val = num2
            if prev is None:
                prev = val
            elif val != prev:
                factorization[val] = factorization.get(val,0) + 1
                break
            factorization[val] = factorization.get(val,0) + 1
            num2 //= val
        if len(factorization) == 1:
            first.append(str(-1))
            second.append(str(-1))
        else:
            one = prev**factorization[prev]
            first.append(str(num//one))
            second.append(str(one))
    sys.stdout.write(" ".join(first))
    sys.stdout.write(" ".join(second))
prog()

