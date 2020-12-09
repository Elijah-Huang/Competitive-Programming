import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(val + '\n')
def prog():
    t = int(input())
    for _ in range(t):
        n = int(input())
        nums = list(map(int,input().split()))
        for i in range((n+1)//2):
            if nums[2*i] > 0:
                nums[2*i] = -nums[2*i]
        for i in range(1,(n+1)//2):
            if nums[2*i-1] < 0:
                nums[2*i-1] = - nums[2*i-1]
        print(" ".join(map(str,nums)))
prog()
