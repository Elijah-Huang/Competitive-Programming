import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))+[-1]
        num_segs = [0]*(n+1)
        first = None
        last = None
        
        for i in range(n):
            if a[i] != a[i+1]:
                num_segs[a[i]] += 1
                if first is None:
                    first = a[i]
                if i == n-1:
                    last = a[i]

        mn = 2*n
        a.pop()
        for i in a:
            mn = min(mn, num_segs[i]-(first==i)-(last==i)+1)
        print(mn)
prog()
