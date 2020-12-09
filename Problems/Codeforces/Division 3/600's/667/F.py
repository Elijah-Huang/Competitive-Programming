import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    n,k = map(int,input().split())
    s = input().strip()
    t = input().strip()

    num_first = [0]
    num_second = [0]
    for i in range(n):
        num_first.append(num_first[-1] + (s[i] == t[0]))
    for i in range(n):
        num_second.append(num_second[-1] + (s[i] == t[1]))

    if t[0] == t[1]:
        most = min(num_first[n] + k, n)
        print(most*(most-1)//2)
        
    else:
        least = -10**6
        dp = [[[least]*201 for j in range(201)] for i in range(200)]
        dp[0][s[0] == t[0]][0] = 0
        dp[0][s[0] != t[0]][1] = 0
        for loc in range(n - 1):
            for changed in range(loc + 2):
                for num_f in range(loc + 2):
                    if s[loc + 1] != t[0]:
                        dp[loc + 1][changed + 1][num_f + 1] = \
                        max(dp[loc + 1][changed + 1][num_f + 1],\
                        dp[loc][changed][num_f])
                    
                    if s[loc + 1] != t[1]:
                        dp[loc + 1][changed + 1][num_f] = \
                        max(dp[loc + 1][changed + 1][num_f],\
                        dp[loc][changed][num_f] + (num_f))
                        
                    if s[loc + 1] == t[0]:
                        dp[loc + 1][changed][num_f + 1] = \
                        max(dp[loc + 1][changed][num_f + 1],\
                        dp[loc][changed][num_f])
                        
                    if s[loc + 1] == t[1]:
                        dp[loc + 1][changed][num_f] = \
                        max(dp[loc + 1][changed][num_f],\
                        dp[loc][changed][num_f] + (num_f))
                        
                    if s[loc + 1] != t[0] and s[loc + 1] != t[1]:
                        dp[loc + 1][changed][num_f] = \
                        max(dp[loc + 1][changed][num_f],\
                        dp[loc][changed][num_f])

        mx = 0
        for loc in range(n):
            for changed in range(k + 1):
                for num_f in range(n + 1):
                    mx = max(mx, dp[loc][changed][num_f])
                    
        print(mx)
                             
prog()
