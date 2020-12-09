import sys
input = sys.stdin.buffer.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        nums = list(map(int,input().split()))
        sums = []
        lengths = 1
        psums = [[0]*(201)]
        indexes = [[] for i in range(201)]
        for i in range(n):
            a = nums[i]
            indexes[a].append(i)
            psums.append(psums[-1].copy())
            psums[-1][a] += 1
        for a in range(1,201):
            for x in range(1,len(indexes[a])//2 + 1):
                start = indexes[a][x-1] + 1
                end = indexes[a][len(indexes[a]) -x ] -1
                max_mid = 0
                for b in range(1,201):
                    max_mid = max(max_mid, psums[end+1][b] -  psums[start][b])
                lengths = max(max_mid + 2*x , lengths)
        sys.stdout.write(str(lengths) + '\n')
prog()
