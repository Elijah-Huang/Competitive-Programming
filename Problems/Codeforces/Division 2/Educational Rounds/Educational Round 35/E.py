import sys
input = sys.stdin.buffer.readline

n,k = map(int,input().split())
p = list(map(int,input().split()))

blocks = [[1,n]]

fail = 0
for i in range(k):
    if blocks[-1][0] <= p[i] <= blocks[-1][1]:
        if p[i] == blocks[-1][0]:
            blocks[-1][0] += 1
        elif p[i] == blocks[-1][1]:
            blocks[-1][1] -= 1
        else:
            blocks.append([blocks[-1][0],p[i] - 1])
            blocks[-2][0] = p[i] + 1

        if blocks[-1][0] > blocks[-1][1]: # block was just 1 thick and = p[i]
            blocks.pop()

    else:
        fail = 1

if fail:
    print(-1)
else:
    for i in p[::-1]:
        blocks.append([i,i])

    while blocks:
        block = blocks.pop()
        print(*range(block[1],block[0]-1,-1), end = ' ')
