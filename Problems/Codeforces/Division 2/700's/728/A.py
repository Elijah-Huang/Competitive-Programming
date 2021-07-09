import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n = int(input())

    out = [i for i in range(1,n+1)]

    for i in range(n//2):
        out[2*i], out[2*i+1] = out[2*i+1], out[2*i]

    if n % 2:
        out[-2],out[-1] = out[-1],out[-2]

    print(*out)

