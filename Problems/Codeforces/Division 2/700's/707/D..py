# O(min(n,m)*log(min(n,m)) + log(k)*log(min(n,m)))
import sys
input = sys.stdin.buffer.readline
from math import gcd

n,m,k = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
g = gcd(n,m)
lcm = n*m//g

# combinations of pairs of lights a_i, b_i repeat every lcm(n,m) days
# two positions i in a and j in b can coincide if i % gcd(n,m) == j % gcd(n,m)

# m*mult_of_m[i] % n == i*g -> multiple of m necessary to attain i*g % n
# m*c % n repeats everytime lcm | m*c -> n/g distinct values -> every multiple of g < n is attained
mult_of_m = [0]*(n//g)
c = 0
for i in range(1,n//g):
    c = (c+m)%n
    mult_of_m[c//g] = i

loc_in_a = [-1]*(10**6+1)
for i in range(n):
    loc_in_a[a[i]] = i

matches = []
for i in range(m):
    if loc_in_a[b[i]] != -1:
        diff = (loc_in_a[b[i]] + n - i%n)%n
        if diff % g == 0:
            matches.append(mult_of_m[diff//g]*m + i + 1)

matches.sort()

def count_matches(m):
    if len(matches) == 0:
        return 0

    count = m//lcm*len(matches)
    m %= lcm

    l = 0; r = len(matches)-1

    while l != r:
        m2 = (l+r+1)//2

        if matches[m2] > m:
            r = m2-1
        else:
            l = m2

    if matches[l] <= m:
        count += l+1

    return count

# must be one diff every max(n,m) via contradiction -> max(r) = max(n,m)*k
l = 1; r = 5*10**17
while l != r:
    m = (l+r)//2
    if m - count_matches(m) >= k:
        r = m
    else:
        l = m+1

print(l)