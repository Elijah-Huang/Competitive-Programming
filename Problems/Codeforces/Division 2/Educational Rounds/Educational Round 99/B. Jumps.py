from bisect import bisect_left
import sys
input = sys.stdin.readline
def prog():
    vals = [i*(i+1)//2 for i in range(2000)]
    for _ in range(int(input())):
        x = int(input())
        ans = bisect_left(vals,x)
        if vals[ans] - 1 == x:
            ans += 1
        print(ans)
prog()
