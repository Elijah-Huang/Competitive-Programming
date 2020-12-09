import sys
input = sys.stdin.readline
def prog():
    digits = ["1110111", "0010010", "1011101", "1011011",\
              "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"]
    n,k = map(int,input().split())
    dp = [[False for i in range(k+1)]for i in range(n+1)]
    dp[0][0] = True
    changes = [[None for i in range(10)]for i in range(n+1)]
    nums = [input().strip() for i in range(n)]
    nums.reverse()
    for i in range(n):
        num = nums[i]
        for digit1 in range(10):
            digit = digits[digit1]
            change = 0
            fail = False
            for j in range(7):
                if num[j] == '1' and digit[j] == '0':
                    fail = True
                    break
                elif num[j] == '0' and digit[j] == '1':
                    change += 1
            if not fail:
                changes[i+1][digit1] = change
                for a in range(k+1):
                    if dp[i][a] == True and a+change <= k:
                        dp[i+1][a+change] = True
    if dp[n][k] == False:
        print(-1)
    else:
        ans = []
        for i in range(n,0,-1):
            for j in range(9,-1,-1):
                val = changes[i][j]
                if val is not None and k - val >= 0 and dp[i-1][k-val] == True:
                    ans.append(str(j))
                    k -= val
                    break
        print("".join(ans))
prog()
            
                
