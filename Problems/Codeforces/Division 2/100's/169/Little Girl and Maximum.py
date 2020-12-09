import sys
input = sys.stdin.buffer.readline
def prog():
    n,q = map(int,input().split())
    array = list(map(int,input().split()))
    array.sort()
    starts = [0 for i in range(n+1)]
    stops = [0 for i in range(n+1)]
    for i in range(q):
        start, stop = map(int,input().split())
        starts[start] += 1
        stops[stop] += 1
    appearances = [starts[1]]
    for i in range(2,n+1):
        appearances.append(appearances[-1] + starts[i] - stops[i-1])
    appearances.sort()
    total_sum = 0
    for i in range(n):
        total_sum += appearances[i]*array[i]
    print(total_sum)
prog()
