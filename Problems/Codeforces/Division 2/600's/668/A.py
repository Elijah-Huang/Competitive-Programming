import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        print(*a[::-1])
prog()
