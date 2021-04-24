# use iterative cuz recursion has too much overhead
# Also it appears that default range is quicker
# Best guess is it's just optimized or maybe cache stuff
import sys
input = sys.stdin.buffer.readline

n = int(input())

s = list(map(int,input().split()))
s.sort()

dp = [0]*n
for i in range(n-1,-1,-1):
    for j in range(i+1,n):
        dp[j] = s[j] - s[i] + min(dp[j-1], dp[j])

print(dp[n-1])