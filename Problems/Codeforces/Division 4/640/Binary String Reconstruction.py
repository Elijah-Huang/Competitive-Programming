import sys
def print(val):
    sys.stdout.write(val)
input = sys.stdin.buffer.readline
def prog():
    for _ in range(int(input().strip())):
        a,b,c = map(int,input().split())
        d = 0
        bits = "0"*(a)
        if a != 0:
            bits += '0'
        bits += "1"*(c)
        if c != 0:
            bits += '1'
        if c == 0:
            d = 1
        if a == 0 and c == 0:
            bits = '0'
        if a > 0 and c > 0:
            b -= 1
        for i in range(b):
            if (i+d) % 2 == 0:
                bits += '0'
            else:
                bits += '1'
        print(bits + '\n')
prog()
