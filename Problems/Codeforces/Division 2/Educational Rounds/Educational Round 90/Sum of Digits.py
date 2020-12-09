import sys
input = sys.stdin.buffer.readline
from math import inf
def prog():
    carry = [[[] for i in range(18)] for i in range(10)]
    for k in range(10):
        for c in range(1,18):
            curr = 10**c
            for a in range(1,k+1):
                nums = list(range(curr-a,curr-a+k+1))
                total = 0
                for num in nums:
                    while num:
                        total += num % 10
                        num//=10
                carry[k][c].append(total)
    for _ in range(int(input())):
        n,k = map(int,input().split())
        smallest = inf
        new = n - k*(k+1)/2
        if new % (k+1) == 0 and new >= 0:
            base = int(new//(k+1))
            if base >= (10 - (k+1)):
                base2 = 10 - (k+1)
                base -= base2
                base2 = str(base2)
            else:
                base2 = ''
            base2 = '9'*(base//9) + base2
            base2 = int(str(base%9) + base2)
            smallest = base2
        for c in range(1,18):
            for a in range(1,k+1):
                add = carry[k][c][a-1]
                new = n - add
                if new % (k+1) == 0 and new >= 0:
                    base = int(new//(k+1))
                    if base >= 8:
                        base2 = '8'
                        base -= 8
                    else:
                        base2 = ''
                    base2 = '9'*(base//9) + base2
                    base2 = int(str(base%9) + base2)*10**c + 10**c - a
                    smallest = min(base2,smallest)
        if smallest == inf:
            print(-1)
        else:
            print(smallest)
prog()
