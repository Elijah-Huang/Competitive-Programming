import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n,k = map(int,input().split())
    s = input().strip()
    changed = 2

    lst = -1
    for i in range(n-1,-1,-1):
        if s[i] == '*' and lst == -1:
            lst = i

    fst = -1
    for i in range(n):
        if s[i] == '*' and fst == -1:
            fst = i

    changed -= (fst == lst)

    loc = fst
    while lst - loc > k:
        for d in range(k,0,-1):
            if s[loc + d] == '*':
                loc = loc + d
                changed += 1
                break

    print(changed)