import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n = int(input())
    p = [(1,1)] + sorted(list(zip(map(int,input().split()), map(int,input().split()))))
    cost = 0

    for i in range(n):
        back = p[i+1][0] - p[i][0] - (p[i+1][1] - p[i][1])

        if back == 0:
            cost += (1-sum(p[i])%2)*(p[i+1][0] - p[i][0])
        else:
            back -= (1-sum(p[i])%2)
            cost += (back+1)//2

    print(cost)

