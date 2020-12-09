import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        n = int(input())
        s = input().strip()
        if n % 2 == 1:
            has_odd = 0
            for i in range(0,n,2):
                if int(s[i]) % 2 == 1:
                    has_odd = 1
            print (1 if has_odd else 2)
        else:
            has_even = 0
            for i in range(1,n,2):
                if int(s[i]) % 2 == 0:
                    has_even = 1
            print (2 if has_even else 1)
prog()
