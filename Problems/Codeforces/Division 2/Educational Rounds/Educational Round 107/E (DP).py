# thanks for explaining this DP solution to me moo.
import sys
input = sys.stdin.readline

mod = 998244353

n,m  = map(int,input().split())
board = [input().strip() for i in range(n)]

ans = 0
tot_c = 0
tot_h = []
tot_v = []

for i in range(n):
    for j in range(m):
        if board[i][j] == 'o':
            tot_c += 1

for i in range(n):
    for j in range(m):
        if board[i][j] == 'o' and (j == 0 or board[i][j-1] == '*'):
            tot_h.append(1)
        elif board[i][j] == 'o':
            tot_h[-1] += 1

for j in range(m):
    for i in range(n):
        if board[i][j] == 'o' and (i == 0 or board[i-1][j] == '*'):
            tot_v.append(1)
        elif board[i][j] == 'o':
            tot_v[-1] += 1

# paired[j][i] -> colorings where (# of 1's after last 0) % 2 == j
paired = [[0]*(max(n,m)+1) for i in range(2)]
paired[0][1] = paired[1][1] = 1
for i in range(2,max(n,m)+1):
    paired[0][i] = (2*paired[1][i-1] + paired[0][i-1]) % mod
    paired[1][i] = paired[0][i-1]

# dp[i] = sum of dominoes for every maximal tiling of a coloring of i consecutive o's
# with 1's or 0's where we can place a part of a domino at a 1 and not at a 0
dp = [0]*(max(n,m)+1)
for i in range(2,max(n,m)+1):
    dp[i] = (2*dp[i-1] + paired[1][i-1]) % mod
    # we add paired[i][i-1] because there is an extra domino from placing a 1
    # there is no overcount because we always pair as soon as possible (two free 1's) (this restriction is enough)

# find the sum of the number of dominoes for every maximal tiling of a coloring of consecutive o's
# with 1's or 0's where we can place a part of a domino at a 1 and not at a 0
# for every consecutive sequence of o's in every row and col individually then multiply this by
# the number of ways to tile the other cells not in this row/col (2^everything else)
# the value of every domino will be considered and there cannot be overcount
# (you can't have a domino counted in 2 different rows or cols or both a row and a col)
for num_consec in tot_h + tot_v:
    ans = (ans + dp[num_consec]*pow(2,tot_c-num_consec,mod)) % mod

print(ans)