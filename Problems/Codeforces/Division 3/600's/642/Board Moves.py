import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
for _ in range(int(input().strip())):
    n = int(input().strip())
    if n == 1:
        print(0)
    else:
        m = n//2
        total = 0 
        for i in range(1,m+1):
            total += i*(4*(2*i))
        print(total)
