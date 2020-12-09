import sys
input = sys.stdin.buffer.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        nums = list(map(int,input().split()))
        sums = []
        lengths = 1
        psums = [[0]*(n+1) for i in range(201)]
        indexes = [[] for i in range(201)]
        for i in range(n):
            indexes[nums[i]].append(i)
            for j in range(1,201):
                psums[j][i+1] = psums[j][i] + (j == nums[i])
        for a in range(1,201):
            for x in range(1,len(indexes[a])//2 + 1):
                start = indexes[a][x-1] + 1
                end = indexes[a][len(indexes[a]) -x ] -1
                max_mid = 0
                for b in range(1,201):
                    max_mid = max(max_mid, psums[b][end+1] -  psums[b][start])
                lengths = max(max_mid + 2*x , lengths)
        sys.stdout.write(str(lengths) + '\n')
prog()
