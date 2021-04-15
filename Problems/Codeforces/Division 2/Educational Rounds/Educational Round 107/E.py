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

# find the sum of the number of dominoes for every maximal tiling of a coloring of consecutive o's
# with 1's or 0's where we can place a part of a domino at a 1 and not at a 0
# for every consecutive sequence of o's in every row and col individually then multiply this by
# the number of ways to tile the other cells not in this row/col (2^everything else)
# the value of every domino will be considered and there cannot be overcount
# (you can't have a domino counted in 2 different rows or cols or both a row and a col)
# we find the sum of the number of dominoes for every maximal tiling of a coloring of consecutive o's
# through finding the sum of dominoes from every subarray of 1's in every coloring of the o's
# it's important that we have the restriction that there is not a 1 to the left or right of the subarray
for num_consec in tot_h + tot_v:
    # num_consec o's in a row or col
    sum_vals = 0

    for sub_len in range(1,num_consec+1):
        leftover = num_consec - sub_len

        if leftover == 0:
            # both endpoints of the subarray are at the endpoints of the o's
            sum_vals += sub_len//2
        if leftover >= 1:
            # one endpoint of the subarray is at one endpoint of the o's
            sum_vals += 2 * (sub_len//2) * pow(2,leftover-1,mod)
        if leftover >= 2:
            # no endpoint of the subarray is at any endpoint of the o's
            sum_vals += (sub_len//2) * (leftover-1) * pow(2,leftover-2,mod)

    sum_vals %= mod
    ans = (ans + sum_vals * pow(2, tot_c-num_consec, mod)) % mod

print(ans)