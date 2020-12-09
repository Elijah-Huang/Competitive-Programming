from math import ceil 
def prog():
    for _ in range(int(input())):
        n,m,k = map(int,input().split())
        if n//k >=m:
            print(m)
        else:
            most = n//k
            m -= most
            next_most = ceil(m/(k-1))
            print(most - next_most)
prog()
