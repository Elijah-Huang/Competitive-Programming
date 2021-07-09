import sys

input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n = int(input())

    a = list(map(int,input().split()))


    ans = 0

    a = sorted([[a[i],i+1] for i in range(n)])

    for i in range(n):
        for j in range(i+1,n):
            if a[i][0]*a[j][0] >= 2*n:
                break

            ans += a[i][0]*a[j][0] == a[i][1]+a[j][1]

    print(ans)