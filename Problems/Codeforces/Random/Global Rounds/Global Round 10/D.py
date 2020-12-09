from math import inf
import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        n = int(input())
        s = input().strip()
        
        '''ss = ['LL' + s[1:n-1] + 'LL','RL' + s[1:n-1] + 'RL',\
              'LR' + s[1:n-1] + 'LR','RR' + s[1:n-1] + 'RR']'''
        dp = [[[0]*4 for i in range(n-1)] for i in range(4)]
        dp[0][0][0] = (s[0] != 'L') + (s[n-1] != 'L')
        for i in range(4):
            if i != 0:
                dp[0][0][i] = inf
        dp[1][0][2] = (s[0] != 'L') + (s[n-1] != 'R')
        for i in range(4):
            if i != 2:
                dp[1][0][i] = inf
        dp[2][0][1] = (s[0] != 'R') + (s[n-1] != 'L')
        for i in range(4):
            if i != 1:
                dp[2][0][i] = inf
        dp[3][0][3] = (s[0] != 'R') + (s[n-1] != 'R')
        for i in range(4):
            if i != 3:
                dp[3][0][i] = inf

        #print(s)
        for i in range(4):
            for j in range(1, n-1):
                dp[i][j][0] = ('L' != s[j]) + dp[i][j-1][2]
                dp[i][j][3] = ('R' != s[j]) + dp[i][j-1][1]
                dp[i][j][1] = ('R' != s[j]) + min(dp[i][j-1][0],dp[i][j-1][2])
                dp[i][j][2] = ('L' != s[j]) + min(dp[i][j-1][1],dp[i][j-1][3])
        #print(dp)
            
        mn = min(dp[0][n-2][3], dp[0][n-2][1],\
                 dp[1][n-2][2], dp[1][n-2][1], dp[1][n-2][0],\
                 dp[2][n-2][3], dp[2][n-2][2], dp[2][n-2][1],\
                 dp[3][n-2][2], dp[3][n-2][0],)

        print(mn)
prog()
        
                
