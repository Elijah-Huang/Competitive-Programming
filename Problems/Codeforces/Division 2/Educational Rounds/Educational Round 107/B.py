import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    a,b,c = map(int,input().split())
    c = 10**(c-1)
    a = 10**(a-1)
    b = 10**(b-1)
    if a > b:
        a += c
    else:
        b += c

    print(a,b)