import sys
s = sys.stdin.readline().strip()
stack = []
dp = [0]*(len(s)+1)
for i in range(len(s)):
    if s[i] == ')':
        if stack:
            begin = stack.pop()
            dp[i] = dp[begin-1] + (i - begin + 1)
    else:
        stack.append(i)

mx = max(dp)
if mx == 0:
    print(0,1)
else:
    print(mx,dp.count(mx))