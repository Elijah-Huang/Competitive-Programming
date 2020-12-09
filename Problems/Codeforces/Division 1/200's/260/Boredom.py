import sys
input = sys.stdin.buffer.readline
def prog():
    n = map(int,input().strip())
    integers = map(int,input().split())
    amounts = [0 for i in range(10**5+1)]
    for integer in integers:
        amounts[integer] += integer
    points = 0
    i = 1
    while i < 10**5 +1:
        if amounts[i] != 0:
            dp = [0, amounts[i]]
            i += 1
            while i < 10**5 +1 and amounts[i] != 0:
                dp.append(max(dp[-1],dp[-2] + amounts[i]))
                i += 1
            points += dp[-1]
        else:
            i += 1
    print(points)
prog()
