import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        n,k,z = map(int,input().split())
        a = list(map(int,input().split()))
        total = 0
        psum = [0]
        for i in range(n):
            psum.append(psum[i] + a[i])
        for i in range(k+1):
            total += a[i]
        mx = total
        current = total
        leftover = 0
        for i in range(k,1,-1):
            current -= a[i]
            leftover += 1
            to_left = min(z, leftover//2)
            leftover2 = leftover - to_left*2
            added = 0
            if leftover2 % 2 == 1:
                if (to_left < z):
                    added += (a[i-1] + a[i-2])*(to_left) + max(a[i-2],a[i])
                else:
                    added += (a[i-1] + a[i-2])*(to_left) + psum[i + leftover2] - psum[i]
                mx = max(mx, current + added)
            else:
                added += (a[i-1] + a[i-2])*(to_left) + psum[i + leftover2] - psum[i]
                mx = max(mx, current + added)
        print(mx)
prog()
        
