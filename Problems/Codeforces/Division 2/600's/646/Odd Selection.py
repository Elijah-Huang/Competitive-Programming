import sys
input = sys.stdin.buffer.readline
def prog():
    for _ in range(int(input())):
        n,x = map(int,input().split())
        array = list(map(int,input().split()))
        odds = 0
        evens = 0
        for e in array:
            if e % 2 == 0:
                evens += 1
            else:
                odds += 1
        if odds % 2 == 0 and odds > 0:
            odds -= 1
        if odds == 0:
            print('No')
        elif x == odds:
            print('YES')
        elif x < odds:
            if x % 2 == 1:
                print('YES')
            else:
                if evens > 0:
                    print('YES')
                else:
                    print('NO')
        else:
            x -= odds
            x -= evens
            if x <= 0:
                print('Yes')
            else:
                print('No')
prog()
