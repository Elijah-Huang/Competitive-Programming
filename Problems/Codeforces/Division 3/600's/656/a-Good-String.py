import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def solve(s,l,r,c):
    if l+1 == r:
        return int(s[l] != c)
    replace1 = replace2 = 0
    for i in range(l,(l+r)//2):
        if s[i] != c:
            replace1 += 1
    for i in range((l+r)//2, r):
        if s[i] != c:
            replace2 += 1
    return min(replace2 + solve(s,l,(l+r)//2,chr(ord(c) + 1)),\
        replace1 + solve(s,(l+r)//2,r,chr(ord(c) + 1)))
def prog():
    for _ in range(int(input())):
        n = int(input())
        s = list(input().strip())
        print(solve(s,0,n,'a'))
prog()
