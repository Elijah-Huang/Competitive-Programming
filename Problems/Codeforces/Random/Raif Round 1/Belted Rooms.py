import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        n = int(input())
        s = input().strip()

        if '>' in s and '<' in s:
            ans = 0
            s = s[-1] + s
            for i in range(n):
                if s[i] == '-' or s[i+1] == '-':
                    ans += 1
            print(ans)
        else:
            print(n)
prog()
