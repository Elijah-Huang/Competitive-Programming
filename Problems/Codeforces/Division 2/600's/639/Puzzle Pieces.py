import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
for _ in range(int(input().strip())):
    n,m = map(int,input().split())
    if n == 1 or m == 1:
        print('YES')
    elif n == 2 and m == 2:
        print('YES')
    else:
        print('NO')
    
