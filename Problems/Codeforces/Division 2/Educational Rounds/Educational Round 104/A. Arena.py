for _ in range(int(input())):
    n = int(input())
    count = [0]*(101)
    a = list(map(int, input().split()))
    for i in a:
        count[i]+=1

    ans = 0
    for i in range(101):
        if count[i]:
            ans = n - count[i]
            break

    print(ans)

