import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        print(n)
        a = [i for i in range(1,n+1)]
        print(*a)
prog()
