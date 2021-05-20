import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    s = input().strip()

    num_zero = 0
    cost_to_make_pal = 0
    has_center = 0

    for i in range((n+1)//2):
        if i == n-1-i:
            if s[i] == '0':
                has_center = 1

        elif s[i] != s[n-1-i]:
            cost_to_make_pal += 1

        elif s[i] == '0':
            num_zero += 2

    if cost_to_make_pal == 0:
        num_zeros = num_zero + has_center
        if num_zeros == 1 or num_zeros % 2 == 0:
            print("BOB")
        else:
            print("ALICE")

    else:
        if num_zero == 0 and cost_to_make_pal == 1 and has_center:
            print("DRAW")
        else:
            print("ALICE")

