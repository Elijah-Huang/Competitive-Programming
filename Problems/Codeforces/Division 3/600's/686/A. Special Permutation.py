import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        a = [n]
        for i in range(1,n):
            a.append(i)
        print(*a)
prog()
        
