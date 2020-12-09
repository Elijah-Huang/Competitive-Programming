import sys
input = sys.stdin.readline
def prog():
    n = int(input())
    a = list(map(int,input().split()))
    output = []
    b = [0]*n
    for j in range(300):
        for i in range(n):
            if a[i] != b[i]:
                b[i]+=1
                output.append('P')
            if i != n-1:
                output.append('R')
        for i in range(n-1):
            output.append('L')
    print(''.join(output))
prog()
