import sys
input = sys.stdin.readline

for _ in range(int(input())):
    a = input().strip()
    b = input().strip()
    mx_common_sub = 0

    b_sub = set()
    for i in range(len(b)):
        for j in range(i, len(b)):
            b_sub.add(b[i:j+1])

    for i in range(len(a)):
        for j in range(i,len(a)):
            if a[i:j+1] in b_sub:
                mx_common_sub = max(mx_common_sub,j-i+1)

    print(len(a)+len(b)-2*mx_common_sub)


