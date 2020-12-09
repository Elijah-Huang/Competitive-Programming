import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(val + '\n')
def prog():
    for _ in range(int(input())):
        n,m = map(int,input().split())
        missing = [int(input().strip(),2) for i in range(n)]
        missing.sort()
        median = (2**m - n -1)//2 
        for i in missing:
            if median >= i:
                median += 1
        output = bin(median)[2:]
        print('0'*(m-len(output)) + output)
prog()

