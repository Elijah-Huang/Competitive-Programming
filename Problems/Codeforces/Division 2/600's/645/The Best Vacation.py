import sys
from bisect import bisect_left
input = sys.stdin.buffer.readline
def nsum(n):
    return (n*(n+1))//2
def prog():
    n,x = map(int,input().split())
    days = list(map(int,input().split()))
    hugs = [nsum(day) for day in days]
    tdays = [0]
    thugs = [0]
    for i in range(n):
        tdays.append(days[i] + tdays[i])
    for i in range(n):
        tdays.append(days[i] + tdays[i+n])
    for i in range(n):
        thugs.append(hugs[i] + thugs[i])
    for i in range(n):
        thugs.append(hugs[i] + thugs[i+n])
    maxes = []
    for i in range(n):
        end = bisect_left(tdays,x+tdays[i])
        diff = tdays[end] - (x + tdays[i])
        if diff <= days[i]:
            maxes.append(thugs[end] - thugs[i] - nsum(diff))
    print(max(maxes))
prog()
