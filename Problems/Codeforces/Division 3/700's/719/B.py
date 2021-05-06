import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n = int(input())

    tot = 0
    for digit in range(1,10):
        curr = digit
        while curr <= n:
            tot += 1
            curr = 10*curr + digit

    print(tot)