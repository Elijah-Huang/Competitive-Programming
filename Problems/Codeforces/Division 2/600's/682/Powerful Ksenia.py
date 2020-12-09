import sys
input = sys.stdin.readline
             
def prog():
    n = int(input())
    a = list(map(int,input().split()))
    
    if n % 2 == 0:
        tot = 0
        for i in a:
            tot ^= i
        if tot != 0:
            print("NO")
            return
    print("YES")
    print((n-1)-(n%2 == 0))
    for j in range(2):
        for i in range(2,n-(n%2==0) + 1,2):
            print(1,i,i+1)
prog()
