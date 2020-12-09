import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        n,x = map(int,input().split())
        x_neighbors = set()
        for i in range(n-1):
            a,b = map(int,input().split())
            if a == x:
                x_neighbors.add(b)
            if b == x:
                x_neighbors.add(a)
        if n == 1:
            print('Ayush')
        else:
            if len(x_neighbors) == 1:
                print('Ayush')
            elif (n-1)%2 == 0:
                print('Ashish')
            else:
                print('Ayush')
prog()
