from collections import Counter
import sys
from math import ceil
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        n,k = map(int,input().split())
        s = input().strip()
        amounts = Counter(s)
        most = list(amounts.values())
        most.sort(reverse = True)
        diff = len(most)
        beauties = []
        for i in range(1,min(int(k**0.5 + 1),n+1)):
            if k % i == 0:
                if i <= n:
                    beauties.append(i)
                if k//i <= n:
                    beauties.append(k//i)
        lengths = []
        for beauty in beauties:
            l = 1
            r = n//beauty
            while l != r:
                m = ceil((l+r)/2)
                need = beauty
                idx = 0
                while need > 0 and idx < diff and most[idx] >= m:
                    need -= most[idx]//m
                    idx += 1
                if need <= 0:
                    l = m
                else:
                    r = m-1
            lengths.append(l*beauty)
        print(max(lengths))
prog()
            
            
