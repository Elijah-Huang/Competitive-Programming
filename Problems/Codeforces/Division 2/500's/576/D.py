import sys
input = sys.stdin.buffer.readline

n = int(input())
a = list(map(int,input().split()))

answers = [-1]*n
last_all_update = [-1,0]

updates = [[1,i+1,a[i]] for i in range(n)]

q = int(input())
for i in range(1,q+1):
    updates.append(list(map(int,input().split())))

curr_mx = 0
for i in range(len(updates)-1,-1,-1):
    a = updates[i]
    if a[0] == 1:
        if answers[a[1]-1] == -1:
            answers[a[1]-1] = max(curr_mx, a[2])
    else:
        curr_mx = max(curr_mx,a[1])

print(*answers)