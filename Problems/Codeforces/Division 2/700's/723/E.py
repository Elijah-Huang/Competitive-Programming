import sys
input = sys.stdin.buffer.readline

mod = 998244353

n,k = map(int,input().split())

s = list(map(int,input().split()))

pos = [-1]*(n+1)

for i in range(n):
    pos[s[i]] = i

increases = 0

for i in range(n-1):
    increases += pos[s[i]+1] > pos[s[i+1]+1]

# k-1-increases+n choose n
# ways to choose n numbers from 1 to k given that the difference between
# variable(increases) of them = 1 is the same as ordering n bars and
# k-1-increases stars (ways to choose the n+1 spaces between numbers and we
# add back 1 to each difference included in increases
numerator = denominator = 1
for i in range(1,n+1):
   numerator = numerator * (k-1-increases+i) % mod
   denominator = denominator * i % mod

# if k-1 < increases, the answer is 0 and this is automatically account for
# because k-1-increases <= -1 and that k-1-increase >= -(n-1)
# Then, the numerator will be multiplied by 0 at some point during calculation

print(numerator*pow(denominator,mod-2,mod)%mod)