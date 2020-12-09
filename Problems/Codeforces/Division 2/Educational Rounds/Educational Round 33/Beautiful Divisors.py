import sys
input = sys.stdin.readline
def prog():
    n = int(input())
    best = 1
    curr = 1
    i = 1
    while curr <= n:
        curr = curr*2 + (1 << (2*i))
        i += 1
        if n % curr == 0:
            best = curr
    print(best)
prog()
