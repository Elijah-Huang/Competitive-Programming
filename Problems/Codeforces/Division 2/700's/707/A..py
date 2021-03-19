import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    expected = [list(map(int,input().split())) for i in range(n)]
    extra = list(map(int,input().split()))
    time = expected[0][0] + extra[0]

    for i in range(n-1):
        time = max(expected[i][1], time + (expected[i][1]-expected[i][0]+1)//2)
        time += expected[i+1][0] - expected[i][1] + extra[i+1]

    print(time)