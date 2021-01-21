import sys
input = sys.stdin.readline

def prog():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        pos = set()
        for i in range(n):
            for j in range(i+1,n):
                pos.add(a[j]-a[i])

        print(len(pos))
prog()
