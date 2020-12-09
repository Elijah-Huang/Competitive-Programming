import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        nums = list(map(int,input().split()))
        odds = []
        evens = []
        for i in range(2*n):
            num = nums[i]
            if num % 2 == 0:
                evens.append(i+1)
            else:
                odds.append(i+1)
        if len(odds) % 2 == 1:
            odds.pop()
            evens.pop()
        else:
            if len(odds) >= 2:
                odds.pop()
                odds.pop()
            else:
                evens.pop()
                evens.pop()
        for i in range(len(odds)//2):
            print(odds[2*i],odds[2*i+1])
        for i in range(len(evens)//2):
            print(evens[2*i],evens[2*i+1])
prog()
