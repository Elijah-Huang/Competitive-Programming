import sys
input = sys.stdin.buffer.readline

def prog():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        mn = min(a)
        counts = [0]*(n+1)
        for i in a:
            counts[i] += 1
        output = ['0' for i in range(n)]

        if sorted(a) == [i for i in range(1,n+1)]:
            output[0] = '1'

        l = 0
        r = n-1
        for i in range(1,n):
            if mn != i:
                break
            if a[l] == i:
                counts[a[l]]-=1
                l+= 1
                output[n-i] = '1'
                while counts[mn] == 0:
                    mn += 1
                
            elif a[r] == i:
                counts[a[r]]-=1
                r-= 1
                output[n-i] = '1'
                while counts[mn] == 0:
                    mn += 1
                
            else:
                output[n-i] = '1'
                break

        print(''.join(output))
        
prog()
