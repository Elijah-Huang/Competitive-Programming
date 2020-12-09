from collections import Counter
import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        s = list(map(int,input().strip()))
        for i in range(n):
            s[i] -= 1
        
        psum = [0]*(n+1)
        a = Counter([0])
        for i in range(n):
            psum[i+1] = s[i] + psum[i]
            a[psum[i+1]] += 1

        ans = 0
        for val in a.values():
            ans += (val*(val-1))//2
        print(ans)
prog()
        
        
        
