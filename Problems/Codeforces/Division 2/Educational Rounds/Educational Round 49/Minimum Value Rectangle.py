from collections import Counter
import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        n = int(input())
        a = Counter(map(int,input().split()))
        work = []
        reached = 0
        for k in a:
            if a[k] >= 4:
                reached = k
                break
            elif a[k] >= 2:
                work.append(k)
        if reached:
            print(4*(str(k) + ' '))
        else:
            work.sort()
            mn = 10**18
            best = []
            for i in range(len(work) -1):
                if mn > 4*(work[i]+work[i+1])**2/(work[i]*work[i+1]):
                    mn = 4*(work[i]+work[i+1])**2/(work[i]*work[i+1])
                    best = [work[i], work[i+1]]
            print(' '.join(map(str,best + best)))
prog()
        
