import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    s = input().strip()

    num_zeros = 0

    for i in range(n):
        num_zeros += s[i] == '0'

    if num_zeros == 1 or num_zeros % 2 == 0:
        print("BOB")
    else:
        print("ALICE")