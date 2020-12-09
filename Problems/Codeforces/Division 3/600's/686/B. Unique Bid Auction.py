from collections import Counter
import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        idx = [0]*(n+1)
        for i in range(n):
            idx[a[i]] = i

        a = Counter(a)
        b = []
        for i in a:
            if a[i] == 1:
                b.append(i)
                
        if len(b) == 0:
            print(-1)
        else:
            print(idx[min(b)]+1)
prog()
        
