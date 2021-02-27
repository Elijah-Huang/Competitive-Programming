# O(n*log^3(n))
import sys
input = sys.stdin.buffer.readline
from collections import Counter

def gcd(a,b):
    while b:
        a,b = b, a%b
    return a

n = int(input())
a = list(map(int,input().split()))
pos_gcd = Counter()

# precompute sparse table
st = [[0]*20 for i in range (n)]

for i in range(n):
    st[i][0] = a[i]
for j in range(1,20):
    for i in range(n-(1<<j)+1):
        st[i][j] = gcd(st[i][j-1],st[i+(1<<(j-1))][j-1])

log2 = [0]*(n+1)
log2[1] = 0
for i in range(2,n+1):
    log2[i] = log2[i//2] + 1

def rgcd(l,r):
    d = log2[r-l+1]
    return gcd(st[l][d], st[r-(1<<d)+1][d])

# precompute the possible gcds
for i in range(n):
    curr_l = i
    while curr_l < n:
        curr_gcd = rgcd(i, curr_l)
        l = curr_l; r = n-1
        while l!=r:
            m = (l+r+1)//2
            if rgcd(i,m) == curr_gcd:
                l = m
            else:
                r = m-1

        pos_gcd[curr_gcd] += (r-curr_l+1)
        curr_l = r+1

# answer queries
q = int(input())
for i in range(q):
    x = int(input())
    sys.stdout.write(str(pos_gcd[x]) + '\n')