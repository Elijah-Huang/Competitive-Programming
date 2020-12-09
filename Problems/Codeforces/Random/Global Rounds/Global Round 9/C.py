import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(val + '\n')
def prog():
    for _ in range(int(input())):
        n = int(input())
        nums = list(map(int,input().split())) + [0]
        mx_smalls = 0
        curr_small = nums[0]
        for i in range(n):
            if nums[i] > nums[i+1]:
                mx_smalls = max(mx_smalls, min(curr_small,nums[i]))
                curr_small = nums[i+1]
            else:
                curr_small = min(curr_small,nums[i])
        end = nums[-2]
        if mx_smalls > end:
            print('NO')
        else:
            print('YES')
prog()
