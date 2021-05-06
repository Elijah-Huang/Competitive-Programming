import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))

    diff = [0]*(2*n-1)
    for i in range(n):
        diff[a[i]-1-i] += 1

    tot = 0
    for i in diff:
        tot += i*(i-1)//2

    print(tot)