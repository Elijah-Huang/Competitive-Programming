import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        curr = 0
        cost = 0
        for i in range(n):
            if curr <= 0 and a[i] < 0:
                cost += -a[i]
            elif curr + a[i] < 0 and curr >= 0:
                cost += -(curr + a[i])
            curr = max(0, curr + a[i])
        print(cost)
prog()
