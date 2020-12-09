import sys
input = sys.stdin.buffer.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        even_s = 0
        for i in range(0,n,2):
            even_s += a[i]
        left = []
        right = []
        for i in range(n//2):
            left.append(a[i*2+1] - a[i*2])
        for i in range(1,(n-1)//2 + 1):
            right.append(a[i*2-1] - a[i*2])
        mx1 = 0
        curr = 0
        for i in range(len(left)):
            curr = max(curr+left[i],left[i])
            mx1 = max(curr,mx1)
        mx2 = 0
        curr = 0
        for i in range(len(right)):
            curr = max(curr+right[i],right[i])
            mx2 = max(curr,mx2)
        even_s += max(mx2,mx1)
        sys.stdout.write(str(even_s) + '\n')
prog()
            
            
