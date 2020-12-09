import sys
input= sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        counts = [0]*(101)
        for i in range(n):
            counts[a[i]] += 1
        best2 = 0
        best1 = 0
        stopped = False
        for i in range(101):
            if counts[i] == 0:
                break
            else:
                if counts[i] >= 1:
                    best1 += 1
                if counts[i] == 1:
                    stopped = True
                if counts[i] > 1 and not stopped:
                    best2 += 1
        print(best1 + best2)  
prog()
        
