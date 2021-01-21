import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
    
def prog():
    n = int(input())
    a = list(map(int,input().split()))
    
    last = {}
    best = n + 1
    for i in range(n):
        if a[i] in last:
            best = min(best, i - last[a[i]] + 1)
            last[a[i]] = i
        else:
            last[a[i]] = i
    print(best if best != n + 1 else -1)
    
prog()
