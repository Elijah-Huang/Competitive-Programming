from bisect import bisect
import sys
input = sys.stdin.buffer.readline
def prog():
    n,d = map(int,input().split())
    moneys = [list(map(int,input().split())) for i in range(n)]
    moneys2 = []
    moneys.sort()
    max_friendship = 0
    psum_friendship = [0]
    for i in range(n):
        psum_friendship.append(psum_friendship[-1] + moneys[i][1])
        moneys2.append(moneys[i][0])
    for i in range(n):
        start = moneys2[i]
        total_friendship = psum_friendship[bisect(moneys2, start + d-1)] - psum_friendship[i]
        max_friendship = max(max_friendship, total_friendship)
    print(max_friendship)
prog()
