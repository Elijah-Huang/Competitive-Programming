import sys
input = sys.stdin.buffer.readline

mod = 998244353
ans = 1

n = int(input())
adj = [0]*(n+1)
for i in range(n-1):
    a,b = map(int,input().split())
    adj[a] += 1
    adj[b] += 1

fact = [1]*(n)
for i in range(2,n):
    fact[i] = (fact[i-1]*i) % mod

for i in adj[1:]:
    ans = (ans * fact[i]) % mod

print((n*ans) % mod)