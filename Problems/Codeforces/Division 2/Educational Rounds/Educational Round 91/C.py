import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        n, x = map(int,input().split())
        a = list(map(int,input().split()))
        a.sort()
        teams = 0
        l = r = n-1
        while (l >= 0):
            if r - l + 1 >= x/a[l]:
                l -= 1
                r = l
                teams += 1
            else:
                l -= 1
        print(teams)
prog()
