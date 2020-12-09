import sys
input = sys.stdin.readline
def prog():
    mod = 998244353
    n = int(input())
    dp = [0]*(n+1)
    dp[0] = 1
    prev_states = [0,1]
    
    for i in range(1,n+1):
        dp[i] = prev_states[i%2]
        prev_states[(i-1)%2] = (prev_states[(i-1)%2] + dp[i])%mod
        
    print((dp[n]*(pow(pow(2,n,mod),mod-2,mod)))%mod)

prog()
