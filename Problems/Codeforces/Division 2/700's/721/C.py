import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))

    ans = 0
    same = {}

    for i in range(n):
        if a[i] in same:
            same[a[i]].append(i+1)
        else:
            same[a[i]] = [i+1]

    for x in same.values():
        ssum = [0]*(len(x)+1)

        for i in range(len(x)-1,-1,-1):
            ssum[i] = ssum[i+1] + x[i]

        for i in range(len(x)-1):
            ans += x[i]*((n+1)*(len(x)-1-i)-ssum[i+1])

    print(ans)