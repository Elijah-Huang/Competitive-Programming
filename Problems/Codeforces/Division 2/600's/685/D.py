import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        d,k = map(int,input().split())
        mid = int(d/k*(1/2)**0.5)
        mid*=k
        if (mid + k)**2 + mid**2 <= d**2:
            print("Ashish")
        else:
            print("Utkarsh")
prog()
