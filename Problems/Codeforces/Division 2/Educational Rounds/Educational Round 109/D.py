import sys
input = sys.stdin.buffer.readline

n = int(input())

a = list(map(int,input().split()))

if sum(a) == 0:
    print(0)
    exit()

loc_one = [0]
loc_zero = [0]
for i in range(n):
    if a[i]:
        loc_one.append(i)
    else:
        loc_zero.append(i)

ones = sum(a)
zeros = n - ones
dp = [[1e9]*(zeros + 1) for i in range(ones+1)]
mn_dp = [[1e9]*(zeros + 1) for i in range(ones+1)]
mn_dp[0] = [0]*(zeros+1)

for i in range(1,ones+1):
    for j in range(1,zeros+1):
        dp[i][j] = abs(loc_one[i]-loc_zero[j]) + mn_dp[i-1][j-1]

        mn_dp[i][j] = min(dp[i][j], mn_dp[i][j-1])

print(mn_dp[ones][zeros])