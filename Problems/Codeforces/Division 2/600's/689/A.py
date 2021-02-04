import sys
input = sys.stdin.readline

def prog():
    for _ in range(int(input())):
        n,k = map(int,input().split())
        pat = 'abc'
        output = [pat[i%3] for i in range(n)]
        print(''.join(output))
prog()
