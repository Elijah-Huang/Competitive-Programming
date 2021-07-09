import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    a,b = map(int,input().split())

    if a < b:
        a,b = b,a

    d = a - b

    if d == 0:
        print(0,0)
        continue

    print(d,min(b%d, d - (b % d)))