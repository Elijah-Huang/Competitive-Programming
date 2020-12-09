import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        val = 1
        ans = 0
        while val <= n:
            val*= 10
            ans +=1
        print(ans)
prog()
