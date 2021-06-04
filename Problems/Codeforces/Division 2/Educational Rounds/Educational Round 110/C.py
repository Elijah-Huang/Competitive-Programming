import sys
input = sys.stdin.readline

for _ in range(int(input())):
    s = input().strip()

    tot = 0

    l = 0
    curr_1 = -1
    last = -1
    for r in range(len(s)):
        if s[r] != '?':
            if curr_1 == -1 or (((r-curr_1)&1^1) + (s[r] == '1'))&1:
                l = last + 1

                if s[r] == '1':
                    curr_1 = r
                else:
                    curr_1 = r + 1

            last = r

        tot += (r-l+1)

    print(tot)