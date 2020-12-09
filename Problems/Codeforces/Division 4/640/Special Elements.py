import sys
input = sys.stdin.buffer.readline
from collections import Counter
def prog():
    for _ in range(int(input())):
        n = int(input().strip())
        elements = list(map(int,input().split()))
        amount = Counter(elements)
        w = 0
        for i in range(n-1):
            segment = elements[i]
            for j in range(i+1,n):
                segment += elements[j]
                if segment > n:
                    break
                elif segment in amount:
                    w += amount[segment]
                    del amount[segment]
        print(w)
prog()
