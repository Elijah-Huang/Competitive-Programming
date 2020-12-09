import sys
from math import inf, log, ceil
input = sys.stdin.buffer.readline
def prog():
    for _ in range(int(input().strip())):
        n = int(input().strip())
        sequence = list(map(int,input().split()))
        j = 0 
        diff = 0
        nondecreasing = False
        while j < n-1 and not nondecreasing:
            nondecreasing = True
            for j in range(j,n-1):
                if sequence[j+1] < sequence[j]:
                    greatest = sequence[j]
                    nondecreasing = False
                    break
            if not nondecreasing:
                smallest = inf
                for j in range(j+1,n):
                    if sequence[j] > greatest:
                        break
                    smallest = min(smallest,sequence[j])
                diff = max(diff,greatest-smallest)
        print(ceil(log(diff+1,2)))
prog()
