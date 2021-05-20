import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n = int(input())

    j = 0
    while n != 1:
        n >>= 1
        j += 1

    print((1<<j) -1)

