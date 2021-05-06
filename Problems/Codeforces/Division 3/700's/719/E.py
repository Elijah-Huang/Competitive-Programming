import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    s = input().strip()

    suff = [0]*(n+1)
    for i in range(n-1,-1,-1):
        suff[i] = (s[i] == '*') + suff[i+1]

    pref = [0] * (n + 1)
    for i in range(n):
        pref[i] = (s[i] == '*') + pref[i - 1]

    mn = 0
    for i in range(n):
        if s[i] == '.':
            mn += min(pref[i-1], suff[i+1])

    print(mn)
