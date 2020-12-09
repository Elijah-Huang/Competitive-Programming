import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        n = int(input())
        print(" ".join(map(str, [i+1 for i in range(n)])))
prog()
    
