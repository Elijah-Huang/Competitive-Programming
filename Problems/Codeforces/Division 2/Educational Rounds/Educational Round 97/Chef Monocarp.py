from collections import Counter
import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        t = Counter(list(map(int,input().split())))
        
        dishes = []
        for i in t:
            dishes.append([i,t[i]])
        dishes.sort()

        ans = 10**9
        dp = [[10**9]*(2*n + 1) for i in range(len(dishes) + 1)]
        dp[0] = [0]*(2*n+1)
        for dish in range(len(dishes)):
            amt = dishes[dish][1]
            m = dishes[dish][0]
            for right in range(dishes[dish][1], 2*n + 1):
                left = right-amt+1
                if right < m:
                    dp[dish+1][right] = min(dp[dish + 1][right-1], dp[dish][left-1] + (m-left)*(m-left +1)//2 - (m-right-1)*(m-right)//2)
                elif left > m:
                    dp[dish+1][right] = min(dp[dish + 1][right-1], dp[dish][left-1] + (right-m)*(right-m +1)//2 - (left-m-1)*(left-m)//2)
                else:
                    dp[dish + 1][right] = min(dp[dish + 1][right-1], dp[dish][left-1] + (right-m)*(right-m+1)//2 + (m - (right - amt + 1))*(m - (right - amt + 1) + 1)//2)

        print(dp[len(dishes)][2*n])

prog()
