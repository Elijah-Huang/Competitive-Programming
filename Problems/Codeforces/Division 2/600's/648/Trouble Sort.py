import sys
input = sys.stdin.buffer.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        b = list(map(int,input().split()))
        ones = 0
        zeros = 0
        for i in b:
            if i == 0:
                zeros += 1
            else:
                ones += 1
        if ones > 0 and zeros > 0:
            print('Yes')
        else:
            non_decreasing = True
            for i in range(n-1):
                if a[i] > a[i+1]:
                    non_decreasing = False
                    break
            if non_decreasing:
                print('Yes')
            else:
                print('No')
prog()
