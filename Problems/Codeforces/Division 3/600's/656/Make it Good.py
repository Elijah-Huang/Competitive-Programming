import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        n = int(input())
        a = [10**9] + list(map(int,input().split()))
        for i in range(n-1,-1,-1):
            if a[i] < a[i+1]:
                break
        peak = i
        for i in range(peak,-1, -1):
            if a[i] > a[i+1]:
                break
        print(i)
prog()
