import sys
input = sys.stdin.buffer.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        grannies = list(map(int,input().split()))
        grannies.sort()
        ans = 0
        for i in range(n):
            if grannies[i] <= i+1:
                ans = i+1
        print(ans+1)          
prog()
