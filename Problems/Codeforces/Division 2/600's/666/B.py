from bisect import bisect, bisect_left
import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    n = int(input())
    a = list(map(int,input().split()))
    a.sort(reverse = True)
    total_cost = sum(a) - a[0] - (n-1)
    
    posibilities = [[] for i in range(31)]
    most = 2*10**9
    for i in range(2,31):
        curr = 1
        while curr**i <= most:
            posibilities[i].append(curr**i)
            curr += 1

    taken = [0]*(min(31,n))
    for i in range(1, min(30,n-1)):
        best = 0
        new_cost = most
        for j in range(2,min(31,n)):
            if not taken[j]:
                low = bisect_left(posibilities[j], a[i])
                high = bisect(posibilities[j], a[i])
                cost = min(abs(posibilities[j][low] - a[i]), \
                               abs(a[i] - posibilities[j][high]))
                if cost <= new_cost:
                    best = j
                    new_cost = cost
        print(j)
        if (new_cost <= a[i] - 1):
            print(new_cost)
            taken[j] = True
            total_cost -= (a[i] - 1 - new_cost)
    print(total_cost)
        
prog()
