import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    s = input().strip()
    count = 0
    for i in s:
        count += (i == '0')
    print(count*(count-1)//2)
prog()
