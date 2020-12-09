def prog():
    n = int(input())
    nums = list(map(int,input().split()))
    amounts = [0]*20
    for num in nums:
        num = bin(num)[:1:-1]
        for i in range(len(num)):
            amounts[i] += "1" == num[i]
    totals = []
    while True:
        left = False
        for amount in amounts:
            if amount:
                left = True
                break
        if not left:
            break
        curr = 0
        for i in range(20):
            if amounts[i]:
                amounts[i] -= 1
                curr += 1 << i
        totals.append(curr)
    ans = 0
    for total in totals:
        ans += total**2
    print(ans)
prog()
