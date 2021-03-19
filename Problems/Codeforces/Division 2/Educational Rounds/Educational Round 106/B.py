import sys
input = sys.stdin.readline

for _ in range(int(input())):
    s = input().strip()

    start0 = -1
    start1 = -1
    for i in range(len(s)-1,0,-1):
        if s[i] == s[i-1]:
            if s[i] == '0' and start0 == -1:
                start0 = i
            elif s[i] == '1':
                start1 = i

    if start0 == -1 or start1 == -1 or start0 < start1:
        print("YES")
    else:
        print("NO")

