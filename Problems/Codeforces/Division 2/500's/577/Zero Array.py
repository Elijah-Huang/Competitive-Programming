import sys
input = sys.stdin.buffer.readline
def prog():
    n = int(input())
    nums = list(map(int,input().split()))
    total = 0
    for num in nums:
        total += num
    if 0 == total % 2:
        fail = False
        for num in nums:
            if 2*num > total:
                fail = True
                break
        if fail:
            print('NO')
        else:
            print('YES')
                
    else:
        print('NO')
prog()
