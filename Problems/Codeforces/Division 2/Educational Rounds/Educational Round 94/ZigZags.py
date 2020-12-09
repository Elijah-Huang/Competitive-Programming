import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        prefix = [0]*(n+1)
        tuples = 0
        for i in range(1,n-2):
            prefix[a[i-1]] += 1
            i_after_j = 0
            for j in range(n-2,i,-1):
                i_after_j += a[j+1] == a[i]
                tuples += prefix[a[j]]*i_after_j
        print(tuples)
prog()
