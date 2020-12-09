import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    n = int(input())
    a = list(map(int,input().split()))
    a.sort()
    c = 1;
    mn_cost = 10**9*(n+1)
    while c**(n-1) < 10**9*(n+1):
        cost = 0
        curr = 1
        for i in range(n):
            cost += abs(a[i] - curr)
            curr *= c
        mn_cost = min(mn_cost, cost)
        c += 1
    print(mn_cost)
prog()
