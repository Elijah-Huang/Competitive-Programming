import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        
        if sum(a) % 4 == 0 or (1 in a and sum(a)%2==0):
            print("YES")
        else:
            print("NO")
prog()

