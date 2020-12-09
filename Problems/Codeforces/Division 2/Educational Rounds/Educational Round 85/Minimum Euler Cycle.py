import sys
input = sys.stdin.buffer.readline
def prog():
    for _ in range(int(input())):
        n,l,r = map(int,input().split())
        l -= 1
        r -= 1
        a = 1
        new = 2*(n-a)
        while new < l:
            l -= new
            r -= new
            a += 1
            new = 2*(n-a)
        total = new - l - (2*(n-a))
        if l == 0 and a == 1:
            segment = [1]
            l += 1
            r += 1
        else:
            segment = []
        while total < r and a <= n:
            segment_a = []
            for i in range(1+a,n):
                segment_a.extend([i,a])
            if n > 1+a:
                segment_a.extend([n,1+a])
            segment.extend(segment_a)
            total += 2*(n-a)
            a += 1
        if a == n+1 or n == 2:
            segment.extend([n,1])
        sys.stdout.write(' '.join(map(str,segment[l-1:r])) + '\n')
prog()
        
