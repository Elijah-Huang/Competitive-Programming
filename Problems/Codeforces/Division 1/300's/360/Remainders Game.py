import sys
input = sys.stdin.buffer.readline
from math import gcd
def prog():
    n,k = map(int,input().split())
    nums = list(map(int,input().split()))
    max_powers = 1
    for num in nums:
        max_powers = gcd(k, num*max_powers//gcd(num,max_powers))
    if max_powers  == k:
        print('YES')
    else:
        print('NO')
prog()
