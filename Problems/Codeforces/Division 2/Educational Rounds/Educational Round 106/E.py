# O(16*n^2)
import sys
input = sys.stdin.readline

mod = 998244353

tot = 0

x = ' ' + input().strip()
y = ' ' + input().strip()
s = [x,y]

# the idea is to go from the dp that finds number of chaotic merges of x and y
# given that the substrings merged must begin at the start of x and y (are just prefixes)
# to the dp where the start of the substrings for the merge can be anything
# this is done by adding 1 at dp[i][j-1][0][1][0] and dp[i-1][j][1][0][1]
# (the same way we would start the dp normally if i == 1 and j == 1 (prefixes from above))

# dp[i][j][c][nex][ney] = the number of chaotic merges of a substring of x and y such that
# either substring of x is empty or ends at i and either substring of y is empty or ends at j
# however both substrings cannot be empty
# c = 0 -> last character is from x otherwise from y
# nex -> 1 if substring from x is not empty else 0
# ney -> 1 if substring from y is not empty else 0
# note that instead of an extra dimension for each nex and ney they are merged to reduce memory (or else MLE)
dp = [[[[0]*4 for j in range(2)] for k in range(len(y))] for i in range(len(x))]

# base case
for i in range(1,len(x)):
    for j in range(1,len(y)):
        # to start the dp of chaotic merges of x[i:] and y[j:]
        dp[i][j-1][0][2] = 1
        dp[i-1][j][1][1] = 1

# transitions
for i in range(len(x)):
    for j in range(len(y)):
        s_idx = [i,j]

        # add num of chaotic merges of subs that end at i and j to tot
        tot = (tot + dp[i][j][0][3] + dp[i][j][1][3]) % mod

        # transition
        for c in range(2):
            for nex in range(2):
                for ney in range(2):
                    # add x[i+1] to the end of the merge and transition
                    if i < len(x)-1 and s[c][s_idx[c]] != x[i+1]:
                        dp[i+1][j][0][2+ney] = (dp[i+1][j][0][2+ney] + dp[i][j][c][2*nex+ney]) % mod
                    # add y[j+1] to the end of the merge and transition
                    if j < len(y)-1 and s[c][s_idx[c]] != y[j+1]:
                        dp[i][j+1][1][2*nex+1] = (dp[i][j+1][1][2*nex+1] + dp[i][j][c][2*nex+ney]) % mod

print(tot)