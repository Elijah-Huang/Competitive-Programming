import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n = int(input())

    if n % 2050:
        print(-1)
    else:
        tot = 0
        n //= 2050
        while n:
            tot += n % 10
            n //= 10

        print(tot)