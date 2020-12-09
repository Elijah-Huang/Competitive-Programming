import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(val + '\n')
def prog():
    for _ in range(int(input())):
        n = int(input())
        nums = list(map(int,input().split()))
        if nums[-1] < nums[0]:
            print('NO')
        else:
            print('YES')
prog()
            
            
