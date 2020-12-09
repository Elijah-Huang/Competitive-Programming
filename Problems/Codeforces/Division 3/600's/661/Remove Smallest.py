t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    a.sort()
    fail = False
    for i in range(n-1):
        if a[i+1] - a[i] > 1:
            fail = 1
            print("NO")
            break
    if not fail:
        print("YES")
