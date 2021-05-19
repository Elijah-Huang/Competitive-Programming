import sys
input = sys.stdin.buffer.readline

n = int(input())
a = [list(map(int,input().split())) for i in range(n)]

zero_path = None
for i in range(n):
    try:
        j = a[i].index(0)
        zero_path = 'D' * i + 'R' * j + (n - 1 - i) * 'D' + (n - 1 - j) * 'R'
        break
    except ValueError:
        continue

# min pow of 2 or 5 on a path with no 0's
dp2 = [[1e8]*n for i in range(n)]
dp5 = [[1e8]*n for i in range(n)]

dp2[0][0] = dp5[0][0] = 0
if a[0][0]:
    while a[0][0] % 2 == 0:
        a[0][0] >>= 1
        dp2[0][0] += 1
    while a[0][0] % 5 == 0:
        a[0][0] //= 5
        dp5[0][0] += 1
else:
    dp2[0][0] = dp5[0][0] = 1e8

for i in range(n):
    for j in range(n):
        if a[i][j]:
            if i:
                dp2[i][j] = min(dp2[i][j], dp2[i-1][j])
                dp5[i][j] = min(dp5[i][j], dp5[i-1][j])
            if j:
                dp2[i][j] = min(dp2[i][j], dp2[i][j-1])
                dp5[i][j] = min(dp5[i][j], dp5[i][j-1])

            while a[i][j] % 2 == 0:
                a[i][j] >>= 1
                dp2[i][j] += 1
            while a[i][j] % 5 == 0:
                a[i][j] //= 5
                dp5[i][j] += 1

a = None
if dp2[n-1][n-1] < dp5[n-1][n-1]:
    a = dp2
else:
    a = dp5

if zero_path is None or a[n-1][n-1] == 0:
    # retrieve path
    path = []
    i = j = n-1
    while i != 0 or j != 0:
        if i and j:
            if a[i-1][j] < a[i][j-1]:
                i = i-1
                path.append('D')
            else:
                j = j-1
                path.append('R')
        elif i:
            i = i-1
            path.append('D')
        elif j:
            j = j-1
            path.append('R')

    print(a[n-1][n-1])
    print(''.join(path[::-1]))
else:
    print(1)
    print(zero_path)