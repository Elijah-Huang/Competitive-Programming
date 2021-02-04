import sys
input = sys.stdin.readline

def prog():
    for _ in range(int(input())):
        n = int(input())
        s = 'L' + input().strip() + 'R'

        dp_left = [0]*(n+1)
        dp_left[0] = 0
        dp_right = [0]*(n+1)
        dp_right[n] = 0
        
        for i in range(1,n+1):
            if s[i] == 'L':
                if s[i-1] == 'R':
                    dp_left[i] = 2 + dp_left[i-2]
                else:
                    dp_left[i] = 1
            else:
                dp_left[i] = 0

        for i in range(n-1,-1,-1):
            if s[i+1] == 'R':
                if s[i+2] == 'L':
                    dp_right[i] = 2 + dp_right[i+2]
                else:
                    dp_right[i] = 1
            else:
                dp_right[i] = 0

        ans = [dp_left[i] + 1 + dp_right[i] for i in range(n+1)]

        print(*ans)

prog()
            
