import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        n,k = map(int,input().split())
        before = (n+1)//2 - 1
        a = list(map(int,input().split()))[k*before:]

        tot = 0
        for i in range(0,len(a),n-before):
            tot += a[i]
        print(tot)
prog()
