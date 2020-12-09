import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        n,k = map(int,input().split())
        x = list(map(int,input().split()))
        y = list(map(int,input().split()))
        x.sort()
        
        most_at_point = [0]*n
        most_after_point = [0]*(n+1)
        tot = 0
        j = -1
        for i in range(n):
            while j + 1 < n and x[j + 1] <= x[i] + k:
                j += 1
                tot += 1
            most_at_point[i] = tot
            tot -= 1

        for i in range(n-1,-1,-1):
            most_after_point[i] = max(most_after_point[i+1], most_at_point[i])
            
        best = 0
        j = 0
        for i in range(n):
            while j < n and x[j] <= x[i] + k:
                j += 1
            if j == n:
                best = max(best, most_at_point[i])
            else:
                best = max(best, most_at_point[i] + most_after_point[j])

        print(best)
prog()
