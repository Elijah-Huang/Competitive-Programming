import sys
input = sys.stdin.buffer.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        nums = list(map(int,input().split()))
        ls = 1001
        idxs = 0
        rs = 1001
        idxr = 1001
        mins = [[]for i in range(n)]
        for i in range(n):
            if nums[i] < ls:
                ls = nums[i]
                idxs = i
            mins[i].append([ls,idxs])
        for i in range(n-1,-1,-1):
            if nums[i] < rs:
                rs = nums[i]
                idxr = i
            mins[i].append([rs,idxr])
        found = False
        for i in range(n):
            if mins[i][0][0] < nums[i] > mins[i][1][0]:
                found = True
                break
        if found:
            print('YES')
            print(mins[i][0][1] + 1, i+1, mins[i][1][1] + 1)
        else:
            print('NO')
prog()
