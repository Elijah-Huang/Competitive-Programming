import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    s = input().strip()

    a = set()

    fail = 0
    for i in range(n):
        e = s[i]
        if e in a and s[i-1] != e:
            fail = 1
        a.add(e)

    if fail:
        print("NO")
    else:
        print("YES")