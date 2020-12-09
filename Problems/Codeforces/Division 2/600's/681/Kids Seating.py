import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        output = []
        for i in range(2*n, 4*n,2):
            output.append(i)
        print(*output)
prog()
