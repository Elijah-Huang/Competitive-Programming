import sys
input = sys.stdin.readline

def prog():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        mx = 0
        seen = [0]*n
        
        for i in range(n):
            if not seen[i]:
                j = i
                tot = 0
                while j < n and not seen[j]:
                    seen[j] = 1
                    tot += a[j]
                    j += a[j]
                    

                mx = max(mx,tot)

        print(mx)
prog()
