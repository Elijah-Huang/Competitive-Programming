import sys
input = sys.stdin.readline

def prog():
    for _ in range(int(input())):
        s = list(input().strip())
        changes = 0

        place = '#$%'
        for i in range(1,len(s)):
            if s[i] == s[i-1] or (i >= 2 and s[i] == s[i-2]):
                s[i] = place[changes%3]
                changes += 1

        print(changes)
prog()
